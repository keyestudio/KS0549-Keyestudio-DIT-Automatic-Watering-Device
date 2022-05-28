#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define soilPin1 A0
#define soilPin2 A1
#define soilPin3 A2
#define soilPin4 A3
#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

int count, count_flag;

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}


void loop()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  int val1 = analogRead(soilPin1);
  int val2 = analogRead(soilPin2);
  int val3 = analogRead(soilPin3);
  int val4 = analogRead(soilPin4);
  lcd.setCursor(0,0);
  lcd.print("S1:");
  lcd.setCursor(3,0);
  lcd.print(val1);
  lcd.setCursor(7,0);
  lcd.print(" ");
  lcd.setCursor(9,0);
  lcd.print("S2:");
  lcd.setCursor(12,0);
  lcd.print(val2);

  lcd.setCursor(0,1);
  lcd.print("S3:");
  lcd.setCursor(3,1);
  lcd.print(val3);
  lcd.setCursor(7,1);
  lcd.print(" ");
  lcd.setCursor(9,1);
  lcd.print("S4:");
  lcd.setCursor(12,1);
  lcd.print(val4);
  delay(200);
  count = count + 1;
  if(count >= 50)  //After 10 seconds, turn off the lCD1602 backlight
  {
    count = 50;
    lcd.noBacklight();
  }
  if(val1 < 420){
    lcd.backlight();
    count = 0;
    digitalWrite(IN1, HIGH);  // Water pump 1
    delay(3000);              //Pumping time is 3 seconds
    digitalWrite(IN1, LOW);   // Shut down the pump
    delay(5000);              //Water penetration time 5 seconds
  }else{
    digitalWrite(IN1, LOW);
  }
  if(val2 < 420){
    lcd.backlight();
    count = 0;
    digitalWrite(IN2, HIGH);
    delay(3000);
    digitalWrite(IN2, LOW);
    delay(5000);
  }else{
    digitalWrite(IN2, LOW);
  }
  if(val3 < 420){
    lcd.backlight();
    count = 0;
    digitalWrite(IN3, HIGH);
    delay(3000);
    digitalWrite(IN3, LOW);
    delay(5000);
  }else{
    digitalWrite(IN3, LOW);
  }
  if(val4 < 420){
    lcd.backlight();
    count = 0;
    digitalWrite(IN4, HIGH);
    delay(3000);
    digitalWrite(IN4, LOW);
    delay(5000);
  }else{
    digitalWrite(IN4, LOW);
  }
}
