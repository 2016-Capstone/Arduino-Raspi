#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);
int randNumber;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  // lcd
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear(); // 화면 clear
  
  Serial.begin(9600);
  
  randomSeed(analogRead(1000)); // rnadom 값 첫 초기 값 1000이상
  lcd.setCursor(0,0); // 커서를 0, 0에 위치
  lcd.print("Hello world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Random = ");
  lcd.setCursor(0,1);
  lcd.print("Random : ");
  lcd.setCursor(8,1); // 1, 8에 글 쓰기 시작
  randNumber = random(1000, 9999); // 1000~9999까지
  
  Serial.println(randNumber); // 시리얼 모니터에 출력
  lcd.print(randNumber); // lcd에 출력
  delay(10000);
}
