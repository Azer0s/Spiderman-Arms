#include <Servo.h>
Servo motor;
const int buttonPin = 7; 
bool toggle = false;
int pos = 0;

void setup() {
	pinMode(buttonPin, INPUT);
	Serial.begin(9600);
	motor.attach(4,750,2245);
}

void loop() {
	if (digitalRead(buttonPin) == HIGH) {
		delay(500);
		if(toggle){
			Serial.println("turn");
			for (pos = 0; pos <= 180; pos += 1) {
				motor.write(pos);
				delay(1);
			}
		}else{
			Serial.println("rev");
			for (pos = 180; pos >= 0; pos -= 1) {
				motor.write(pos);
				delay(1); 
			}
		}

		Serial.println(pos);
		toggle = !toggle;
	}
}
