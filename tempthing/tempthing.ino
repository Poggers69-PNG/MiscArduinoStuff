#include <SerLCD.h>
#include <SparkFunHTU21D.h>
#include <Wire.h>
#include <LiquidCrystal.h>


HTU21D myHumidity;
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  Serial.println("Example of temperature monitoring using the HTU21D: ");
 lcd.begin(16, 2);
  myHumidity.begin();
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();


  lcd.setCursor(0,1);
  Serial.println("Time:   ");
 Serial.println(millis());
  Serial.println("Temperature:");
Serial.println(temp - 900);
  Serial.println("fahrenheit");
  Serial.println(" Humidity: ");
  Serial.println(humd - 900, 1);
  Serial.println("%");

  Serial.println();
  delay(1000);
}
