Sure, I'll complete the functions within the provided code with a focus on functionality and readability.

### Completed Code
#include <LiquidCrystal.h>
#include <string.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define light 3
#define fan 4
#define TV 5

char temp;
char str[10];
char i = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(TV, OUTPUT);
  lcd.print(" Home Automation ");
  lcd.setCursor(0, 1);
  lcd.print("    Using PC     ");
  delay(2000);
  lcd.clear();
  lcd.print("Keywords For ");
  lcd.setCursor(0, 1);
  lcd.print("Controlling");
  delay(2000);
  lcd.clear();
  lcd.print("1. LIGHT ON");
  lcd.setCursor(0, 1);
  lcd.print("2. LIGHT OFF");
  delay(2000);
  lcd.clear();
  lcd.print("3. FAN ON");
  lcd.setCursor(0, 1);
  lcd.print("4. FAN OFF");
  delay(2000);
  lcd.clear();
  lcd.print("5. TV ON");
  lcd.setCursor(0, 1);
  lcd.print("6. TV OFF");
  delay(2000);
  defaultDisplay();
  delay(1000);
}

void loop() {
  if (temp == 1) {
    str[i] = '\0'; // Null-terminate the string
    // Fan control
    if (strncmp(str, "FAN ON", 6) == 0) {
      digitalWrite(fan, HIGH);
      lcd.clear();
      lcd.print("Fan Turned On");
    } else if (strncmp(str, "FAN OFF", 7) == 0) {
      digitalWrite(fan, LOW);
      lcd.clear();
      lcd.print("Fan Turned Off");
    }
    // Light control
    else if (strncmp(str, "LIGHT ON", 8) == 0) {
      digitalWrite(light, HIGH);
      lcd.clear();
      lcd.print("Light Turned On");
    } else if (strncmp(str, "LIGHT OFF", 9) == 0) {
      digitalWrite(light, LOW);
      lcd.clear();
      lcd.print("Light Turned Off");
    }
    // TV control
    else if (strncmp(str, "TV ON", 5) == 0) {
      digitalWrite(TV, HIGH);
      lcd.clear();
      lcd.print("TV Turned On");
    } else if (strncmp(str, "TV OFF", 6) == 0) {
      digitalWrite(TV, LOW);
      lcd.clear();
      lcd.print("TV Turned Off");
    } else {
      lcd.clear();
      lcd.print("Invalid Input");
      lcd.setCursor(0, 1);
      lcd.print("Try Again");
    }
    delay(3000);
    defaultDisplay();
  }
}

void serialEvent() {
  while (Serial.available()) {
    char Inchar = Serial.read();
    if (i < sizeof(str) - 1) { // Prevent buffer overflow
      str[i++] = Inchar;
      lcd.print(Inchar);
    }
    if (Inchar == '\n') { // End of command
      temp = 1;
      i = 0; // Reset the index for the next command
    }
  }
}

void defaultDisplay() {
  lcd.clear();
  lcd.print("Enter Your Choice:");
  lcd.setCursor(0, 1);
  lcd.cursor();
  memset(str, 0, sizeof(str)); // Clear the buffer
  temp = 0;
}