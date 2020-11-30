#define DEBUG(a) Serial.println(a);
#include <Wire.h>

String data = "";
int cont = 0; //variable de conteo

void setup()
{
  Wire.begin(); //inicio de comunicación i2c
  Serial.begin(9600);
  Serial.println("Master");
}

void loop()
{
  while (Serial.available())
  {
    char character = Serial.read();
    if (character != 13 )
    {
      data.concat(character);
      
    }
    else
    {
      
      Wire.beginTransmission(4); // configuración de esclavo a enviar
      Wire.write("data");  // envio de mensaje
      Wire.endTransmission(); // fin de comunicación
      Serial.println("Mensaje Enviado");
      delay(1000); // espera
      data = "";
    }
  }
}
