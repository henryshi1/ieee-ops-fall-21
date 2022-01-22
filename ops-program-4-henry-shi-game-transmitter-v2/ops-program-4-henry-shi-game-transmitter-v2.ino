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

// pin numbers
#define LEDPIN 12         // white indicator LED pin
#define redButtonPin 11       // red button pin
#define greenButtonPin 10     // green button pin

// variables for serial comms
char byteRead;

// variables for pushbutton status
int redButtonState;       // default with pull-up resistor is HIGH
int greenButtonState;
int lastRedButtonState = HIGH;   // previous pushbutton state
int lastGreenButtonState = HIGH;
int ledState = LOW;       // LED state
int score = 0;            // score starts at 0
int gameOver = false;     // gameOver is initially false
unsigned long lastDebounceTime = 0;    // time since last debounce
unsigned long debounceDelay = 50;       // 50 ms delay time for debounce
bool isCorrect;           // is the correct button pressed?
bool signalRead = false;  // was the signal from the receiver read in or not?

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(redButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  
  /* Activate Serial protocol and
  begin transmitting data at 9600 baud rate */
  Serial.begin(9600);
  while(!Serial) {
    ; // null, waiting for serial port to connect
  }

  // initialize LED state
  digitalWrite(LEDPIN, ledState);
  
}

/* code for transmitter Arduino */
void loop() {
  
  // read the state of red and green pushbutton into a local variable
  int redReading = digitalRead(redButtonPin);
//  Serial.print("red button reading: ");
//  Serial.print(redReading);
  int greenReading = digitalRead(greenButtonPin);
//  Serial.print(", green button reading: ");
//  Serial.println(greenReading);
  
  // check if either pushbutton is pressed
  
  if (redReading == LOW && redReading != lastRedButtonState) {
    delay(50);    // 50ms debounce time
    // if button is still pressed after 50ms, we take it as a legit press
    if (redReading == LOW) {
      Serial.write('R');
      Serial.flush();     // wait for the char to send out completely before continuing
    }
  }
  else if (greenReading == LOW && greenReading != lastGreenButtonState) {
    delay(50);    // 50ms debounce time
    // if button is still pressed after 50ms, we take it as a legit press
    if (greenReading == LOW) {
      Serial.write('G');
      Serial.flush();
    }
  }
  lastRedButtonState = redReading;
  lastGreenButtonState = greenReading;

  // read signal from other arduino
  // check to see if a signal exists
  if (Serial.available() > 0) {
    byteRead = Serial.read();       // read signal
//    Serial.print("byteRead: ");
//    Serial.println(byteRead);
    // if the signal is 'T', indicating correct button press
    if (byteRead == 'T') {
//      Serial.print("byteRead: ");
//      Serial.println(byteRead);
      blinkLed(3);// blink 3 times
    } // if the signal is 'F', indicating incorrect button press
    else if (byteRead == 'F') {
//      Serial.print("byteRead: ");
//      Serial.println(byteRead);
      // blink once
    }
  } else {
    //Serial.println("no data available to read");
  }

//    if (isCorrect == 1) {         // 1 for correct button
//      blinkLED(3);
//    } else if (isCorrect == 0) {  // 0 for incorrect button
//      digitalWrite(LEDPIN, HIGH);
//      delay(1500);
//      digitalWrite(LEDPIN, LOW);
//      delay(500);
//    }
//    Serial.flush();
//    isCorrect = '?';
  
    /* check if either pushbutton is pressed
       (i.e. input went from HIGH to LOW)
       and if you've waited long enough since last press for noise to die down
    */
    /*
    // if red button state changes,
    if (redReading != lastRedButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    
      // if reading has been around for longer than debounce time, 
      // take it as the actual current button state
      if ((millis() - lastDebounceTime) > debounceDelay) {
        Serial.println("red pressed");
        // if the button state has changed since last time
        if (redReading != redButtonState) {
          // assign the red reading to the red button state
          redButtonState = redReading;
          
          // turn LED on and increment score if new button state is LOW, i.e. pressed
          if (redButtonState == LOW) {
            ledState = HIGH;
            // send out "red" signal
            Serial.write('R');
            Serial.println("red");
            score++;
          } // otherwise, turn LED off and do not increment score
          else {
            ledState = LOW;
          }
          
        }
      }
    }
    // if green button state changes,
    else if (greenReading != lastGreenButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    
      // if reading has been around for longer than debounce time, 
      // take it as the actual current button state
      if ((millis() - lastDebounceTime) > debounceDelay) {
        // if the button state has changed since last time
        if (greenReading != greenButtonState) {
          // assign the reading to the button state
          greenButtonState = greenReading;
          
          // turn LED on and increment score if new button state is LOW, i.e. pressed
          if (greenButtonState == LOW) {
            ledState = HIGH;
            Serial.write('G');
            Serial.println("green");
            // dummy block, comment out in final program
            score++;
          } // otherwise, turn LED off and do not increment score
          else {
            ledState = LOW;
          }
        }
      }
    }
    // set the LED
    digitalWrite(LEDPIN, ledState);
    // save the readings as last button states for the next loop iteration
    lastRedButtonState = redReading;
    lastGreenButtonState = greenReading;

    // dummy test block, comment out in final program
    if (score >= 5) {
      gameOver = true;
    }
    */
  /*
  // after game ends, print out score
  Serial.print("score: ");
  Serial.println(score);
  */
}

// blink LED for a set number of blinks
void blinkLed(int nBlinks) {
  for (int i = 0; i<nBlinks; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(250);
    digitalWrite(LEDPIN, LOW);
    delay(250);
  }
}
