#define soilPin1 A0
#define soilPin2 A1
#define soilPin3 A2
#define soilPin4 A3
#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

void setup() {
  Serial.begin(9600);
  pinMode(soilPin1, INPUT);
  pinMode(soilPin2, INPUT);
  pinMode(soilPin3, INPUT);
  pinMode(soilPin4, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int val1 = analogRead(soilPin1);
  int val2 = analogRead(soilPin2);
  int val3 = analogRead(soilPin3);
  int val4 = analogRead(soilPin4);
  Serial.print("SoilSensor 1 =  ");
  Serial.print(val1);
  Serial.print("  ");
  Serial.print("SoilSensor 2 =  ");
  Serial.print(val2);
  Serial.print("  ");
  Serial.print("SoilSensor 3 =  ");
  Serial.print(val3);
  Serial.print("  ");
  Serial.print("SoilSensor 4 =  ");
  Serial.println(val4);
  if(val1 < 420){
    digitalWrite(IN1, HIGH);
  }else{
    digitalWrite(IN1, LOW);
  }
  if(val2 < 420){
    digitalWrite(IN2, HIGH);
  }else{
    digitalWrite(IN2, LOW);
  }
  if(val3 < 420){
    digitalWrite(IN3, HIGH);
  }else{
    digitalWrite(IN3, LOW);
  }
  if(val4 < 420){
    digitalWrite(IN4, HIGH);
  }else{
    digitalWrite(IN4, LOW);
  }
}
