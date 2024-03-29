// Constants
const int triggerPin = 2;   // Ultrasonic sensor trigger pin
const int echoPin = 3;      // Ultrasonic sensor echo pin
const int bib = 4;       // LED pin
const int buzzerPin = 5;    // Buzzer pin

// Variables
long duration;              // Time taken for the ultrasonic pulse to return
int distance;               // Distance measured by the ultrasonic sensor

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(bib, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the duration of the pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check the distance and control LED and buzzer accordingly
  if (distance < 30) {    // If distance is less than 30 cm
    digitalWrite(bib, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(bib, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);  // Delay between distance measurements
}