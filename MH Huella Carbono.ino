int pinCorriente= 34;
int pinInterruptor = 32; 
int pinRele = 25;
int pinLedInterruptor = 15;
int pinVentana = 4;
int pinLedVentana = 2;
int interruptorVal = 0;
int ventanaVal = 0;
int sensorVal = 0; 
float tension= 230.0;
float factorCoreccion= 1.8;
boolean rele_on = false;

void setup(){
Serial.begin(9600); 

pinMode(pinCorriente,INPUT);
pinMode(pinInterruptor,INPUT);
pinMode(pinVentana,INPUT);
pinMode(pinRele,OUTPUT);
pinMode(pinLedInterruptor,OUTPUT);
pinMode(pinLedVentana,OUTPUT);

digitalWrite(pinLedInterruptor,LOW);
digitalWrite(pinLedVentana,LOW);
}

void loop(){
  
  interruptorVal = analogRead(pinInterruptor);
  ventanaVal = analogRead(pinVentana); 
  
  if(interruptorVal>0){

    if(rele_on == true){
      digitalWrite(pinRele,LOW);
      digitalWrite(pinLedInterruptor,LOW);
      rele_on=false;
    }
    else if(rele_on==false){
      digitalWrite(pinRele,HIGH);
      digitalWrite(pinLedInterruptor,HIGH);
      rele_on=true;
      
    }
  }
  if(ventanaVal > 3900){
    digitalWrite(pinLedVentana,HIGH);
  }
  else {
    digitalWrite(pinLedVentana,LOW);
  }

  int sensorCorriente = analogRead(pinCorriente); 
  float voltajeSensor = analogRead(pinCorriente)* (factorCoreccion/ 4095.0);
  float corriente=voltajeSensor*10.0; 
  float P=corriente*tension; 
  Serial.print(" Sensor interruptor: "),
  Serial.print(interruptorVal);
  Serial.print(" Sensor corriente: "),
  Serial.print(sensorCorriente);
  Serial.print(" Intensidad: ");
  Serial.print(corriente,3);
  Serial.print(" A, Potencia: ");
  Serial.print(P,3);  
  Serial.println(" W");
  
  delay(2000);
  
}
