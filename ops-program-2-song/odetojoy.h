//
//  OdeToJoy.h
//  Ode To Joy
//
//  Ludwig van Beethoven
//  Public Domain
//

#define NOTE_DUR 137

void play(int note, int dur);

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
