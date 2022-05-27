// Arduino(Embedded) C code for the project
// Pin 4, 5, 6, 7 -> Relay output.
// Pin A2, A3, A4, A5 -> Analog input value from the LDR's.
// Analog value less than 700 implies it Black tile. 
// NOTE: Its is to be caliberated based on ambient intensity
// and screen brightness.
void setup()
{
 pinMode(4,OUTPUT);
 digitalWrite(4,LOW); 
 pinMode(5,OUTPUT);
 digitalWrite(5,LOW); 
 pinMode(6,OUTPUT);
 digitalWrite(6,LOW); 
 pinMode(7,OUTPUT);
 digitalWrite(7,LOW); 
 Serial.begin(9600);
}
int delay1 = 80;
int delay2 = 75;
int count =0;
int sensorPin2=A2;
int sensorPin3=A3;
int sensorPin4=A4;
int sensorPin5=A5;
int sensorValue = 0;
void loop()
{ 
  
   sensorValue = analogRead(sensorPin2); // read the value from the sensor
  Serial.println(sensorValue); 
   sensorValue = analogRead(sensorPin3); // read the value from the sensor
  Serial.println(sensorValue); 
   sensorValue = analogRead(sensorPin4); // read the value from the sensor
  Serial.println(sensorValue); 
  sensorValue = analogRead(sensorPin5); // read the value from the sensor
  Serial.println(sensorValue); 

 count = count +1;
 if(count==25)
 {
   delay1 = 70;
   delay2 = 75;
 }
 if(analogRead(A5)<700)   
 {
   digitalWrite(4, HIGH);
   delay(delay2);
   digitalWrite(4, LOW);
   delay(delay1);
 }
 else if(analogRead(A4)<700)
 {
   digitalWrite(5, HIGH);
   delay(delay2);
   digitalWrite(5, LOW);
   delay(delay1);
 }
 else if(analogRead(A3)<700)
 {
   digitalWrite(6, HIGH);
   delay(delay2);
   digitalWrite(6, LOW);
   delay(delay1);
 }
 else if(analogRead(A2)<700)
 {
   digitalWrite(7, HIGH);
   delay(delay2);
   digitalWrite(7, LOW);
   delay(delay1);
 }
 delay(10);    // delay for stability
}
