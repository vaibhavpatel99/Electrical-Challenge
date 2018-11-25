int redLed = 7;
int greenLed = 8;
int pot = 0;
int trigPin = 9;
int echoPin = 10;
int motor = 11;

void setup() {
// Runs once
 Serial.begin(9600);
 pinMode(pot, INPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(redLed, OUTPUT);
 pinMode(greenLed, OUTPUT);
 pinMode(motor, OUTPUT);
}

void loop () {
 int motor_spd;
 int pot_val;
 pot_val = analogRead(pot);
 
 double duration, distance;
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2.0/29.1);
 Serial.print(distance);
 Serial.println(" CM");

 if(distance < 10) {
  analogWrite(motor, 0);
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  Serial.println("stop");
 } else {
  motor_spd = map(pot_val, 1, 1023, 0, 255);
  Serial.println(motor_spd);
  analogWrite(motor, motor_spd);
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, LOW);
  Serial.println("run");
 } 
}
