#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 8

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Your UIDs
byte card1[4] = {0x29, 0x8B, 0xFC, 0x03};
byte card2[4] = {0xA3, 0x00, 0xC1, 0x2C};
byte card3[4] = {0xE3, 0xBA, 0xCA, 0x06};  // 🔥 NEW

bool marked1 = false;
bool marked2 = false;
bool marked3 = false;   // 🔥 NEW

bool checked1 = false;
bool checked2 = false;
bool checked3 = false;  // 🔥 NEW

int count = 0;

void setup() {
  SPI.begin();
  Wire.begin();
  lcd.init();
  lcd.backlight();

  pinMode(BUZZER, OUTPUT);

  mfrc522.PCD_Init();

  lcd.setCursor(0, 0);
  lcd.print("Scan Card");
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  if (compareUID(mfrc522.uid.uidByte, card1)) {

    if (!marked1) {
      marked1 = true;
      count++;
      accessGranted();
    } else {
      checked1 = true;
      showMessage("Already Marked");
    }

  } else if (compareUID(mfrc522.uid.uidByte, card2)) {

    if (!marked2) {
      marked2 = true;
      count++;
      accessGranted();
    } else {
      checked2 = true;
      showMessage("Already Marked");
    }

  } else if (compareUID(mfrc522.uid.uidByte, card3)) {   // 🔥 NEW

    if (!marked3) {
      marked3 = true;
      count++;
      accessGranted();
    } else {
      checked3 = true;
      showMessage("Already Marked");
    }

  } else {
    showMessage("Access Denied");
  }

  delay(2000);

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  // 🔥 RESET ONLY AFTER ALL 3 RE-SCANNED
  if (marked1 && marked2 && marked3 && checked1 && checked2 && checked3) {
    delay(2000);
    resetSystem();
  } else {
    lcd.clear();
    lcd.print("Scan Card");
  }
}

bool compareUID(byte *a, byte *b) {
  for (byte i = 0; i < 4; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void accessGranted() {
  lcd.clear();
  lcd.print("Access Granted");
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(count);

  tone(BUZZER, 1000);
  delay(200);
  noTone(BUZZER);
}

void showMessage(String msg) {
  lcd.clear();
  lcd.print(msg);
}

void resetSystem() {
  marked1 = false;
  marked2 = false;
  marked3 = false;

  checked1 = false;
  checked2 = false;
  checked3 = false;

  count = 0;

  lcd.clear();
  lcd.print("Scan Card");
}
