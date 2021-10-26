//
//  MaryLittleLamb.h
//  Mary Had a Little Lamb
//
//  Not created by Henry Shi
//  Public Domain
//

#define NOTE_DUR 137

void play(int note, int dur);

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
