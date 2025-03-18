# Antino-BioSafe-Monitor

# BioSafe Monitor: AIoT-based Device for Real-Time Toxic Gas Detection in Sewers & Septic Tanks
## DEMO VIDEO LINK : https://www.youtube.com/watch?v=hBV3V14wlOM


## Problem Statement
Despite strict regulations prohibiting hazardous manual cleaning of sewers and septic tanks without safety equipment, these dangerous practices persist. Sanitation workers face life-threatening risks due to toxic gas exposure, including hydrogen sulfide (H₂S), methane (CH₄), carbon monoxide (CO), ammonia (NH₃), and sulfur dioxide (SO₂). In India alone, over 900 deaths related to manual scavenging have been recorded in the last decade, with more than 100 fatalities in 2023 alone. Prolonged exposure to these gases can cause severe respiratory issues, neurological damage, and sudden fatalities.

Existing gas monitoring devices are expensive, lack real-time alerts, and fail to provide actionable insights. PPE kits and safety devices help but do not eliminate exposure risks, particularly when workers unknowingly enter hazardous environments. There is an urgent need for a real-time gas detection system that integrates predictive hazard assessment and emergency response mechanisms.
## Solution Overview
BioSafe Monitor is an AIoT-powered device designed to protect sanitation workers by continuously detecting toxic gases, issuing real-time alerts, and preventing exposure to hazardous environments. The system integrates sensor-based monitoring, AI-driven predictive analysis, remote monitoring, and automated safety protocols to mitigate risks effectively.

### Key Technologies Used:
- **Hardware**: Arduino/Raspberry Pi, gas sensors (MQ-135, MQ-2, MQ-7), NodeMCU for Wi-Fi.
- **Software**: Python (for AI models), TensorFlow (for gas prediction), Node.js (backend), React Native (mobile app).
- **Cloud & Database**: Firebase, Google Cloud IoT, AWS IoT for real-time data storage and analytics.
- **Communication**: MQTT for sensor communication, Twilio for SMS/voice alerts.
- **Data Analytics**: Apache Kafka (real-time streaming), Pandas & Matplotlib (data visualization), Power BI/Tableau (report generation).

## Setup & Installation
## **1. Hardware Setup**  
### **A. Components Required**  
- Gas Sensors (**H₂S, CH₄, CO, NH₃, SO₂**)  
- Microcontroller (**ESP32 / Raspberry Pi**)  
- Buzzer for alerts  
- OLED Display for real-time data  
- Wi-Fi Module (if not integrated with the microcontroller)  
- Rechargeable Battery & Power Management Circuit  

### **B. Assembly Instructions**  
1. Connect the gas sensors to the microcontroller using the appropriate GPIO pins.  
2. Attach the OLED display to show real-time gas concentration levels.  
3. Connect the buzzer for audible alerts.  
4. Ensure the power supply is properly connected and stable.  

### **C. Connectivity**  
- Configure Wi-Fi settings in the microcontroller firmware to enable remote monitoring.  
- Ensure all hardware components are securely connected.  

---

