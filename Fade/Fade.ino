const int ledPins[] = {5, 6, 9, 10, 11};  // Array for your specific LED pins
const int numLeds = 5;  // Number of LEDs
int brightness[] = {0, 0, 0, 0, 0};  // Start brightness of LEDs
int fadeAmount = 5;  // Amount to change brightness (same for all LEDs)
unsigned long previousMillis = 0;  // Store last time update
unsigned long interval = 30;  // Time between updates (change this for speed)
int currentLed = 0;  // Current LED index

void setup() {
  // Set up the LED pins as output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time to update the LEDs
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the current time

    // Fade current LED
    brightness[currentLed] += fadeAmount;

    // If the LED is at the extremes (0 or 255), reverse the fade direction
    if (brightness[currentLed] <= 0 || brightness[currentLed] >= 255) {
      fadeAmount = -fadeAmount;  // Reverse the fade direction
    }

    // Update the current LED's brightness
    analogWrite(ledPins[currentLed], brightness[currentLed]);

    // If the current LED has finished fading, move to the next LED
    if (brightness[currentLed] == 0 || brightness[currentLed] == 255) {
      // Move to the next LED
      currentLed++;

      // If we reached the last LED, reset to the first LED
      if (currentLed >= numLeds) {
        currentLed = 0;
      }
    }
  }
}
