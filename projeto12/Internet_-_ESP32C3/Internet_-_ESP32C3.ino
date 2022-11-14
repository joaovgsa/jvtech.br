//Biblioteca Própria do Arduino IDE
#include <WiFi.h>

//Nome e senha da rede entre aspas ""
const char* rede = "nome_da_rede";
const char* senha = "senha";

void setup() 
{
 //Iniciando a comunicação serial
 Serial.begin(115200);

 //Configurando a rede e senha
 WiFi.begin(rede, senha);

 //Aguardando o ESP32 conectar a internet
 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Conectando ...");
 }
 
 //ESP32 está conectado a internet corretamente
 Serial.println("Conexão Completa");
}

void loop()
{
}
