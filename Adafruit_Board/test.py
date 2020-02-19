#with reference to https://learn.adafruit.com/adafruit-16-channel-servo-driver-with-raspberry-pi/using-the-adafruit-library

from adafruit_servokit import ServoKit
kit = ServoKit(channels=16)

motor_angle = 120

kit.servo[0].angle = motor_angle
kit.servo[1].angle = motor_angle
kit.servo[2].angle = motor_angle
kit.servo[3].angle = motor_angle
kit.servo[4].angle = motor_angle
kit.servo[5].angle = motor_angle
