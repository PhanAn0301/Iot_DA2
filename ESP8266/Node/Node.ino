#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4 
#define DHTTYPE DHT11


LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  Wire.begin(D4,D3);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Do Am:");
  lcd.setCursor(0,1);
  lcd.print("Nhiet do:");
}

void loop() {
  delay(2000);
  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  if ( isnan(Humidity) || isnan(Temperature) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hic = dht.computeHeatIndex(Temperature, Humidity, false);
  lcd.setCursor(6,0);
  Serial.print(F("Humidity: "));
  Serial.print(Humidity);
  lcd.setCursor(6,0);
  lcd.print(Humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(Temperature);
  Serial.print(F("°C "));
  Serial.print(hic);
  Serial.println("");
  lcd.setCursor(9,1);
  lcd.print(Temperature);
}
