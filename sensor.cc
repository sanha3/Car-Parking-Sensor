// C++ code
//
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  while (distance < 10000000) {
    distance = 0.01723 * readUltrasonicDistance(5, 4);
    if (distance > 275) {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      noTone(11);
    } else {
      if (distance > 35) {
        if (distance > 200) {
          digitalWrite(8, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(9, LOW);
          tone(11, 18, 100000000000); // play tone 2 (D0 = 18 Hz)
        } else {
          digitalWrite(8, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(9, HIGH);
          tone(11, 23, 100000000000); // play tone 6 (F#0 = 23 Hz)
        }
      } else {
        if (distance < 35) {
          digitalWrite(8, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(9, HIGH);
          tone(11, 29, 100000000000); // play tone 10 (A#0 = 29 Hz)
        }
      }
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}
