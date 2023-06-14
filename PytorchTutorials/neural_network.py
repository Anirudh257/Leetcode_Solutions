# Reference: https://www.youtube.com/watch?v=Jy4wM2X21u0

# Import Libraries

import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from torch.utils.data import DataLoader
import torchvision.datasets as datasets
import torchvision.transforms as transforms

# Model Definition
class NN(nn.Module):

    # Constructor
    def __init__(self, input_size, num_classes):
        super(NN, self).__init__() # Call the parent class nn.Module and initialize those attributes
        self.fc1 = nn.Linear(input_size, 50)
        self.fc2 = nn.Linear(50, num_classes)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = self.fc2(x)

        return x

# Sanity check
# model = NN(784, 10)
# randX = torch.randn(64, 784)
# print(model(randX).shape) # 64 x 10

# Set device
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

# Hyperparameters
input_size = 784
num_classes = 10
learning_rate = 0.001
batch_size = 64
num_epochs = 1

# Load Data
train_dataset = datasets.MNIST(root = 'dataset/', train = True, transform = transforms.ToTensor(),
                               download = True)
train_loader = DataLoader(dataset = train_dataset, batch_size = batch_size, shuffle = True)
test_dataset = datasets.MNIST(root='dataset/', train = False, transform = transforms.ToTensor(),
                              download = True)
test_loader = DataLoader(dataset = test_dataset, batch_size = batch_size, shuffle = False)

# Initialize the network
model = NN(input_size=input_size, num_classes=num_classes).to(device)

# Loss and Optimize
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr = learning_rate)

# Train network
for epoch in range(num_epochs):
    for batch_idx, (data, targets) in enumerate(train_loader):
        data = data.to(device) # 64 x 1 x 28 x 28
        targets =  targets.to(device) # 64

        # Reshape data
        data = data.reshape(data.shape[0], -1) # 64 x 784

        # Forward
        scores = model(data)
        loss = criterion(scores, targets)

        # Backward
        optimizer.zero_grad() # Remove backprops from previous epochs
        loss.backward()

        # Gradient step
        optimizer.step()

# accuracy computing function
def check_accuracy(loader, model):
    num_correct = 0
    num_samples = 0
    model.eval()

    with torch.no_grad():
        for x, y in loader:
            x = x.to(device)
            y = y.to(device)

            x = x.reshape(x.shape[0], -1)
            scores = model(x)
            _, predictions = scores.max(1) # Find the index of the maximum value
            num_correct += (predictions == y).sum()
            num_samples += predictions.size(0)

        print(f'Got {num_correct}/{num_samples} with accuracy {float(num_correct)/float(num_samples)*100:.2f}')

    model.train()
    # return acc

check_accuracy(train_loader, model)
check_accuracy(test_loader, model)





