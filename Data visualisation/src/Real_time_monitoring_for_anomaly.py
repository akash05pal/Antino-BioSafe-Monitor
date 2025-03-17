import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import platform
import pandas as pd

# Load sensor data from CSV
df = pd.read_csv("gas_readings.csv")
gases = ['H2S', 'CH4', 'NH3', 'CO', 'SO2']

# Define thresholds for each gas
thresholds = {'H2S': 10, 'CH4': 4, 'NH3': 3, 'CO': 8, 'SO2': 1}
num_readings = 200  # Number of past readings to display

# Initialize storage with initial data
data = {gas: list(df[gas].iloc[:num_readings]) for gas in gases}

# Create subplots
fig, axes = plt.subplots(3, 2, figsize=(10, 6))
axes = axes.flatten()
fig.delaxes(axes[-1])  # Remove extra subplot

plots = {}
for i, gas in enumerate(gases):
    ax = axes[i]
    ax.set_title(f"{gas} Levels")
    ax.set_xlim(0, num_readings)
    ax.set_ylim(0, thresholds[gas]*2)
    ax.set_xlabel("Reading Index")
    ax.set_ylabel("Concentration (ppm)")
    plots[gas] = ax.scatter(range(num_readings), data[gas], c=['blue']*num_readings, cmap='coolwarm', edgecolors='k')
    ax.axhline(thresholds[gas], color='r', linestyle='--', label="Threshold")
    ax.legend()

alert_text = fig.text(0.5, 0.96, "", ha='center', color='red', fontsize=12)

current_index = num_readings  # Start at row after the initial window

# Define beep sound function
if platform.system() == 'Windows':
    import winsound
    def beep_sound():
        winsound.Beep(1000, 500)  # 1000 Hz for 500 ms
else:
    import tkinter as tk
    def beep_sound():
        root = tk.Tk()
        root.withdraw()
        root.bell()
        root.destroy()

def update(frame):
    global current_index
    beep_triggered = False
    high_gases = []

    # Loop back to start if we reach the end
    if current_index >= len(df):
        current_index = 0
    
    # Get the current row
    row = df.iloc[current_index]
    current_index += 1
    
    for i, gas in enumerate(gases):
        new_value = row[gas]
        data[gas].append(new_value)
        if len(data[gas]) > num_readings:
            data[gas].pop(0)
        
        # Check if gas level exceeds threshold
        if new_value > thresholds[gas]:
            high_gases.append(f"{gas}: {new_value:.2f} ppm")
            beep_triggered = True
        
        # Update scatter plot points and colors
        colors = ['red' if val > thresholds[gas] else 'blue' for val in data[gas]]
        plots[gas].set_offsets(np.column_stack((range(len(data[gas])), data[gas])))
        plots[gas].set_color(colors)
    
    # Update alert text
    if high_gases:
        alert_text.set_text("High concentration detected: " + ", ".join(high_gases))
    else:
        alert_text.set_text("")
    
    # Trigger alarm if needed
    if beep_triggered:
        beep_sound()

ani = animation.FuncAnimation(fig, update, interval=2000)  # 2 seconds per update

plt.tight_layout()
plt.show()
