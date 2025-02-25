
#include <ESP8266WiFi.h>

// Motor driver 1 pin definitions (Front motors)
#define FRONT_LEFT_FORWARD D1
#define FRONT_LEFT_BACKWARD D2
#define FRONT_RIGHT_FORWARD D3
#define FRONT_RIGHT_BACKWARD D4

// Motor driver 2 pin definitions (Rear motors)
#define REAR_LEFT_FORWARD D5
#define REAR_LEFT_BACKWARD D6
#define REAR_RIGHT_FORWARD D7
#define REAR_RIGHT_BACKWARD D8

// Speed control (PWM)
#define SPEED_CONTROL D0

// Ultrasonic sensor pin definitions
#define TRIG_PIN D9
#define ECHO_PIN D10

// Buzzer pin definition (used for both horn and warning)
#define BUZZER_PIN D11

const char *ssid = "Your_SSID"; // WiFi SSID
const char *password = "Your_PASSWORD"; // WiFi password

WiFiServer server(80); // Start the server on port 80
int motorSpeed = 500; // Default motor speed (0-1023 for PWM control)

void setup() {
    // Set motor control pins as OUTPUT
    pinMode(FRONT_LEFT_FORWARD, OUTPUT);
    pinMode(FRONT_LEFT_BACKWARD, OUTPUT);
    pinMode(FRONT_RIGHT_FORWARD, OUTPUT);
    pinMode(FRONT_RIGHT_BACKWARD, OUTPUT);
    pinMode(REAR_LEFT_FORWARD, OUTPUT);
    pinMode(REAR_LEFT_BACKWARD, OUTPUT);
    pinMode(REAR_RIGHT_FORWARD, OUTPUT);
    pinMode(REAR_RIGHT_BACKWARD, OUTPUT);
    pinMode(SPEED_CONTROL, OUTPUT);
    
    // Set ultrasonic sensor pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    
    // Set buzzer pin as OUTPUT
    pinMode(BUZZER_PIN, OUTPUT);
    
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    // Wait for WiFi connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");
    server.begin(); // Start the server
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        // Read incoming request from client
        String request = client.readStringUntil('\r');
        client.flush();
        
        // Check received command and perform the appropriate action
        if (request.indexOf("FORWARD") != -1) {
            moveForward();
        } else if (request.indexOf("BACKWARD") != -1) {
            moveBackward();
        } else if (request.indexOf("LEFT") != -1) {
            turnLeft();
        } else if (request.indexOf("RIGHT") != -1) {
            turnRight();
        } else if (request.indexOf("STOP") != -1) {
            stopMotors();
        } else if (request.indexOf("SPEED") != -1) {
            int speedValue = request.substring(request.indexOf("SPEED") + 5).toInt();
            setSpeed(speedValue);
        } else if (request.indexOf("HORN") != -1) {
            honkHorn();
        }
    }
    
    // Measure distance using the ultrasonic sensor
    long distance = getDistance();
    
    // Activate buzzer if an obstacle is within 5 cm (warning)
    if (distance <= 5 && distance > 2) {
        digitalWrite(BUZZER_PIN, HIGH);
    } else {
        digitalWrite(BUZZER_PIN, LOW);
    }
    
    // Stop motors if an obstacle is within 2 cm
    if (distance <= 2) {
        stopMotors();
    }
}

// Function to move the car forward
void moveForward() {
    analogWrite(FRONT_LEFT_FORWARD, motorSpeed);
    analogWrite(FRONT_RIGHT_FORWARD, motorSpeed);
    analogWrite(REAR_LEFT_FORWARD, motorSpeed);
    analogWrite(REAR_RIGHT_FORWARD, motorSpeed);
    digitalWrite(FRONT_LEFT_BACKWARD, LOW);
    digitalWrite(FRONT_RIGHT_BACKWARD, LOW);
    digitalWrite(REAR_LEFT_BACKWARD, LOW);
    digitalWrite(REAR_RIGHT_BACKWARD, LOW);
}

// Function to move the car backward
void moveBackward() {
    analogWrite(FRONT_LEFT_BACKWARD, motorSpeed);
    analogWrite(FRONT_RIGHT_BACKWARD, motorSpeed);
    analogWrite(REAR_LEFT_BACKWARD, motorSpeed);
    analogWrite(REAR_RIGHT_BACKWARD, motorSpeed);
    digitalWrite(FRONT_LEFT_FORWARD, LOW);
    digitalWrite(FRONT_RIGHT_FORWARD, LOW);
    digitalWrite(REAR_LEFT_FORWARD, LOW);
    digitalWrite(REAR_RIGHT_FORWARD, LOW);
}

// Function to turn the car left
void turnLeft() {
    digitalWrite(FRONT_LEFT_FORWARD, LOW);
    digitalWrite(REAR_LEFT_FORWARD, LOW);
    analogWrite(FRONT_RIGHT_FORWARD, motorSpeed);
    analogWrite(REAR_RIGHT_FORWARD, motorSpeed);
}

// Function to turn the car right
void turnRight() {
    analogWrite(FRONT_LEFT_FORWARD, motorSpeed);
    analogWrite(REAR_LEFT_FORWARD, motorSpeed);
    digitalWrite(FRONT_RIGHT_FORWARD, LOW);
    digitalWrite(REAR_RIGHT_FORWARD, LOW);
}

// Function to stop the motors
void stopMotors() {
    digitalWrite(FRONT_LEFT_FORWARD, LOW);
    digitalWrite(FRONT_RIGHT_FORWARD, LOW);
    digitalWrite(REAR_LEFT_FORWARD, LOW);
    digitalWrite(REAR_RIGHT_FORWARD, LOW);
    digitalWrite(FRONT_LEFT_BACKWARD, LOW);
    digitalWrite(FRONT_RIGHT_BACKWARD, LOW);
    digitalWrite(REAR_LEFT_BACKWARD, LOW);
    digitalWrite(REAR_RIGHT_BACKWARD, LOW);
}

// Function to set the motor speed
void setSpeed(int speedValue) {
    motorSpeed = constrain(speedValue, 0, 1023); // Ensure speed is within valid range
    Serial.print("Speed set to: ");
    Serial.println(motorSpeed);
}

// Function to honk the horn using the same buzzer
void honkHorn() {
    for (int i = 0; i < 3; i++) { // Beep three times
        digitalWrite(BUZZER_PIN, HIGH);
        delay(200);
        digitalWrite(BUZZER_PIN, LOW);
        delay(200);
    }
}

// Function to measure distance using the ultrasonic sensor
long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2; // Convert time into distance (cm)
    return distance;
}
