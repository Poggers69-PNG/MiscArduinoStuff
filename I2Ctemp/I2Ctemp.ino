#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);

float Voltage = 0.0;

int thermistor_25 = 10000;

float refCurrent = 0.0001;

void setup(void) {

Serial.begin(9600);

ads.begin();

}

void loop(void) {

int16_t adc0; 

adc0 = ads.readADC_SingleEnded(0); // Read ADC value from ADS1115

Voltage = adc0 * (5.0 / 65535); // Replace 5.0 with whatever the actual Vcc of your Arduino is

float resistance = (Voltage / refCurrent); // Using Ohm's Law to calculate resistance of thermistor

float ln = log(resistance / thermistor_25); // Log of the ratio of thermistor resistance and resistance at 25 deg. C

float kelvin = 1 / (0.0033540170 + (0.00025617244 * ln) + (0.0000021400943 * ln * ln) + (-0.000000072405219 * ln * ln * ln)); // Using the Steinhart-Hart Thermistor Equation to calculate temp in K

float temp = kelvin -457.87; // Converting Kelvin to fahrenheit

Serial.print("AIN0: "); // Print ADC value to Serial Monitor

Serial.print(adc0);

Serial.print("\tand the temperature is equal to: "); // Print temperature to Serial Monitor in fahrenheit

Serial.println(temp, 7);

Serial.println();

delay(510); // Change how often the sketch outputs reading

}
