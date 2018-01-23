const int xPin = 2;     // X output of the accelerometer
const int yPin = 3;     // Y output of the accelerometer
const int rightLED = 7; // right LED
const int leftLED = 8;  // left LED
const int fwdLED = 9;   // forward LED
const int revLED = 10;  // backward LED

void setup() {
  // initialize serial communications:
  Serial.begin(9600);
  // initialize the pins connected to the accelerometer as inputs and the LEDs as outputs:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(rightLED, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(fwdLED, OUTPUT);
  pinMode(revLED, OUTPUT);
}

void loop() {
  // variables to read the pulse widths:
  int pulseX, pulseY;

  // read pulse from x- and y-axes:
  pulseX = pulseIn(xPin, HIGH);
  pulseY = pulseIn(yPin, HIGH);
  /************left right control*******************/
  if (pulseY >= 5000){
    digitalWrite(rightLED, HIGH);
    digitalWrite(leftLED, LOW);
  } else{
    digitalWrite(rightLED, LOW);
    digitalWrite(leftLED, HIGH);
  }
  /************fwd backward control*******************/
  if (pulseX >= 5000){
    digitalWrite(fwdLED, LOW);
    digitalWrite(revLED, HIGH);
  } else{
    digitalWrite(fwdLED, HIGH);
    digitalWrite(revLED, LOW);
  }
  // print the acceleration
  //Serial.print(pulseX);
  // print a tab character:
  //Serial.print("\t");
  //Serial.print(pulseY);
  //Serial.println();

  delay(100);
}
