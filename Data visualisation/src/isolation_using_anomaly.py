import pandas as pd
from sklearn.ensemble import IsolationForest
import matplotlib.pyplot as plt

# Load sensor data from CSV
df = pd.read_csv("gas_readings.csv")

# Define gas columns
gases = ['H2S', 'CH4', 'NH3', 'CO', 'SO2']

# Define threshold values for each gas
thresholds = {'H2S': 10, 'CH4': 4, 'NH3': 3, 'CO': 8, 'SO2': 1}

# Train Isolation Forest model
model = IsolationForest(contamination=0.02)
df['Anomaly'] = model.fit_predict(df[gases])

# Plot each gas with its anomaly classification
fig, axes = plt.subplots(len(gases), 1, figsize=(10, 10), sharex=True)

for i, gas in enumerate(gases):
    ax = axes[i]
    ax.scatter(df.index, df[gas], c=df['Anomaly'], cmap='coolwarm', edgecolors='k')
    ax.axhline(y=thresholds[gas], color='r', linestyle='--', label="Threshold")
    ax.set_ylabel(f"{gas} (ppm)")
    ax.legend()

plt.xlabel("Reading Index")
plt.suptitle("Anomaly Detection for All Gases")
plt.show()
