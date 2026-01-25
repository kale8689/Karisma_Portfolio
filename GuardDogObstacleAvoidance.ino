// Motor control pins
const int motor1Pin1 = 7;  // Motor 1 input 1
const int motor1Pin2 = 8;  // Motor 1 input 2
const int motor2Pin1 = 11;  // Motor 2 input 1
const int motor2Pin2 = 12;  // Motor 2 input 2

// Ultrasonic sensor pins
const int trigPin = 6;  // Trigger pin
const int echoPin = 10; // Echo pin

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure distance with the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;  // Calculate distance in cm

  // Print distance to serial monitor for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // If an obstacle is detected within 15 cm, stop and avoid
  if (distance < 15) {
    // Stop the car
    stopCar();

    // Reverse for a short time
    reverseCar();
    delay(1000);  // Reverse for 1 second

    // Turn the car right to avoid the obstacle
    turnRight();
    delay(1000);  // Turn for 1 second

    // Move forward again
    forwardCar();
    delay(1000);  // Move forward for 1 second
  } else {
    // No obstacle detected, move forward
    forwardCar();
  }

  delay(100);  // Small delay before next reading
}

// Function to move the car forward
void forwardCar() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to reverse the car
void reverseCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to stop the car
void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn the car right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
