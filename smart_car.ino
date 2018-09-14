int motor1CW = 6;
int motor1ACW = 7;
int motor2CW = 8;
int motor2ACW = 9;
//MOTOR 1->RIGHT
//MOTOR 2->LEFT

int stop1 = 4; //to stop the car using front IR sensor
int stop2 = 5; //to stop the  car using back IR sensor

char state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motor1CW, OUTPUT);
  pinMode(motor1ACW, OUTPUT);
  pinMode(motor2CW, OUTPUT);
  pinMode(motor2ACW, OUTPUT);

  pinMode(stop1, INPUT);
  pinMode(stop2, INPUT);
}

void Control() {
  if (Serial.available() > 0) {
    state = Serial.read();



    if (state == 'F') {
      digitalWrite(motor1CW, HIGH);
      digitalWrite(motor2CW, HIGH);  //forward
      digitalWrite(motor1ACW, LOW);
      digitalWrite(motor2ACW, LOW);

      state = 0;

    } else if (state == 'B') {
      digitalWrite(motor1CW, LOW);
      digitalWrite(motor2CW, LOW);
      digitalWrite(motor1ACW, HIGH);  //reverse
      digitalWrite(motor2ACW, HIGH);
      state = 0;

    } else if (state == 'L') {
      digitalWrite(motor1CW, HIGH);
      digitalWrite(motor2CW, LOW);
      digitalWrite(motor1ACW, LOW); //left
      digitalWrite(motor2ACW, HIGH);
      state = 0;

    } else if (state == 'R') {
      digitalWrite(motor1CW, LOW);
      digitalWrite(motor2CW, HIGH);
      digitalWrite(motor1ACW, HIGH);  //right
      digitalWrite(motor2ACW, LOW);
      state = 0;

    } else if (state == 'G') {
      digitalWrite(motor1CW, HIGH);
      digitalWrite(motor2CW, LOW);
      digitalWrite(motor1ACW, LOW);  //forward left
      digitalWrite(motor2ACW, LOW);
      state = 0;

    } else if (state == 'I') {
      digitalWrite(motor1CW, LOW);
      digitalWrite(motor2CW, HIGH);
      digitalWrite(motor1ACW, LOW);  //forward right
      digitalWrite(motor2ACW, LOW);
      state = 0;

    } else if (state == 'H') {
      digitalWrite(motor1CW, LOW);
      digitalWrite(motor2CW, LOW);
      digitalWrite(motor1ACW, HIGH);  //backleft
      digitalWrite(motor2ACW, LOW);
      state = 0;

    } else if (state == 'J') {
      digitalWrite(motor1CW, LOW);
      digitalWrite(motor2CW, LOW);
      digitalWrite(motor1ACW, LOW);
      digitalWrite(motor2ACW, HIGH);
      state = 0;

    } else if (state == '0') {
      digitalWrite(motor1CW, LOW);
      digitalWrite(motor2CW, LOW);
      digitalWrite(motor1ACW, LOW);
      digitalWrite(motor2ACW, LOW);
    }

  }
}


void loop() {
  if (stop1 == LOW && stop2 == LOW) {
    Control();
  }
  else  {

    digitalWrite(motor1CW, LOW);
    digitalWrite(motor2CW, LOW);
    digitalWrite(motor1ACW, LOW);
    digitalWrite(motor2ACW, LOW);

    Control();
  }
}

