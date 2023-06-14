# Reference: https://youtu.be/VVDHU_TWwUg?list=PLqnslRFeH2UrcDBWF5mfPGpqQDSta6VK4
import torch
import torch.nn as nn

# f = w*x

# f = 2*x
X = torch.tensor([[1], [2], [3], [4]], dtype=torch.float32)
Y = torch.tensor([[2], [4], [6], [8]], dtype=torch.float32)
X_test = torch.tensor([5], dtype = torch.float32)

in_samples, in_feats = X.shape
out_samples, out_feats = Y.shape

print(in_samples, in_feats)

# model = nn.Linear(in_feats, out_feats)

# Custom Model Definition
class LinearRegression(nn.Module):
  def __init__(self, input_size, output_size):
    super(LinearRegression, self).__init__()

    self.lin = nn.Linear(input_size, output_size)

    def forward(self, x):
      return self.lin(x)
    
model = LinearRegression(in_feats, out_feats)

# loss
mse_loss = nn.MSELoss()

print(f'Prediction before training: f(5) = {model(X_test).item():.3f}')

# Hyperparameters
lr = 0.01
n_epochs = 50

optimizer = torch.optim.SGD(lr=lr, params=model.parameters())


for epoch in range(n_epochs):
  y_pred = model(X)

  l = mse_loss(y_pred, Y)

  #gradients 
  l.backward() # dl/dw

  #update weights
  optimizer.step()

  # zero gradients
  optimizer.zero_grad()

  [w, b] = model.parameters()
  print(f'epoch {epoch + 1}: w = {w[0][0]:.3f}, loss = {l.item():.8f}')

print(f'Prediction after training: f(5) = {model(X_test).item():.3f}')