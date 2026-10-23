// Arduino-Based Hand Gesture Controlled Wheelchair
// Transmitter-side firmware from the ETE 2200 project report (Appendix: Arduino Code).
// Logic is unchanged from the report; only comments and formatting were added.
//
// Board : Arduino Nano (ATmega328P, 5 V, 16 MHz)
// Sensor: ADXL335 analog accelerometer, hand-worn
//         X output -> A3, Y output -> A2
// Output: D10..D13 drive the 4 data inputs (AD0..AD3) of the HT12E encoder.
//         The HT12D decoder on the wheelchair turns these back into 4 parallel
//         lines that feed the L298N motor driver inputs (IN1..IN4).

const int xPin = A3;
const int yPin = A2;

const int Q1 = 10;
const int Q2 = 11;
const int Q3 = 12;
const int Q4 = 13;

long x;
long y;

void setup()
{
  Serial.begin(9600);
  pinMode(Q1, OUTPUT);
  pinMode(Q2, OUTPUT);
  pinMode(Q3, OUTPUT);
  pinMode(Q4, OUTPUT);
}

void loop()
{
  x = analogRead(xPin);
  y = analogRead(yPin);

  // Raw readings (10-bit ADC, 0..1023) for tuning thresholds in the Serial Monitor
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");

  // Thresholds from the report's code. Readings inside the dead band
  // (x 320..370 and y 310..400) leave the chair stopped.
  if (x < 320) {
    left();
  }
  else if (x > 370) {
    right();
  }
  else if (y > 400) {
    forward();
  }
  else if (y < 310) {
    backward();
  }
  else {
    stop_();
  }
}

// Q1..Q4 patterns:  Q1 Q2 Q3 Q4
//   stop            0  0  0  0
//   forward         1  0  0  1
//   backward        0  1  1  0
//   left            1  0  1  0
//   right           0  1  0  1

void stop_()
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(Q1, LOW);
  digitalWrite(Q2, LOW);
  digitalWrite(Q3, LOW);
  digitalWrite(Q4, LOW);
}

void forward()
{
  Serial.println("");
  Serial.println("Forward");
  digitalWrite(Q1, HIGH);
  digitalWrite(Q2, LOW);
  digitalWrite(Q3, LOW);
  digitalWrite(Q4, HIGH);
}

void backward()
{
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(Q1, LOW);
  digitalWrite(Q2, HIGH);
  digitalWrite(Q3, HIGH);
  digitalWrite(Q4, LOW);
}

void left()
{
  Serial.println("");
  Serial.println("Left");
  digitalWrite(Q1, HIGH);
  digitalWrite(Q2, LOW);
  digitalWrite(Q3, HIGH);
  digitalWrite(Q4, LOW);
}

void right()
{
  Serial.println("");
  Serial.println("Right");
  digitalWrite(Q1, LOW);
  digitalWrite(Q2, HIGH);
  digitalWrite(Q3, LOW);
  digitalWrite(Q4, HIGH);
}
