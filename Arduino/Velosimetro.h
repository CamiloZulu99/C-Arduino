/*
¿Quieres saber a qué velocidad se mueve una pelota de tenis, 
tu perro o tu coche? Con un Arduino Nano y un sensor de ultrasonidos 
puedes construir este pequeño velocímetro. 
Mide la distancia de un objeto en movimiento en el intervalo 
de 1 segundo y, a continuación, calcula el movimiento del objeto
en cm/s.
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 9;
const int echoPin = 10;


long duration;
int distance1=0;
int distance2=0;
double Speed=0;
int distance=0;

void setup() 
{
lcd.begin(16, 2);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode( 7 , OUTPUT);
Serial.begin(9600); 
}


void loop() 
{


   distance1 = ultrasonicRead(); 
   
   delay(1000);
   
   distance2 = ultrasonicRead(); 
   
   
   Speed = (distance2 - distance1)/1.0; 
   
//Displaying Speed
  Serial.print("Speed in cm/s  :"); 
  Serial.println(Speed);
lcd.setCursor(0,1); 
lcd.print("Speed  cm/s ");
lcd.print(Speed); 

// LED indicator
if (distance >0 && distance <5) 
{
    digitalWrite( 7 , HIGH);
    delay(50);                  
}

if (distance > 5 && distance <10 ) 
{
    digitalWrite( 7 , HIGH);
    delay(50);                  
    digitalWrite( 7 , LOW);    
    delay(50);                  
}

if (distance >10  && distance < 20) 
{
    digitalWrite( 7 , HIGH);
    delay(210);                  
    digitalWrite( 7 , LOW);   
    delay(210);                  
}

if (distance >20  && distance < 35) 
{
    digitalWrite( 7 , HIGH);
    delay(610);                 
    digitalWrite( 7 , LOW);    
    delay(610);                 
}


}

float ultrasonicRead ()
{

digitalWrite(trigPin, LOW);
delayMicroseconds(2);


digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;


Serial.print("Distance in cm : ");
Serial.println(distance);
lcd.setCursor(0,0);
lcd.print("Dist. in cm ");
lcd.print(distance);
lcd.print("   ");
return distance;

}