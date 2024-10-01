#include <Servo.h>  
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

Servo S1;
Servo S2;

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int suma = 3000; 
int menu;
int buzzerPin = 10; // Pin donde está conectado el buzzer
int frecuencia = 1000; // Frecuencia del tono en Hz
int duracion = 10000; // Duración del tono en milisegundos


void setup() {
 attachInterrupt(digitalPinToInterrupt(3),alarma,FALLING);
  Serial.begin(9600);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);

   pinMode(buzzerPin, OUTPUT); 

  S1.attach(9);
   S2.attach(12);
  lcd.init();
   lcd.backlight();
   lcd.setCursor(1,0);
   lcd.print("Selecciona un "); 
   lcd.setCursor(6,1);
   lcd.print("modo");

}

void loop() {
     
if(digitalRead(4)==HIGH){
  menu = 10;
   lcd.setCursor(0,0);
   lcd.print("                  "); 
   lcd.setCursor(0,1);
   lcd.print("                  "); 
   lcd.setCursor(3,0);
   lcd.print("Automatico");  
   S1.write(90);    

  }
     if(digitalRead(2)==HIGH && menu==10){
       S2.write(0);
     delay(250);
     S2.write(80);
    S1.write(0);
    delay(suma);
    S1.write(90);
    delay(100000);
   }
  if(digitalRead(7)==HIGH){
    menu = 1;
   lcd.setCursor(0,0);
   lcd.print("                  "); 
   lcd.setCursor(0,1);
   lcd.print("                  "); 
   lcd.setCursor(4,0);
   lcd.print("Manual"); 
   lcd.setCursor(0,1); 
   lcd.print("liberar/"); 
   lcd.setCursor(8,1); 
   lcd.print("cantidad");
  }
   if(digitalRead(5)==HIGH && menu == 1 ){ 
     S2.write(0);
     delay(250);
     S2.write(80);
    S1.write(0);
    delay(suma);
    S1.write(90);
    
    }
 if(digitalRead(6)==HIGH && menu == 1 && !digitalRead(5)==HIGH ){ 
    menu = 7;
     lcd.setCursor(0,0);
   lcd.print("                  "); 
   lcd.setCursor(0,1);
   lcd.print("                  ");
   lcd.setCursor(4,0); 
   lcd.print("cantidad");
   lcd.setCursor(0,1);
   lcd.print("    1  2  3   ");
    }
 if(digitalRead(6)==HIGH && menu==7){
 suma=4000;
  
 }
  if(digitalRead(5)==HIGH && menu==7){
  suma=2000;
 }
  if(digitalRead(6)==HIGH && digitalRead(5)==HIGH ){
  suma=3000;
 }
 
} 
void alarma(){
  for(int i = 1; i<= 10; i++){ 
 tone(buzzerPin, frecuencia, duracion); 
  delay(1000); 
  }
}
