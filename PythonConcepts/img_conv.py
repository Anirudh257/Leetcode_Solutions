import base64
import io
from PIL import Image
from matplotlib import pyplot  as plt

def base64str_to_PILImage(base64str):
    base64str_img_bytes = base64str.encode('utf-8')
    base64bytes = base64.b64decode(base64str_img_bytes)
    bytesObj = io.BytesIO(base64bytes)
    img = Image.open(bytesObj)
    return img

with open("dog_with_ball.png", "rb") as img_file:
    base64str = base64.b64encode(img_file.read()).decode("utf-8")

print("Here")
# plt.imshow(base64str_to_PILImage(base64str))