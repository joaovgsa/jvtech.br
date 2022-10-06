//Bibliotecas 
#include <SPI.h>
#include <LoRa.h>

//Definição dos pinos utilizados pelo LoRa
#define SS 30
#define RST 13
#define D0 11

int ciclo = 0;

void setup() {
  //Inicia comunicação serial
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Emissor");

  //Configura os pinos do Lora
  LoRa.setPins(SS, RST, D0);
  
  //Configurando a frequência do LoRa
  while (!LoRa.begin(915E6)) {
    Serial.println(" ... ");
    delay(500);
  }

  //Sincroniza LoRa Emissor-Receptor
  LoRa.setSyncWord(0xAA);
  Serial.println("Sincronização Completa");
}

void loop() {
  Serial.print("Emitindo Mensagem: ");
  Serial.println(ciclo);

  //Enviando a mensagem
  LoRa.beginPacket();
  LoRa.print(ciclo);
  LoRa.print("Mensagem ");
  LoRa.endPacket();
  delay(2000);

  ciclo++;
}
