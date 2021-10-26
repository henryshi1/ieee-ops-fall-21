#include "basicpitches.h"
#include "pitches.h"
/*#include "Despacito.h"
#include "marylittlelamb.h"
#include "odetojoy.h"
*/
#define SPEAKER 3
#define RECEIVER A6
int NOTE_DUR = 56;

// play a note for a certain number of beats
// note = frequency of the note given by basicpitches.h
// dur = duration in # of beats
void play(int note, double dur) {
  tone(SPEAKER, note);
  delay(dur*NOTE_DUR);
  noTone(SPEAKER);
  delay(dur*NOTE_DUR/3);
}

void setup() {
  Serial.begin(9600);     // initialize serial output at 9600 bitrate
  pinMode(SPEAKER, OUTPUT);
  pinMode(RECEIVER, INPUT);
}

void loop() {
  
  // Read in potentiometer value
  int pMeterValue = analogRead(RECEIVER);
  
  // Print potentiometer value
  Serial.println("pMeterValue:");
  Serial.println(pMeterValue);
  /*
  // Calculate duty cycle and print it
  double dCycle = pMeterValue/1023.0;
  Serial.println(dCycle);

  // Output PWM signal to the speaker pin
  analogWrite(SPEAKER, dCycle*255);
  */
  // Choose a song based on receiver value
  if (pMeterValue<341) {
    // song 1
    Despacito();
  } else if (pMeterValue<682) {
    // song 2
    Mary();
  } else {
    // song 3
    OdeToJoy();
  }
}
void Mary() {
    NOTE_DUR = 126;
    play(NOTE_E4, 1);  //m1
    play(NOTE_D4, 1);
    play(NOTE_C4, 1);
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);
    play(NOTE_E4, 1);
    play(NOTE_E4, 2);
 
    delay(NOTE_DUR*6); //m2
    play(NOTE_D4, 1);
    play(NOTE_D4, 1);
    play(NOTE_D4, 2);
    play(NOTE_E4, 1);
    play(NOTE_G4, 1);
    play(NOTE_G4, 2);

    delay(NOTE_DUR*6); //m3
    play(NOTE_E4, 1);
    play(NOTE_D4, 1);
    play(NOTE_C4, 1);
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);
    play(NOTE_E4, 1);
    play(NOTE_E4, 1);
    play(NOTE_E4, 1);
  
    play(NOTE_D4, 1);  //m4
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);
    play(NOTE_D4, 1);
    play(NOTE_C4, 2);

    delay(NOTE_DUR*4);
}

void OdeToJoy() {

    NOTE_DUR = 126;
    play(NOTE_E4, 1); // M1
    play(NOTE_E4, 1);
    play(NOTE_F4, 1);
    play(NOTE_G4, 1);
 
    play(NOTE_G4, 1); // M2 
    play(NOTE_F4, 1);
    play(NOTE_E4, 1);
    play(NOTE_D4, 1);

    play(NOTE_C4, 1); // M3
    play(NOTE_C4, 1);
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);

    play(NOTE_E4, 1.5); // M4
    play(NOTE_D4, 0.5);
    play(NOTE_D4, 2);

    play(NOTE_E4, 1); // M5
    play(NOTE_E4, 1);
    play(NOTE_F4, 1);
    play(NOTE_G4, 1);

    play(NOTE_G4, 1); // M6
    play(NOTE_F4, 1);
    play(NOTE_E4, 1);
    play(NOTE_D4, 1);

    play(NOTE_C4, 1); // M7
    play(NOTE_C4, 1);
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);

    play(NOTE_D4, 1.5); // M8
    play(NOTE_C4, 0.5);
    play(NOTE_C4, 2);

    play(NOTE_D4, 1); // M9
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);
    play(NOTE_C4, 1);
  
  
    play(NOTE_D4, 1); // M10
    play(NOTE_E4, 0.5);
    play(NOTE_F4, 0.5);
    play(NOTE_E4, 1);
    play(NOTE_C4, 1);

    play(NOTE_D4, 1); // M11
    play(NOTE_E4, 0.5);
    play(NOTE_F4, 0.5);
    play(NOTE_E4, 1);
    play(NOTE_D4, 1);

    play(NOTE_C4, 1); // M12
    play(NOTE_D4, 1);
    play(NOTE_G3, 2);

    play(NOTE_E4, 1); // M13
    play(NOTE_E4, 1);
    play(NOTE_F4, 1);
    play(NOTE_G4, 1);

    play(NOTE_G4, 1); // M14
    play(NOTE_F4, 1);
    play(NOTE_E4, 1);
    play(NOTE_D4, 1);

    play(NOTE_C4, 1); // M15
    play(NOTE_C4, 1);
    play(NOTE_D4, 1);
    play(NOTE_E4, 1);
  
    play(NOTE_D4, 1.5); // M16
    play(NOTE_C4, 0.5);
    play(NOTE_C4, 2);
  
    delay(NOTE_DUR*4);
}

void Despacito() {
    play(NOTE_D4, 1);
    play(NOTE_FS4, 1);
    play(NOTE_B4, 1);
    play(NOTE_D5, 1);
    play(NOTE_CS5, 1);
    play(NOTE_B4, 1);
    play(NOTE_AS4, 1);
    play(NOTE_B4, 16); //m2
    delay(NOTE_DUR*6);
    play(NOTE_B4, 6);
    play(NOTE_CS5, 6);
    play(NOTE_D5, 6);
    play(NOTE_E5, 6); //m3
    play(NOTE_FS5, 7);
    play(NOTE_D5, 7);
    play(NOTE_FS5, 8);
    play(NOTE_D5, 8);
    play(NOTE_FS5, 22);
    delay(NOTE_DUR*4);
    play(NOTE_FS4, 2); //m4
    play(NOTE_D5, 6);
    play(NOTE_E4, 2);
    play(NOTE_CS5, 6);
    play(NOTE_D4, 2);
    play(NOTE_B4, 4); //m5
    play(NOTE_D4, 2);
    play(NOTE_FS4, 4);
    play(NOTE_B4, 2);
    play(NOTE_D4, 4);
    play(NOTE_B4, 4);
    play(NOTE_D4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4); //m6
    play(NOTE_D4, 2);
    play(NOTE_G4, 4);
    play(NOTE_B4, 2);
    play(NOTE_D4, 4);
    play(NOTE_B4, 4);
    play(NOTE_D4, 2);
    play(NOTE_G4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 4); //m7
    play(NOTE_FS4, 2);
    play(NOTE_A4, 4);
    play(NOTE_D5, 2);
    play(NOTE_FS4, 4);
    play(NOTE_D5, 4);
    play(NOTE_FS4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_E5, 12); //m8
    delay(NOTE_DUR*2);
    play(NOTE_FS4, 2);
    play(NOTE_D5, 6);
    play(NOTE_E4, 2);
    play(NOTE_CS5, 6);
    play(NOTE_D4, 2);
    play(NOTE_B4, 10); //m9
}
