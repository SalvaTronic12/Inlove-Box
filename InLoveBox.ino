#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2); // configuración de la pantalla - Direcciones (0x3f,16,2) ||(0x20,16,2) 

const byte FILAS = 4;
const byte COLUMNAS = 4;

char fechaClave[8] = {'1','2','0','1','2','0','0','1'};
char fechaIngresada[8];
int contador = 0;
int pos = 3;
int verificador = 0;
String frase[3] = {"TE AMO", "TE ADORO", "HERMOSA"};
Servo servo;
Servo servo1;
int contador1 = 65;
int contador2 = 70;
long numero;








char matriz[FILAS][COLUMNAS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte pinesFilas[FILAS] = {9,8,7,6};
byte pinesColumnas[COLUMNAS] = {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(matriz),pinesFilas,pinesColumnas,FILAS,COLUMNAS);

char Tecla;



void setup() {
 Serial.begin(9600);
lcd.init(); // inicializar pantalla
lcd.backlight(); //luz de fondo
lcd.clear();
servo.attach(11);
servo1.attach(12);

servo.write(70);// inicio
servo1.write(65);//inicio
randomSeed(analogRead(A1));


}

void loop() {

numero = random(1,3);

lcd.setCursor(0,0);
lcd.print("Ingresa la fecha");
lcd.setCursor(5,1);
lcd.print("/");
lcd.setCursor(8,1);
lcd.print("/");



Tecla = teclado.getKey();

if(Tecla){


if(pos < 5){
fechaIngresada[contador] = Tecla;
contador++;
lcd.setCursor(pos,1);
lcd.print(Tecla);
pos++;
}
else if(pos > 4 && pos < 7){
fechaIngresada[contador] = Tecla;
contador++;
 pos++;
 lcd.setCursor(pos,1);
 lcd.print(Tecla);
 if( pos == 7){
  pos++;
 }
}
else if(pos > 6  && pos <12){
fechaIngresada[contador] = Tecla;
contador++;
 pos++;
 lcd.setCursor(pos,1);
 lcd.print(Tecla);

}



}


if(contador == 8){
  delay(800);
  
  for(int i =0; i<8;i++){
    if(fechaClave[i]!=fechaIngresada[i]){
      verificador = 1;
    }
    }
    
      if(verificador == 1){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Todos cometemos");
     lcd.setCursor(4,1);
     lcd.print("errores");
     
     delay(3000);
     lcd.clear();
     lcd.setCursor(2,0);
     lcd.print("Tienes otra");
     lcd.setCursor(2,1);
     lcd.print("oportunidad");
     delay(3000);
     
     lcd.clear();
     
     contador = 0;
     pos=3;
     verificador =0;

     
  }
  else{
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print(frase[numero]);
    delay(4000);
    
    
    while(contador1 != -1 && contador2 != 141){
  contador1--;
  contador2++;
  servo.write(contador1);
  servo1.write(contador2);
  delay(55);
}
delay(8000);

while(contador1 != 71 && contador2 != 64){
  contador1++;
  contador2--;
  servo.write(contador1);
  servo1.write(contador2);
  delay(55);
}
delay(2000);
    contador = 0;
    pos=3;
 lcd.clear();
  }
}


  
}
