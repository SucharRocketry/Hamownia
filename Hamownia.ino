#include "HX711.h"
HX711 hamownia(3, 2); //Pin danych (DOUT), pin zegara (CLK)

void setup() {
  Serial.begin(9600);
  hamownia.set_scale(108); //Odczyt kalibracyjny (odczytana wartość przedmiotu / rzeczywista masa.
  hamownia.tare();  //Wyzerowanie belki tensometrycznej
}

void loop() {
  Serial.print((hamownia.get_units(), 1)*101,9); //Odczyt siły ciągu w newtonach
  Serial.println(" g"); //Jednostka: newtony
  
  //Serial.println(hamownia.get_units(), 1); //Odczyt siły ciągu w gramach
  //Serial.print(" N"); //Jednostka: gramy
  
  //Serial.println((hamownia.get_units(), 1)*1000); //Odczyt siły ciągu w kilogramach
  //Serial.print(" kg"); //Jednostka: kilogramy
  
}
