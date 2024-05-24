#include "pitches.h"

const int BUTTON_PIN = 9;
int buttonState = 0;

//song1
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

//song2
int melody2[] = {
  NOTE_DS6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_DS6, 0, NOTE_D6, NOTE_C4
};
int noteDurations2[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(BUTTON_PIN , INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  Serial.print(buttonState);  
  
  if(buttonState == LOW)
  {
     for (int thisNote = 0; thisNote < 8; thisNote++) 
     {
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(8);
     }
  }
  else if(buttonState == HIGH)
  {
    for (int thisNote = 0; thisNote < 8; thisNote++) 
       {
          int noteDuration = 1000 / noteDurations2[thisNote];
          tone(8, melody2[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(8);
       }
  }

}
