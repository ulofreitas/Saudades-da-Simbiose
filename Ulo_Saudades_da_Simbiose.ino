#include "SR04.h"

//Defining LED Pins
#define RED 6
#define GREEN 5
#define BLUE 3

//Defining Ultrasonic Sensor Pins
#define TRIG_PIN 12
#define ECHO_PIN 11
#define max_distance 400

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;
long d;

void setup() {
    Serial.begin(9600); //Initialization of Serial Port
    delay(1000);
    
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

void loop() {
    distance = sr04.Distance();
    d = distance;
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println("cm");
    
    long redValue1 = 2 * d + 20;
    long greenValue1 = 0;
    long blueValue1 = (-1) * (1 * d - 210);
    
    long redValue2 = 0;
    long greenValue2 = 0.1 * d + 20;
    long blueValue2 = 0.1 * d + 20;
    
    long redValue3 = 0;
    long greenValue3 = 0.03 * d + 20;
    long blueValue3 = 0.01 * d + 10;
    
    if (distance > 0 && 21 > distance) {
        analogWrite(6, redValue1 + 20 * sin(millis() / 200));
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("redValue = ");
        Serial.println(redValue1);
        Serial.println(" ");
        
        analogWrite(5, greenValue1);
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("greenValue = ");
        Serial.println(greenValue1);
        Serial.println(" ");
        
        analogWrite(3, blueValue1 + 20 * sin(millis() / 200));
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("blueValue = ");
        Serial.println(blueValue1);
        Serial.println(" ");
    } else if (distance >= 21 && 400 > distance) {
        analogWrite(6, redValue2 + 1 * sin(millis() / 40));
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("redValue = ");
        Serial.println(redValue2);
        Serial.println(" ");
        
        analogWrite(5, greenValue2 + 10 * sin(millis() / 20) );
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("greenValue = ");
        Serial.println(greenValue2);
        Serial.println(" ");
        
        analogWrite(3, blueValue2 + 10 * sin(millis() / 20) );
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("blueValue = ");
        Serial.println(blueValue2);
        Serial.println(" ");
    } else if (distance >= 400 && 1300 > distance) {
        analogWrite(6, redValue3);
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("redValue = ");
        Serial.println(redValue3);
        Serial.println(" ");
        
        analogWrite(5, greenValue3 + 10 * sin(millis() / 100) );
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("greenValue = ");
        Serial.println(greenValue3);
        Serial.println(" ");
        
        analogWrite(3, blueValue3 - 10 * sin(millis() / 100) );
        Serial.print("d = ");
        Serial.println(d);
        Serial.print("blueValue = ");
        Serial.println(blueValue3);
        Serial.println(" ");
    }
    
}
