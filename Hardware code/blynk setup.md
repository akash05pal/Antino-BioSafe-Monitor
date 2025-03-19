# BioSafe Monitor - Blynk Dashboard Setup

## Step 1: Download the Blynk App
1. Install **Blynk IoT** from the Google Play Store or Apple App Store.
2. Sign up using your email and log in.

## Step 2: Create a New Project
1. Open the Blynk app and create a new project.
2. Set the project name as **"BioSafe Monitor"**.
3. Choose the device as **ESP32** and connection type as **WiFi**.
4. Click **Create**.
5. Copy the **BLYNK_AUTH_TOKEN** sent to your email (you will need this in the ESP32 code).

## Step 3: Add Widgets to Dashboard

### **Labelled Value Widgets (to display sensor data)**
- Add **5 Labelled Value Widgets** from the widget box.
- Configure them as follows:
  
| Sensor | Virtual Pin | Label |
|--------|------------|--------|
| Smoke Sensor | V0 | Smoke Level |
| MQ-2 Sensor | V1 | MQ-2 Gas |
| MQ-135 Sensor | V2 | MQ-135 Gas |
| Temperature | V3 | Temperature (°C) |
| Humidity | V4 | Humidity (%) |

- Set **Reading Frequency** to **1 second**.

### **LED Widget (to indicate Alerts)**
- Add an **LED Widget**.
- Assign it to **Virtual Pin V5**.
- This will turn **RED** when a dangerous gas level is detected.

### **Notification Widget**
- Add the **Notification Widget**.
- This will send **real-time alerts** when gas levels exceed safe limits.

### **Events Setup (For Alerts)**
1. Go to the **Events Tab** in Blynk.
2. Create events for:
   - **Gas Alert** (Trigger: V0, V1, V2 exceeding safe limits)
   - **Temperature Alert** (Trigger: V3 > 50°C)
   - **Humidity Alert** (Trigger: V4 > 80%)

## Step 4: Connecting ESP32 to Blynk
1. Install **Blynk Library** in the Arduino IDE.
2. Update **WiFi credentials** (`ssid` and `pass`) in the provided code.
3. Upload the code to **ESP32** using Arduino IDE.
4. Open the **Serial Monitor** to check if the device is connected.

## Step 5: Testing the System
1. Once ESP32 is connected, check **real-time data** in the Blynk App.
2. Introduce **smoke** near the MQ-2 sensor to test alerts.
3. Observe **temperature and humidity changes** using a heat source.
4. If the **LED widget turns RED**, check **notifications for alerts**.

## Step 6: Troubleshooting
- If **WiFi is not connecting**, recheck **SSID and Password**.
- If **sensor values are not updating**, ensure **proper wiring and connections**.
- Restart **ESP32** if data is not showing in the Blynk app.
