const int MOTOR_A = 12;
const int MOTOR_B = 13;

int diff = 60;
int pwmB = 20;
int pwmA = pwmB + diff;


void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);

  for (int i=0; i <= 255; i++){
    analogWrite(MOTOR_A, i);
    analogWrite(MOTOR_B, i);
    delay(5);
  }
  
}

void loop() {

  analogWrite(MOTOR_A, pwmA);
  analogWrite(MOTOR_B, pwmB);

}
