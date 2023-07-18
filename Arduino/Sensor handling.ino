#include <TimeLib.h>
#include <Wire.h>
#include <VL53L0X.h>

#define PIRsensor 10
#define trigPin 11
#define echoPin 12
#define buttonPin 13

VL53L0X sensor;

void setup() {
  // Ustawienie PINow i ustanowienie polaczenia szeregowego
  pinMode(PIRsensor, INPUT); // Set PIR sensor pin as input
  pinMode(trigPin, OUTPUT); // Set trigger pin as output for the hypersonic sensor
  pinMode(echoPin, INPUT); // Set echo pin as input for the hypersonic sensor
  pinMode(buttonPin, INPUT); // Set button pin as input
  Serial.begin(9600); // Initialize serial communication at 9600 baud
}

void loop() {
  int PIRsensor_value = 0;
  long time, distance;
  // Odczytanie stanu przycisku
  int buttonState = digitalRead(buttonPin); // Read the state of the button

  if (Serial.available() > 0) {
    // Odczytanie czasu przez polaczenie szeregowe
    // Read the time from the serial port
    String received_time = Serial.readStringUntil('\n');

    // Podzial otrzymanego czasu na godziny, minuty, sekundy
    // Parse the received time into hour, minute, and second values
    int hour = received_time.substring(0, 2).toInt();
    int minute = received_time.substring(3, 5).toInt();
    int second = received_time.substring(6, 8).toInt();

    // Ustawienie czasu Arduino
    // Set the internal time of Arduino
    setTime(hour, minute, second, 1, 1, 2023);

    // Koniec odczytu z portu szeregowego
    // End reading from the serial port
    Serial.flush();
  }

  Serial.println("Arduino is running");

  if (buttonState == LOW) {
    Serial.println("Measurement started");
    delay(1000);
    Serial.print("Start time: ");
    Serial.print(hour());
    Serial.print(":");
    Serial.print(minute());
    Serial.print(":");
    Serial.println(second());

    // Pomiar przez czujnik hipersoniczny
    // Hypersonic sensor measurement
    for (int i = 0; i < 100; i++) {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
 
      time = pulseIn(echoPin, HIGH);
      distance = (time / 58) * 10;
  
      Serial.print(distance);
      Serial.println(" mm (Hypersonic sensor)");
    }

    // Pomiar przez czujnik ToF
    // VL53L0X sensor measurement
    for (int i = 0; i < 100; i++) {
      Wire.begin();
      sensor.init();
      sensor.setTimeout(1500);
      while (!Serial);
      Serial.print(sensor.readRangeSingleMillimeters());
      Serial.println(" mm (ToF sensor)");
    }

    Serial.print("End time: ");
    Serial.print(hour());
    Serial.print(":");
    Serial.print(minute());
    Serial.print(":");
    Serial.println(second());
  }

  delay(500);
}
