//Bibliotecas 
#include <SPI.h>
#include <LoRa.h>

//Definição dos pinos utilizados pelo LoRa
#define SS 30
#define RST 13
#define D0 11

int ciclo = 0;
int mensagem = 0;

void setup() {
  //Inicia comunicação serial
  Serial.begin(115200);

  //Configura o botão e o LED
  pinMode(10, INPUT);  //Botão
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

      //Placa é Receptor
      int packetSize = LoRa.parsePacket();
      if (packetSize) 
      {
      //Uma mensagem foi recebida
      Serial.print("Mensagem Recebida");

      //Pisca o LED
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);

      //Leitura da mensagem
      while (LoRa.available()) 
      {
        String LoRaData = LoRa.readString();
        mensagem = Serial.print(LoRaData); 
      }
      }
      delay(1000);

      if (mensagem == Serial.print(ciclo))
      {
        //Placa é Emissor
        Serial.print("Emitindo Mensagem: ");
  
        //Pisca o LED
        digitalWrite(2, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        
        //Enviando a mensagem
        LoRa.beginPacket();
        LoRa.print(ciclo);
        LoRa.print("OK");
        LoRa.endPacket();
        delay(2000);
        ciclo ++;
      }    
      else
      {
        //Pisca o LED
        digitalWrite(2, HIGH);
        delay(5000);
        digitalWrite(2, LOW);
      }
      delay (2000);
}
