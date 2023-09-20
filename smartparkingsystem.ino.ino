#include <Servo.h>
#define ENTRANCE_SERVO_PIN 9
#define EXIT_SERVO_PIN 10
#define IR_SENSOR_1 2
#define IR_SENSOR_2 3
#define IR_SENSOR_3 4
#define IR_SENSOR_4 5
#define RED_LED_PIN 6
#define GREEN_LED_PIN 7
#define CLOUD_ENABLED true // Set this to false if not using cloud integration

Servo entranceGateServo;
Servo exitGateServo;

void setup() {
  Serial.begin(9600);
  entranceGateServo.attach(ENTRANCE_SERVO_PIN);
  exitGateServo.attach(EXIT_SERVO_PIN);
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(IR_SENSOR_3, INPUT);
  pinMode(IR_SENSOR_4, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  if (CLOUD_ENABLED) {
    // Initialize cloud connection here
    // Example: Initialize WiFi and connect to cloud server
  }
}

void loop() {
  bool slot1 = digitalRead(IR_SENSOR_1);
  bool slot2 = digitalRead(IR_SENSOR_2);
  bool slot3 = digitalRead(IR_SENSOR_3);
  bool slot4 = digitalRead(IR_SENSOR_4);

  // Check if any slot is occupied and set LED accordingly
  if (slot1 || slot2 || slot3 || slot4) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }

  // Check if all slots are filled and display at the entrance
  if (slot1 && slot2 && slot3 && slot4) {
    entranceGateServo.write(90); // Close entrance gate
    // If cloud is enabled, send data to the cloud
    if (CLOUD_ENABLED) {
      // Send status data to the cloud
    }
  } else {
    entranceGateServo.write(0); // Open entrance gate
  }

  // Additional cloud integration code can be added here
  if (CLOUD_ENABLED) {
    // Check for cloud commands or update status
    // Example: Listen for cloud commands to open or close exit gate
  }

  // Add a delay to prevent rapid sensor readings
  delay(1000);
}

