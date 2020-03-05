#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN_1  105
#define SERVOMAX_1  600

#define SERVOMIN_2  100
#define SERVOMAX_2  600

#define SERVOMIN_3  140
#define SERVOMAX_3  600

#define SERVOMIN_4  140
#define SERVOMAX_4  650

#define SERVOMIN_5  140
#define SERVOMAX_5  650

#define SERVOMIN_6  140
#define SERVOMAX_6  650

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  Serial.println("Serial ON");
}

int angles[6];

void loop() {
  while (Serial.available() < 6) {} // Wait 'till there are 9 Bytes waiting
  Serial.println("Bytes:");
  for (int n = 0; n < 6; n++)
  {
    angles[n] = Serial.parseInt(); // Then: Get them.
    Serial.println(angles[n]);
  }
  pwm.setPWM(0, 0, angleToPulse(angles[0], 1));
  pwm.setPWM(1, 0, angleToPulse(angles[1], 2));
  pwm.setPWM(2, 0, angleToPulse(angles[2], 3));
  pwm.setPWM(3, 0, angleToPulse(angles[3], 4));
  pwm.setPWM(4, 0, angleToPulse(angles[4], 5));
  pwm.setPWM(5, 0, angleToPulse(angles[5], 6));

//  pwm.setPWM(2, 0, angleToPulse(0, 3));
//  delay(1000);
//  pwm.setPWM(2, 0, angleToPulse(180, 3));
//  delay(1000);


}

int angleToPulse(int ang, int motor_select) {
  int pulse = 0;
  switch (motor_select) {
    case 1:
      pulse = map(ang, 0, 180, SERVOMIN_1, SERVOMAX_1); // map angle of 0 to 180 to Servo min and Servo max
      Serial.print("Motor 1 selected. Angle: ");
      break;
    case 2:
      pulse = map(ang, 0, 180, SERVOMIN_2, SERVOMAX_2); // map angle of 0 to 180 to Servo min and Servo max
      Serial.print("Motor 2 selected. Angle: ");
      break;
    case 3:
      pulse = map(ang, 0, 180, SERVOMIN_3, SERVOMAX_3); // map angle of 0 to 180 to Servo min and Servo max
      Serial.print("Motor 3 selected. Angle: ");
      break;
    case 4:
      pulse = map(ang, 0, 180, SERVOMIN_4, SERVOMAX_4); // map angle of 0 to 180 to Servo min and Servo max
      Serial.print("Motor 4 selected. Angle: ");
      break;
    case 5:
      pulse = map(ang, 0, 180, SERVOMIN_5, SERVOMAX_5); // map angle of 0 to 180 to Servo min and Servo max
      Serial.print("Motor 5 selected. Angle: ");
      break;
    case 6:
      pulse = map(ang, 0, 180, SERVOMIN_6, SERVOMAX_6); // map angle of 0 to 180 to Servo min and Servo max
      Serial.print("Motor 6 selected. Angle: ");
      break;
    default:
      Serial.print("Default selected. Angle: ");
      break;
  }
  Serial.println(ang);
  return pulse;
}
