//Bibliotecas 
#include <SPI.h>
#include <LoRa.h>

//Definição dos pinos utilizados pelo LoRa
#define SS 30
#define RST 13
#define D0 11

void setup() {
  //Inicia comunicação serial
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receptor");

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
  //Analisa transmissões
  int packetSize = LoRa.parsePacket();
  if (packetSize) {

    //Uma mensagem foi recebida
    Serial.print("Mensagem Recebida");

    //Leitura da mensagem
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 
    }

    //Mostra o RSSI da mensagem
    Serial.print(" com RSSI: ");
    Serial.println(LoRa.packetRssi());
  }
}
