# Explaining GET functionality in FastAPI
from fastapi import FastAPI

app = FastAPI()  # the function

@app.get("/predict")  # get called to decorate this.
def predict_complex_model(age: int, sex: str):  # simple function
    # Assume a big and complex model here. For this test I am using a simple rule based model
    if age < 10 or sex == 'F':
        return {'survived': 1}
    else:
        return {'survived': 0}

# When enter pressed -> Call http://127.0.0.1:8000/predict endpoint -> Call predict_complex_model

#  Web developer can get the output using the requests function in python

