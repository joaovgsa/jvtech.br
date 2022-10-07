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

  //Configura o LED e o botão
  pinMode(2, OUTPUT); //LED
  pinMode(10, INPUT); //Botão

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

    if (digitalRead(10)==1) //Se o botão for pressionado
    {
      Serial.print("Emitindo Mensagem: ");

      //Liga o LED
      digitalWrite(2, HIGH);

      //Enviando a mensagem
      LoRa.beginPacket();
      LoRa.print("Alterar Relé");
      LoRa.endPacket();
      delay(2000);

      //Desliga o LED
      digitalWrite(2, LOW);
    }

    delay(1000);
}
