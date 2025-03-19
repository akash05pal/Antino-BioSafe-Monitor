Follow these steps to set up the Blynk dashboard on your smartphone:

Step 1: Download the Blynk App
Install Blynk IoT from the Google Play Store or Apple App Store.
Sign up using your email and log in.
Step 2: Create a New Project
Open the Blynk app and create a new project.
Set the project name as "BioSafe Monitor".
Choose the device as ESP32 and connection type as WiFi.
Click Create.
Copy the BLYNK_AUTH_TOKEN sent to your email (you will need this in the ESP32 code).
Step 3: Add Widgets to Dashboard
Labelled Value Widgets (to display sensor data)

Add 5 Labelled Value Widgets from the widget box.
Configure them as follows:
Smoke Sensor → Virtual Pin V0, Label: Smoke Level
MQ-2 Sensor → Virtual Pin V1, Label: MQ-2 Gas
MQ-135 Sensor → Virtual Pin V2, Label: MQ-135 Gas
Temperature → Virtual Pin V3, Label: Temperature (°C)
Humidity → Virtual Pin V4, Label: Humidity (%)
Set Reading Frequency to 1 second.
LED Widget (to indicate Alerts)

Add an LED Widget.
Assign it to Virtual Pin V5.
This will turn RED when a dangerous gas level is detected.
Notification Widget

Add the Notification Widget.
This will send real-time alerts when gas levels exceed safe limits.
Events Setup (For Alerts)

Go to the Events Tab in Blynk.
Create events for:
Gas Alert (Trigger: V0, V1, V2 exceeding safe limits)
Temperature Alert (Trigger: V3 > 50°C)
Humidity Alert (Trigger: V4 > 80%)
3. Connecting ESP32 to Blynk
Install Blynk Library in the Arduino IDE.
Update WiFi credentials (ssid and pass) in the provided code.
Upload the code to ESP32 using Arduino IDE.
Open the Serial Monitor to check if the device is connected.
4. Testing the System
Once ESP32 is connected, check real-time data in the Blynk App.
Introduce smoke near the MQ-2 sensor to test alerts.
Observe temperature and humidity changes using a heat source.
If the LED widget turns RED, check notifications for alerts.
5. Troubleshooting
If WiFi is not connecting, recheck SSID and Password.
If sensor values are not updating, ensure proper wiring and connections.
Restart ESP32 if data is not showing in the Blynk app.