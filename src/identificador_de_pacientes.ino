#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_PN532.h>

// Initialize LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// PN532 I2C pins for Arduino Mega
#define SDA_PIN 20
#define SCL_PIN 21

// Initialize PN532 using I2C
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

// Authorized UID (replace with your card's UID)
uint8_t authorizedUID[] = {0xA3, 0x17, 0xB3, 0xD}; // Example UID
unsigned long lastCardTime = 0;      // Time the last card was read
const unsigned long MAX_CARD_DELAY = 500; // Maximum time in ms to process a card

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Esperando por");
  lcd.setCursor(0, 1);
  lcd.print("cartao...");

  // Initialize PN532
  Wire.begin();
  if (!nfc.begin()) {
    lcd.clear();
    lcd.print("PN532 Error!");
    while (1);  // Halt the program if PN532 is not detected
  }
  lcd.clear();
  lcd.print("RFID Pronto");
  delay(2000); // Show "RFID Ready" before moving to the waiting state
  resetSystem();
}

void loop() {
  uint8_t success;
  uint8_t uid[7];     // Buffer to store the UID
  uint8_t uidLength;  // Length of the UID

  // Attempt to read a card
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    // Card detected
    unsigned long currentCardTime = millis();
    if (currentCardTime - lastCardTime < MAX_CARD_DELAY) {
      // Card passed too fast
      accessDenied("Acesso Negado");
    } else {
      lastCardTime = currentCardTime;  // Update the time of last card read

      // Check if the card is authorized
      if (isAuthorized(uid, uidLength)) {
        authorizedAccess();
      } else {
        accessDenied("Acesso Negado");
      }
    }
  }
}

bool isAuthorized(uint8_t* uid, uint8_t uidLength) {
  // Check if the UID matches the authorized UID
  if (uidLength != sizeof(authorizedUID)) return false;
  for (uint8_t i = 0; i < uidLength; i++) {
    if (uid[i] != authorizedUID[i]) {
      return false;
    }
  }
  return true;
}

void authorizedAccess() {
  // Display "Acesso Autorizado" on LCD
  lcd.clear();
  lcd.print("Acesso");
  lcd.setCursor(0, 1);
  lcd.print("Autorizado");

  // Keep the success message for 3 seconds
  delay(3000);

  // Reset to waiting state
  resetSystem();
}

void accessDenied(const char* message) {
  // Display "Acesso Negado" on LCD
  lcd.clear();
  lcd.print(message);

  // Keep the failure message for 3 seconds
  delay(3000);

  // Reset to waiting state
  resetSystem();
}

void resetSystem() {
  // Clear the LCD and reset the message
  lcd.clear();
  lcd.print("Esperando por");
  lcd.setCursor(0, 1);
  lcd.print("cartao...");
}
