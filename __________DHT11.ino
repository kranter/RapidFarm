#include "DHT.h"
#define DHTPIN 2 // Номер пина вывода показаний
DHT dht(DHTPIN, DHT11); //инициализация датчика
void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  delay(2000); 
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  if (isnan(h) || isnan(t)) {  // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
    Serial.println("Ошибка считывания");
    return;
  }
  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println(" *C "); //Вывод показателей на экран
}
