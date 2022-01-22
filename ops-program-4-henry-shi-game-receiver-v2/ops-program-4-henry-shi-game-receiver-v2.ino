/*
 * OPS Project 4: Arduino Uno microcontroller serial comms 
 * Transmitter and Receiver arduino
 * by Henry Shi
 * 
 * Circuit 1 (receiver):
 * - RX connected to other Arduino TX
 * - TX connected to other Arduino RX
 * - GND connected to other Arduino GND
 * - pin 12 (D12) connected to LED in series with 1300 ohm resistor
 * 
 * Circuit 2 (transmitter):
 * - RX connected to other Arduino TX
 * - TX connected to other Arduino RX
 * - GND connected to other Arduino GND
 * 
 * Any Serial.print() and Serial.println() statements 
 * in transmitter code will be executed by receiver
 */

// Define LED pins
#define redLed 11
#define greenLed 12

long randNum;               // random long number
char byteRead;              // character read from bufer
char currentLed;            // LED that is on
bool buttonPressed = false; // Is button pressed?
char isCorrect;             // Is correct button pressed? (T or F character)
int whileCounter = 0;       // counts the number of while loop iterations

void setup() {
  /* Set LED pin to output mode */
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
  // Activate Serial protocol
  Serial.begin(9600);
  while(!Serial) {
    ; // null, waiting for serial port to connect
  }

  // Activate RNG
  randomSeed(analogRead(0));
}

/* code for receiver Arduino */
void loop() {
  randNum = random(2);
  // randomly turn on an LED
  if (randNum == 0) {
    digitalWrite(redLed, HIGH);
    currentLed = 'R';
  } else {
    digitalWrite(greenLed, HIGH);
    currentLed = 'G';
  }
  // loop while button is not pressed
  while (!buttonPressed) {
    // check if there's button press data available to read
    if (Serial.available() > 0) {
      // read the first byte from the receive buffer
      byteRead = Serial.read();

      // If the "red" button is pressed
      if (byteRead == 'R') {
//        Serial.println("red");
        ledOff();   // turn off LEDs
        buttonPressed = true;
        if (byteRead == currentLed) {
          isCorrect = 'T';
        } else {
          isCorrect = 'F';
        }
//        Serial.print("isCorrect: ");
//        Serial.println(isCorrect);
        // send out the "isCorrect" character
        Serial.write(isCorrect);
      }
      // If the "green" button is pressed
      else if (byteRead == 'G') {
//        Serial.println("green");
        ledOff();
        buttonPressed = true;
        if (byteRead == currentLed) { // if correct button is pressed
          isCorrect = 'T';
        } else {
          isCorrect = 'F';
        }
//        Serial.print("isCorrect: ");
//        Serial.println(isCorrect);
        // send out the "isCorrect" character
        Serial.write(isCorrect);
      }
    }
    else {
      //Serial.println("no data available to read");
    }
  }
  
  // reset variables
  buttonPressed = false;    // reset buttonPressed state
  isCorrect = '?';         // reset isCorrect boolean---------------------------------

  // wait 1 second before generating another random light
  delay(1000);
}
void ledOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
}
