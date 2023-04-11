// Define the pins for the motors
const int MOTOR1_CLOCKWISE_PIN = 13;
const int MOTOR1_COUNTERCLOCKWISE_PIN = 12;
const int MOTOR2_CLOCKWISE_PIN = 14;
const int MOTOR2_COUNTERCLOCKWISE_PIN = 27;

// Define the pins for the buttons
#define BUTTON1_PIN 15
#define BUTTON2_PIN 4

// Define the motor speeds
#define MOTOR1_SPEED 255
#define MOTOR2_SPEED 255

// Define the pin for the limit switch
#define LIMIT_SWITCH_PIN 10

void setup() {
  Serial.begin(115200);
  // Set the motor pins as output
  pinMode(MOTOR1_CLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR1_COUNTERCLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR2_CLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR2_COUNTERCLOCKWISE_PIN, OUTPUT);

    digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, HIGH);
    digitalWrite(MOTOR2_CLOCKWISE_PIN, HIGH);
    digitalWrite(MOTOR2_COUNTERCLOCKWISE_PIN, HIGH);

  // Set the button pins as input with pull-up resistors
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  // Set the limit switch pin as input with pull-up resistor
  pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  
  // Check if button 1 is pressed
  if (digitalRead(BUTTON1_PIN) == LOW) {
    // Stop all motors
    digitalWrite(MOTOR1_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR2_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR2_COUNTERCLOCKWISE_PIN, LOW);
    
    // Rotate motor 1 clockwise for 5 seconds
    digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
    delay(5000);
    
    // Rotate motor 1 counterclockwise for 5 seconds
    digitalWrite(MOTOR1_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, HIGH);
    delay(5000);
    
    // Stop motor 1
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, HIGH);
    digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
    
    // Rotate motor 2 clockwise for 2 seconds
    digitalWrite(MOTOR2_CLOCKWISE_PIN, HIGH);
    delay(2000);
    
    // Stop motor 2
    digitalWrite(MOTOR2_CLOCKWISE_PIN, LOW);
  }
  
  // Check if button 2 is pressed
  if (digitalRead(BUTTON2_PIN) == LOW) {
    // Stop all motors
    digitalWrite(MOTOR1_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR2_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR2_COUNTERCLOCKWISE_PIN, LOW);
    
    // Rotate motor 2 counterclockwise for 2 seconds
    digitalWrite(MOTOR2_COUNTERCLOCKWISE_PIN, HIGH);
    delay(2000);
    
    // Stop motor 2
    digitalWrite(MOTOR2_COUNTERCLOCKWISE_PIN, LOW);
  }
}