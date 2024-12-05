import requests
import pandas as pd

# Hugging Face API Configuration
HUGGINGFACE_API_URL = "https://api-inference.huggingface.co/models/YOUR_MODEL_NAME"
HEADERS = {"Authorization": f"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"}

# Load temperature data
data = pd.read_csv('temperature_data.csv')
temperatures = data['Temperature'].tolist()

# Prepare payload for prediction
def predict_health_condition(temperature):
    payload = {
        "inputs": {
            "temperature": temperature,
            # Add more fields if available (e.g., pulse, humidity)
        }
    }
    response = requests.post(HUGGINGFACE_API_URL, headers=HEADERS, json=payload)
    return response.json()

# Process predictions
for temp in temperatures:
    result = predict_health_condition(temp)
    print(f"Temperature: {temp} -> Health Condition: {result}")
