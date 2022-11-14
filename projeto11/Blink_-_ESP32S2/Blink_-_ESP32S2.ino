void setup() {
  //Inicializando o LED da placa
  pinMode(18, OUTPUT);
}

void loop() {
  digitalWrite(18, HIGH);   //Liga o LED
  delay(1000);              //Espera de 1 segundo
  digitalWrite(18, LOW);    //Desliga o LED
  delay(1000);              //Espera de 1 segundo
}
