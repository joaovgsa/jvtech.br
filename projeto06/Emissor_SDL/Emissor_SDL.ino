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

  //Configura o LED e o sensor
  pinMode(2, OUTPUT); //LED
  pinMode(A2, INPUT); //Sensor de Luminosidade

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

    if (analogRead(A2)>=600) //Se o sensor perceber alta claridade
    {
      Serial.print("Emitindo Mensagem: ");

      //Liga o LED
      digitalWrite(2, HIGH);

      //Enviando a mensagem
      LoRa.beginPacket();
      LoRa.print("Alta Luminosidade Percebida");
      LoRa.endPacket();
      delay(2000);

      //Desliga o LED
      digitalWrite(2, LOW);
    }
    else if (analogRead(A2)>=100)
    {
      Serial.print("Emitindo Mensagem: ");

      //Liga o LED
      digitalWrite(2, HIGH);

      //Enviando a mensagem
      LoRa.beginPacket();
      LoRa.print("Alta Luminosidade Percebida");
      LoRa.endPacket();
      delay(2000);

      //Desliga o LED
      digitalWrite(2, LOW);
    }

    delay(1000);
}
