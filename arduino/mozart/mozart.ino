/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#define NOTE_A3  220
#define NOTE_B3  247

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330

#define NOTE_F4  349
#define NOTE_G4  392

int audioPin = 9;

// notes in the melody:
int melody[] = {
  NOTE_E4, NOTE_D4, NOTE_C4, 0,
  NOTE_E4, NOTE_D4, NOTE_C4, 0,
  NOTE_C4, NOTE_C4, NOTE_C4, 0,
  NOTE_D4, NOTE_D4, NOTE_D4, 0,
  NOTE_E4, NOTE_D4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  8, 8, 8, 8,
  8, 8, 8, 8,
  4, 4, 4, 4
};

int playMelodyButton;
int buttonA;
int buttonB;
int buttonC;
int buttonD;
int buttonE;
int buttonF;
int buttonG;
bool playingA;
bool playingB;
bool playingC;
bool playingD;
bool playingE;
bool playingF;
bool playingG;

void playMelody() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 20; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(audioPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(audioPin);
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  playMelodyButton = digitalRead(10);
  buttonA = digitalRead(2);
  buttonB = digitalRead(3);
  buttonC = digitalRead(4);
  buttonD = digitalRead(5);
  buttonE = digitalRead(6);
  buttonF = digitalRead(7);
  buttonG = digitalRead(8);
  
  if (playMelodyButton == HIGH) {
    playMelody();
  }
  
  if (buttonA == HIGH) {
    tone(audioPin, NOTE_A3);
    playingA = true;
  } else if (buttonA == 0 && playingA == true) {
    noTone(audioPin);
    playingA = false;
  }
  if (buttonB == HIGH) {
    tone(audioPin, NOTE_B3);
    playingB = true;
  } else if (buttonB == 0 && playingB == true) {
    noTone(audioPin);
    playingB = false;
  }
  if (buttonC == HIGH) {
    tone(audioPin, NOTE_C4);
    playingC = true;
  } else if (buttonC == 0 && playingC == true) {
    noTone(audioPin);
    playingC = false;
  }
  if (buttonD == HIGH) {
    tone(audioPin, NOTE_D4);
    playingD = true;
  } else if (buttonD == 0 && playingD == true) {
    noTone(audioPin);
    playingD = false;
  }
  if (buttonE == HIGH) {
    tone(audioPin, NOTE_E4);
    playingE = true;
  } else if (buttonE == 0 && playingE == true) {
    noTone(audioPin);
    playingE = false;
  }
  if (buttonF == HIGH) {
    tone(audioPin, NOTE_F4);
    playingF = true;
  } else if (buttonF == 0 && playingF == true) {
    noTone(audioPin);
    playingF = false;
  }
  if (buttonG == HIGH) {
    tone(audioPin, NOTE_G4);
    playingG = true;
  } else if (buttonG == 0 && playingG == true) {
    noTone(audioPin);
    playingG = false;
  }
}