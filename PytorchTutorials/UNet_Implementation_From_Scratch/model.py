import torch
import torch.nn as nn
import torchvision.transforms.functional as TF

class DoubleConv(nn.Module):
    def __init__(self, in_channels, out_channels):
        super(DoubleConv, self).__init__()
        self.conv_stack = nn.Sequential(
            nn.Conv2d(in_channels, out_channels, 3, 1, 1, bias=False),
            nn.BatchNorm2d(out_channels),
            nn.Conv2d(out_channels, out_channels, 3, 1, 1, bias=False),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True)
        )

    def forward(self, x):
        return self.conv_stack(x)
    
class UNet(nn.Module):
    def __init__(self, in_channels=3, out_channels=1, features=[64, 128, 256, 512]):
        super(UNet, self).__init__()
        self.up_sampling = nn.ModuleList()
        self.down_sampling = nn.ModuleList()
        self.pool = nn.MaxPool2d(kernel_size = 2, stride = 2)

        # Down part of UNet
        for feature in features:
             self.down_sampling.append(DoubleConv(in_channels, feature))
             in_channels = feature
            
        # Up part of UNet
        for feature in reversed(features):
            self.up_sampling.append(nn.ConvTranspose2d(feature*2, feature, kernel_size=2, stride=2))
            self.up_sampling.append(DoubleConv(feature*2, feature))

        self.bottleneck = DoubleConv(features[-1], features[-1]*2) 

        self.final_conv = nn.Conv2d(features[0], out_channels, kernel_size=1)


    def forward(self, x):
        skip_connections = []
        
        for down in self.down_sampling:
            x = down(x)
            skip_connections.append(x)
            x = self.pool(x)   

        x = self.bottleneck(x)  
        skip_connections = skip_connections[::-1]

        for idx in range(0, len(self.up_sampling), 2):
            x = self.up_sampling[idx](x)
            skip_connection = skip_connections[idx//2]
            concat_skip = torch.cat((skip_connection, x), dim=1)
            x = self.up_sampling[idx + 1](concat_skip)

        return self.final_conv(x)



unet = DoubleConv(512, 512)

input_shape = (1, 512, 512)

X_test= torch.randn(input_shape)

y_pred = unet(X_test)

print(y_pred.shape)