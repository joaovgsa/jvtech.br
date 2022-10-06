//Bibliotecas 
#include <SPI.h>
#include <LoRa.h>

//Definição dos pinos utilizados pelo LoRa
#define SS 30
#define RST 13
#define D0 11
#define pinoSensor 22

void setup() {
  //Inicia comunicação serial
  Serial.begin(115200);

  //Configura o sensor e o LED
  pinMode(pinoSensor, INPUT); //Sensor de Vibração
  pinMode(2, OUTPUT); //LED

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

    if (digitalRead(22)==0) //Se o sensor perceber vibração
    {
      Serial.print("Emitindo Mensagem: ");

      //Liga o LED
      digitalWrite(2, HIGH);

      //Enviando a mensagem
      LoRa.beginPacket();
      LoRa.print("Vibração Percebida");
      LoRa.endPacket();
      delay(2000);

      //Desliga o LED
      digitalWrite(2, LOW);
    }

    delay(1000);
}