## **2. Software Setup & Usage Guide**  
### **A. Arduino IDE Setup**  
1. **Download & Install Arduino IDE** from [Arduino Official Website](https://www.arduino.cc/en/software).  

2. **Install ESP32 Board Support** (if using ESP32):  
   - Go to **File → Preferences**  
   - Add this URL in **Additional Board Manager URLs**:  
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Go to **Tools → Board → Board Manager**, search for `"ESP32"`, and install it.  

3. **Install Required Libraries**:  
   - Open **Arduino IDE**  
   - Go to **Sketch → Include Library → Manage Libraries**  
   - Install the following:  
     - **Firebase ESP8266/ESP32 Client**  
     - **Adafruit SSD1306** (for OLED display)  
     - **Adafruit GFX**  
     - **MQ Unified Sensor** (for gas sensors)  

4. **Flash Firmware to Microcontroller**:  
   - Open the project code  
   - Connect the **ESP32/Raspberry Pi via USB**  
   - Select the correct **board & COM port**  
   - Click **Upload**  

---

### **B. Cloud Backend Setup (Firebase)**  
1. Go to **Firebase Console**.  
2. **Create a new project** → Enable **Realtime Database**.  
3. Copy **Database URL & API Key**.  
4. Set **Firebase rules** for testing:  
   ```json
   {
     "rules": {
       ".read": true,
       ".write": true
     }
   }

### **C. Mobile Application Setup**  
1. **Install Android Studio**.  
2. **Clone the mobile app repository**:  
   ```bash
   git clone https://github.com/your-repo-name/BioSafe-Monitor-App.git
   cd BioSafe-Monitor-App

Place google-services.json (from Firebase) inside the app/ folder.

Build & install the app:
./gradlew installDebug

### Steps to Set Up:
1. **Hardware Assembly**: Connect gas sensors to the microcontroller and set up power sources.
2. **Software Installation**:
   - Install necessary libraries and dependencies.
   - Set up the backend server and connect it to cloud storage.
   - Deploy AI models for predictive analysis.
3. **Integration & Testing**:
   - Connect the device to the mobile application.
   - Verify real-time gas detection and alert mechanisms.
   - Test cloud integration and dashboard analytics.

## Usage Instructions
1. **Pre-Entry Gas Detection & Alerts**:
   - Place the device at the sewer or septic tank opening.
   - The system detects gas levels and alerts the worker if toxic levels are detected.
   - Supervisors receive simultaneous notifications.

2. **Continuous Monitoring During Operation**:
   - Workers wear the device, which continuously monitors gas levels.
   - Alerts are sent if toxic concentrations rise beyond safety limits.
   - Worker’s location is tracked for emergency response.

3. **Cloud Integration & Real-Time Data Visualization**:
   - Live data is sent to the cloud for monitoring by supervisors and municipal authorities.
   - Mobile app provides workers and supervisors with instant updates.

4. **AI-Based Predictive Analysis & Data Insights**:
   - AI algorithms analyze historical data to predict gas leaks and high-risk zones.
   - Authorities can use insights for preventive measures and safety protocol optimization.

5. **Emergency Alerts & Geolocation-Based Notifications**:
   - SMS alerts with real-time location data are sent to supervisors, authorities, and family members in case of danger.
   - Emergency guidance for evacuation is provided via the mobile app.

6. **Automatic Ventilation & Mitigation Measures (Optional)**:
   - The system can activate exhaust fans to dissipate harmful gases.
   - Workers receive evacuation route guidance.

## Unique Features
- **Pre-Entry Safety Alerts**: Ensures no worker enters a hazardous environment unknowingly.
- **AI-Driven Predictions**: Identifies high-risk areas before an accident occurs.
- **Voice Alerts**: Supports multilingual voice alerts for illiterate workers.
- **Battery-Powered & Portable**: Functions in remote locations without a stable power supply.
- **Government & Municipal Integration**: Scalable solution for widespread adoption.

## Data Analytics & Insights
- **Real-time Gas Concentration Trends**: Live dashboard displays gas levels across multiple locations.
- **Predictive Analysis**: AI models forecast potential gas buildups.
- **High-Risk Zones Mapping**: Identifies frequently hazardous areas.
- **Worker Exposure Reports**: Tracks exposure history for health risk assessment.
- **Safety Compliance Monitoring**: Helps municipalities ensure adherence to safety regulations.

## Challenges & Solutions
- **Sensor Accuracy & Maintenance**: Regular calibration with reference gases ensures reliability.
- **Internet Connectivity Issues**: LoRaWAN integration enables data transmission in remote areas.
- **Worker Adoption**: Smart helmet integration makes the device easier to use.
- **Battery Life**: Solar-powered options ensure continuous operation.

## Conclusion
BioSafe Monitor is a smart, affordable, and scalable solution designed to protect sanitation workers from life-threatening gas exposure. By integrating real-time IoT monitoring, AI-driven predictions, GSM-based alerts, and comprehensive data analytics, it enhances workplace safety while providing long-term insights to improve safety policies and worker health management.

## DEMO VIDEO LINK : https://www.youtube.com/watch?v=hBV3V14wlOM
