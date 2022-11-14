//Biblioteca Própria do Arduino IDE
#include "BluetoothSerial.h"

//Configuração do Bluetooth
BluetoothSerial SerialBT;

void setup()
{
  //Inicia a comunicação serial
  Serial.begin(9600);
  //Define o nome do ESP32
  SerialBT.begin("Nome");
}

void loop() 
{
  //Verifica se a serial está disponível
  if (Serial.available()) 
  {
    //Faz a leitura do que foi enviado
    SerialBT.write(Serial.read());
  }

  //Se está realmente disponível
  if (SerialBT.available()) 
  {
      SerialBT.println("Funcionando");
  }
}
