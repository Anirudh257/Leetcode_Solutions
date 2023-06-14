# Reference: https://youtu.be/ACmuBbuXn20?list=PLhhyoLH6IjfxeoooqP9rhU3HJIAVAJ3Vz

# Import libraries
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from torch.utils.data import DataLoader
import torchvision.datasets as datasets
import torchvision.transforms as transforms

# VGG general structure
VGG16 = [64, 64, 'M', 128, 128, 'M', 256, 256, 256, 'M', 512, 512, 512, 'M', 512, 512, 512, 'M'] 
# -> Flatten
# and 3 Linear layers (4096, 4096, 1000)

VGG_types = {
    "VGG11": [64, "M", 128, "M", 256, 256, "M", 512, 512, "M", 512, 512, "M"],
    "VGG13": [64, 64, "M", 128, 128, "M", 256, 256, "M", 512, 512, "M", 512, 512, "M"],
    }


class VGG(nn.Module):
    def __init__(self, in_channels, num_classes):
        super(VGG, self).__init__()
        self.in_channels = in_channels

        # Improve readability and scalability by using a separate function to write the layers of the network
        self.conv_layers = self.create_conv_layers(VGG16)

        self.fcs = nn.Sequential(
                nn.Linear(512*7*7, 4096),
                nn.ReLU(),
                nn.Dropout(p=0.5),
                nn.Linear(4096, 4096),
                nn.ReLU(),
                nn.Dropout(p=0.5),
                nn.Linear(4096, num_classes)
        )
    
    def forward(self, x):
        x = self.conv_layers(x)
        x = x.reshape(x.shape[0], -1)
        x = self.fcs(x)

        return x

    def create_conv_layers(self, vgg_architecture):
        layers = []
        in_channels = self.in_channels

        for x in vgg_architecture:
            if type(x) == int:
                out_channels = x

                layers += [
                    nn.Conv2d(in_channels=in_channels, out_channels=out_channels, 
                              kernel_size=(3, 3), stride=(1, 1), padding=(1, 1)),
                    nn.BatchNorm2d(x),
                    nn.ReLU()
                ]

                in_channels = x
            else:
                layers += [nn.MaxPool2d(kernel_size=(2, 2), stride=(2, 2))]

        return nn.Sequential(*layers)
    
if __name__ == "__main__":
    device = "cuda" if torch.cuda.is_available() else "cpu"
    model = VGG(in_channels=3, num_classes=1000).to(device)
    BATCH_SIZE = 3
    x = torch.randn(BATCH_SIZE, 3, 224, 224).to(device)
    assert model(x).shape == torch.Size([BATCH_SIZE, 1000])
    print(model(x).shape)