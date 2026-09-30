#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String passwordArray[3] = {"3", "7", "5"};
String input_password;
int startButton;
bool setPassword;
String password;
const int passwordLength = 4;
String passwordPart[passwordLength];

// Pins used for the LEDs
const int redLED = 11;
const int greenLED = 12;
const int blueLED = 13;

void setup(){
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
  pinMode(2, OUTPUT);
  pinMode(10, INPUT);
  setPassword = false;
  startButton = 0;
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop(){
  startButton = digitalRead(10);
  if (startButton == HIGH) {
    for (int i = 0; i < password.length(); i++) {
      if (password[i] == '3') {
        digitalWrite(redLED, HIGH);
        delay(1000);
        digitalWrite(redLED, LOW);
        delay(500);
      }
      else if (password[i] == '7') {
        digitalWrite(greenLED, HIGH);
        delay(1000);
        digitalWrite(greenLED, LOW);
        delay(500);
      }
      else if (password[i] == '5') {
        digitalWrite(blueLED, HIGH);
        delay(1000);
        digitalWrite(blueLED, LOW);
        delay(500);
      }
    }
    if (setPassword != true) {
      randomSeed(analogRead(0));
      for (int i = 0; i < passwordLength; i++) {
        passwordPart[i] = passwordArray[random(0, 3)];
      }
      for (int i = 0; i < passwordLength; i++) {
        password += passwordPart[i];
      }
      Serial.println(password);
      setPassword = true;
    }
  }
  char key = keypad.getKey();

  if (key){
    Serial.println(key);

    if(key == '*') {
      input_password = ""; // clear input password
    } else if(key == '#') {
      if(password == input_password && setPassword == true) {
        Serial.println("password is correct");
        // DO YOUR WORK HERE
		digitalWrite(2, HIGH);
        
      } else {
        Serial.println("password is incorrect, try again");
      }

      input_password = ""; // clear input password
    } else {
      input_password += key; // append new character to input password string
    }
  }
}
