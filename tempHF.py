import requests

def predict_health_risk(temp, bpm):
    url = "https://api-inference.huggingface.co/models/YOUR_MODEL_NAME"
    headers = {"Authorization": f"Bearer YOUR_API_KEY"}
    data = {"inputs": {"temperature": temp, "pulse": bpm}}
    response = requests.post(url, headers=headers, json=data)
    return response.json()

temp = 36.5
bpm = 72
prediction = predict_health_risk(temp, bpm)
print(f"Risk Level: {prediction}")
