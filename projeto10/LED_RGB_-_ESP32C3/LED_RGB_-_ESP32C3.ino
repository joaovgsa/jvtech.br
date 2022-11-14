#define PIN 8       //Define o pino que o LED RGB está
#define NUMPIXELS 1 //Quantidade de Pixel do led
#include <Adafruit_NeoPixel.h> //Biblioteca do LED NeoPixel

//Inicializando o LED RGB da Placa
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(9, INPUT);    //Configurando o botão da placa
  pixels.begin();       //Configurando o LED RGB 
}

int a=255, b=0, c=0;

void loop() {
    //Determina a cor do LED
    pixels.setPixelColor(1, pixels.Color(a, b, c));
    //Liga o LED
    pixels.show();

    //Quando o botão for pressionado
    if(digitalRead(9)==1){
      if(a==255){ //Se a cor tiver vermelho, mudar para verde
        a=0;
        b=255;
        c=0;
      }
      else if(b==255){ //Se a cor tiver verde, mudar para azul 
        a=0;
        b=0;
        c=255;
      }
      else if(c==255){ //Se a cor tiver azul, mudar para vermelho
        a=255;
        b=0;
        c=0;
      }
    }

    delay(1000); //Espera de 1 segundo
}
