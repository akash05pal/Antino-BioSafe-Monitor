import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense
from sklearn.preprocessing import MinMaxScaler

# Load sensor data from CSV
df = pd.read_csv("gas_readings.csv")
gases = ['H2S', 'CH4', 'NH3', 'CO', 'SO2']

# Scale the data
scaler = MinMaxScaler()
data_scaled = scaler.fit_transform(df[gases])

# Prepare time-series sequences (past 10 readings → predict next reading)
X, y = [], []
time_steps = 10

for i in range(time_steps, len(data_scaled)):
    X.append(data_scaled[i-time_steps:i, :])  # Past 10 readings for all gases
    y.append(data_scaled[i, :])  # Next reading for all gases

X, y = np.array(X), np.array(y)

# Build the LSTM model
model = Sequential([
    LSTM(50, activation='relu', return_sequences=True, input_shape=(time_steps, len(gases))),
    LSTM(50, activation='relu'),
    Dense(len(gases))  # Predicts all gases
])
model.compile(optimizer='adam', loss='mse')

# Train the model
model.fit(X, y, epochs=10, batch_size=16)

# Predict the next gas levels
future_pred = model.predict(X[-1].reshape(1, time_steps, len(gases)))
predicted_values = scaler.inverse_transform(future_pred)

# Display predicted values for each gas
for i, gas in enumerate(gases):
    print(f"Predicted {gas}: {predicted_values[0][i]:.2f} ppm")
