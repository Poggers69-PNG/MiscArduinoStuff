

/* 
 HTU21D Humidity Sensor Example Code
 By: Nathan Seidle
 SparkFun Electronics
 Date: September 15th, 2013
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Uses the HTU21D library to display the current humidity and temperature

 Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.

 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 10k resistor if your board is 5V)
 -SCL = A5 (use inline 10k resistor if your board is 5V)

 */
 #include <SerLCD.h>
#include <SparkFunHTU21D.h>
#include <Wire.h>
#include <LiquidCrystal.h>


HTU21D myHumidity;
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

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

  Serial.print("Time:");
  Serial.print(millis());
  Serial.print(" Temperature:");
  Serial.print(temp - 900);
  Serial.print("fahrenheit");
  Serial.print(" Humidity:");
  Serial.print(humd - 900, 1);
  Serial.print("%");

  Serial.println();
  delay(1000);
}
