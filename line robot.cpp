// Line Following Robot - 2 IR sensors + L298N

const int leftSensor  = 2;
const int rightSensor = 3;

const int leftMotorF  = 5;   // IN1
const int leftMotorB  = 6;   // IN2
const int rightMotorF = 9;   // IN3
const int rightMotorB = 10;  // IN4

const int speedVal = 150;    // 0-255, lower = slower and easier to control

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(leftMotorF, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorF, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
}

void loop() {
  int left  = digitalRead(leftSensor);   // 1 = black line, 0 = white
  int right = digitalRead(rightSensor);

  if (left == 0 && right == 0) {
    moveForward();            // line is between the sensors
  }
  else if (left == 1 && right == 0) {
    turnLeft();               // line drifted to the left
  }
  else if (left == 0 && right == 1) {
    turnRight();              // line drifted to the right
  }
  else {
    stopRobot();              // both on black (junction) or lost
  }
}

void moveForward() {
  analogWrite(leftMotorF, speedVal);
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, speedVal);
  analogWrite(rightMotorB, 0);
}

void turnLeft() {
  analogWrite(leftMotorF, 0);          // left motor stops
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, speedVal);  // right motor drives
  analogWrite(rightMotorB, 0);
}

void turnRight() {
  analogWrite(leftMotorF, speedVal);
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, 0);
  analogWrite(rightMotorB, 0);
}

void stopRobot() {
  analogWrite(leftMotorF, 0);
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, 0);
  analogWrite(rightMotorB, 0);
}