#define BLYNK_TEMPLATE_ID "TMPL3j8PNOV6N"
#define BLYNK_TEMPLATE_NAME "BIOSAFE"
#define BLYNK_AUTH_TOKEN "SYX-MbQcASjcvfvOquk6QJY6TkcOWRcg"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Ankit";  // WiFi Name
char pass[] = "anch1234";  // WiFi Password

// Sensor Pins
const int smokeA0 = 34;   // Smoke Sensor
const int mq2A0 = 35;     // MQ-2 Sensor
const int mq135A0 = 32;   // MQ-135 Sensor
const int dhtPin = 27;    // DHT11 Sensor Pin
const int ledPin = 2;     // LED Indicator

// DHT Sensor Type
#define DHTTYPE DHT11
DHT dht(dhtPin, DHTTYPE);

// LCD Display Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;

void setup() {
    Serial.begin(115200);

    // Initialize sensors
    pinMode(smokeA0, INPUT);
    pinMode(mq2A0, INPUT);
    pinMode(mq135A0, INPUT);
    pinMode(ledPin, OUTPUT);
    dht.begin();

    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("BIOSAFE MONITOR");
    delay(2000);
    lcd.clear();

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, pass);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) {
        Serial.print(".");
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi Connected!");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nFailed to connect to WiFi.");
    }

    // Connect to Blynk
    Blynk.config(auth);
    Blynk.connect();

    // Send sensor data every 1 second
    timer.setInterval(1000L, sendSensorData);
}

void sendSensorData() {
    int smokeValue = analogRead(smokeA0);
    int mq2Value = analogRead(mq2A0);
    int mq135Value = analogRead(mq135A0);
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    bool alert = false;

    // Send values to Blynk
    Blynk.virtualWrite(V0, smokeValue);
    Blynk.virtualWrite(V1, mq2Value);
    Blynk.virtualWrite(V2, mq135Value);
    Blynk.virtualWrite(V3, temperature);
    Blynk.virtualWrite(V4, humidity);

    Serial.print("Smoke Sensor: ");
    Serial.print(smokeValue);
    Serial.print(" | MQ-2: ");
    Serial.print(mq2Value);
    Serial.print(" | MQ-135: ");
    Serial.print(mq135Value);
    Serial.print(" | Temp: ");
    Serial.print(temperature);
    Serial.print("°C | Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    // Display values on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Smoke:");
    lcd.print(smokeValue);
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(temperature);
    lcd.print("C");
    delay(1000);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MQ2:");
    lcd.print(mq2Value);
    lcd.setCursor(0, 1);
    lcd.print("Humidity:");
    lcd.print(humidity);
    lcd.print("%");
    delay(1000);

    // Trigger alerts if gas levels exceed safe limits
    if (smokeValue > 500) {
        Blynk.logEvent("gas_alert", "High Smoke Level Detected!");
        alert = true;
    }
    if (mq2Value > 400) {
        Blynk.logEvent("gas_alert", "High MQ-2 Gas Level Detected!");
        alert = true;
    }
    if (mq135Value > 450) {
        Blynk.logEvent("gas_alert", "High MQ-135 Gas Level Detected!");
        alert = true;
    }
    if (temperature > 50) {
        Blynk.logEvent("temp_alert", "High Temperature Detected!");
        alert = true;
    }
    if (humidity > 80) {
        Blynk.logEvent("humidity_alert", "High Humidity Detected!");
        alert = true;
    }

    // Turn on LED if alert is triggered
    digitalWrite(ledPin, alert ? HIGH : LOW);
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Disconnected! Reconnecting...");
        WiFi.begin(ssid, pass);
    }
    Blynk.run();
    timer.run();
}
