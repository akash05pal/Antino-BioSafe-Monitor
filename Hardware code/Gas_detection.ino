<<<<<<< HEAD
#define BLYNK_TEMPLATE_ID "TMPL3j8PNOV6N"
#define BLYNK_TEMPLATE_NAME "BIOSAFE"
#define BLYNK_AUTH_TOKEN "SYX-MbQcASjcvfvOquk6QJY6TkcOWRcg"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Ankit";  // WiFi Name
char pass[] = "anch1234";  // WiFi Password

// Sensor Pins
const int smokeA0 = 34;   // Smoke Sensor
const int mq2A0 = 35;     // MQ-2 Sensor
const int mq135A0 = 32;   // MQ-135 Sensor
const int dhtPin = 27;    // DHT11 Sensor Pin

// DHT Sensor Type
#define DHTTYPE DHT11
DHT dht(dhtPin, DHTTYPE);

BlynkTimer timer;

void setup() {
    Serial.begin(115200);

    // Initialize sensors
    pinMode(smokeA0, INPUT);
    pinMode(mq2A0, INPUT);
    pinMode(mq135A0, INPUT);
    dht.begin();

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

    // Trigger alerts if gas levels exceed safe limits
    if (smokeValue > 500) {
        Blynk.logEvent("gas_alert", "High Smoke Level Detected!");
    }
    if (mq2Value > 400) {
        Blynk.logEvent("gas_alert", "High MQ-2 Gas Level Detected!");
    }
    if (mq135Value > 450) {
        Blynk.logEvent("gas_alert", "High MQ-135 Gas Level Detected!");
    }
    if (temperature > 50) {
        Blynk.logEvent("temp_alert", "High Temperature Detected!");
    }
    if (humidity > 80) {
        Blynk.logEvent("humidity_alert", "High Humidity Detected!");
    }
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Disconnected! Reconnecting...");
        WiFi.begin(ssid, pass);
    }
    Blynk.run();
    timer.run();
}
=======
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // I2C address for most SSD1306 displays

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// Pin definitions
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;

// Gas names for display
const char* gasNames[] = {"H2S", "CH4", "CO", "NH3", "SO2"};
int currentGas = 0; // Index to track which gas is being displayed

void setup() {
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  
  Serial.begin(9600);
  
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Initial display setup
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("BioSafe Monitor"));
  display.println(F("Initializing..."));
  display.display();
  delay(2000);
}

void loop() {
  int analogValue = analogRead(sensor);
  Serial.print("Gas Level: ");
  Serial.println(analogValue);
  
  // Calculate a percentage for visualization (0-100%)
  int percentage = map(analogValue, 0, 1023, 0, 100);
  
  // Clear the display
  display.clearDisplay();
  
  // Display header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("BioSafe Monitor"));
  
  // Display current gas being monitored
  display.setCursor(0, 10);
  display.print(F("Gas: "));
  display.println(gasNames[currentGas]);
  
  // Display gas level
  display.setCursor(0, 20);
  display.print(F("Level: "));
  display.print(analogValue);
  display.print(F(" ("));
  display.print(percentage);
  display.println(F("%)"));
  
  // Draw a progress bar
  display.drawRect(0, 30, 128, 10, SSD1306_WHITE);
  display.fillRect(0, 30, map(analogValue, 0, 1023, 0, 128), 10, SSD1306_WHITE);
  
  // Display status message
  display.setCursor(0, 45);
  if (analogValue > sensorThresh) {
    display.setTextSize(2);
    display.println(F("DANGER!"));
    display.setTextSize(1);
    display.println(F("EVACUATE AREA"));
    
    // Activate warning indicators
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    tone(buzzer, 1000, 500);
  } else {
    display.setTextSize(2);
    display.println(F("SAFE"));
    display.setTextSize(1);
    display.println(F("Environment OK"));
    
    // Activate safe indicators
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
    noTone(buzzer);
  }
  
  // Update display
  display.display();
  
  // Cycle through gas types every 5 seconds for demonstration
  if (millis() % 5000 == 0) {
    currentGas = (currentGas + 1) % 5;
  }
  
  delay(100); // Short delay for stability
}

>>>>>>> 0cc753fccc6c3ee66cedd8fa9988591f571edd76
