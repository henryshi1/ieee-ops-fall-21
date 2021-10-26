/*
 * OPS Program
 * Lecture 1
 * 2021-09-27
 * Henry Shi
 */

// define pin for potentiometer input
#define RECEIVER 18
// define pin for LED
#define LED 7
/*  set the blinking timescale
 *  blink rate scales with potentiometer voltage */
#define timescale 1

void setup() {
  // set potentiometer receiver pin to input
  pinMode(RECEIVER, INPUT);
  // set LED pin to output
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read value from potentiometer
  int pMeterValue = analogRead(RECEIVER);
  // print out potentiometer value
  Serial.println(pMeterValue);

  // turn on LED by putting 5V into it
  digitalWrite(LED, HIGH);

  // wait for a certain time depending on the potentiometer value
  delay(timescale*pMeterValue);

  // turn off LED by putting 0V into it
  digitalWrite(LED, LOW);

  // wait for a certain time depending on the potentiometer value
  delay(timescale*pMeterValue);
}
