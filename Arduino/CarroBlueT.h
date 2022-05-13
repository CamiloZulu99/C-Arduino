/*
Puede parecer un proyecto exigente, pero, en realidad, no es 
excesivamente complicado de construir ni de configurar.
Una vieja caja de DVD puede servir de chasis para tu coche
teledirigido. Incorpora en ella los motores paso a paso y las ruedas,
conéctalo todo a un Arduino Uno y configura una aplicación en tu 
teléfono. ¡A conducir!
*/

char t;
 
void setup() {
pinMode(13,OUTPUT);   
pinMode(12,OUTPUT);   
pinMode(11,OUTPUT);   
pinMode(10,OUTPUT);   
pinMode(9,OUTPUT);   //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //(mover hacia una direccion)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      //(Mover reversa)
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      
  digitalWrite(11,HIGH);
}
 
else if(t == 'R'){      
  digitalWrite(13,HIGH);
}

else if(t == 'W'){    
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      //(Detiene motores )
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
