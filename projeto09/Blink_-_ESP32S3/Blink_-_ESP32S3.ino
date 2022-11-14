void setup() {
  //Inicializando o LED da placa
  pinMode(48, OUTPUT);
}

void loop() {
  digitalWrite(48, HIGH);   //Liga o LED
  delay(1000);              //Espera de 1 segundo
  digitalWrite(48, LOW);    //Desliga o LED
  delay(1000);              //Espera de 1 segundo
}
