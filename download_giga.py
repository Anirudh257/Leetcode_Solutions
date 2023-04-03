'''
Downloads:
https://drive.google.com/open?id=1USoQ8lJgN8kAWnUnRrupMGrPMLlDVqlV

with gdown
'''
import gdown
import os
from zipfile import ZipFile

data_dir = "datasets/gigaword"
if not os.path.exists(data_dir):
	os.makedirs(data_dir)

# Download
print("Downloading Gigaword dataset to ", data_dir)
url = 'https://drive.google.com/uc?id=1USoQ8lJgN8kAWnUnRrupMGrPMLlDVqlV'
file="ggw_data.zip"
output = os.path.join(data_dir,file)
gdown.download(url, output, quiet=False)

# Extract
with ZipFile(output, 'r') as zipObj:
   zipObj.extractall(data_dir)
