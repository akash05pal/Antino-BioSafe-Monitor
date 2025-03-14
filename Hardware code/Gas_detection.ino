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

