int E2 = 11;
int M2 = 13; 
const int xPin = 2;     // X output of the accelerometer
const int yPin = 3;     // Y output of the accelerometer

void setup()
{
  Serial.begin (9600);
 pinMode(xPin, INPUT);
 pinMode(yPin, INPUT);
 pinMode(M2, OUTPUT);
}
void loop()
{
  int pulseX, pulseY;
  pulseX = pulseIn(xPin, HIGH);
  pulseY = pulseIn(yPin, HIGH);
  
 if (pulseY >= 5000){
 // FORWARD 
 analogWrite(E2, 255);
 digitalWrite(M2, HIGH); 
 Serial.println(pulseY);
 }

else {
 // REVERSE
 analogWrite(E2, 255);
 digitalWrite(M2, LOW);
 Serial.println(pulseY);
}
// // STOP
// analogWrite(E2, 0);
// digitalWrite(M2, LOW); 
// delay(1000);
 }

