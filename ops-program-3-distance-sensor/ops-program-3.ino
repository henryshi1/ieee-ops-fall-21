long zero;
#define IR 19
#define LED 6

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  // noise calibration
  zero = 0;
  for (int i = 0; i < 100; i++) {
    zero += analogRead(IR);
  }
  zero /= 100;
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Read in IR sensor intensity value */
  int val = analogRead(IR) - zero;
  Serial.println("val");
  Serial.println(val);
  /* Map an analog value to 8 bits (0 to 255) 
     and constrain */
  val = map(val, 0, 1023, 0, 255);
  val = constrain(val,0,255);
  /* Set LED brightness based on IR sensor 
     reading */
  analogWrite(LED, val);
}
