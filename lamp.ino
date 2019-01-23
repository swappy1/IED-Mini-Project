#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;
SoftwareSerial mySerial(10,11); 
int ledpin=13;
int Data;
int flag=0;
int Sensorvalue; 
int soundpin=4;
int soundval=LOW;
boolean ledstatus=false;
int angle=0;

void setup() 
{
  mySerial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(soundpin,INPUT);
  myservo.attach(9); 
}

void loop()
{
  //Read on Bluetooth
  if (mySerial.available()>0)
  {
    Data=mySerial.read();
    flag=0;
  }
  
   soundval=digitalRead(soundpin);
  
   if(soundval==1)
   {  
    if(ledstatus==false)
   {
      ledstatus=true;
      digitalWrite(8,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
   }
    else if(ledstatus==0)
    {
      ledstatus=false;
      digitalWrite(8,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
      
    }
    
   if(Data=='1')
    {  
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      digitalWrite(8,LOW);
      flag=1;
    }
    
    else if (Data=='0')
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(8,LOW);
      flag=1;
    }
    else if(Data =='2')
    {//disco mode
      digitalWrite(8,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      delay(500);
      digitalWrite(12,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(13,LOW);
      delay(500);
      digitalWrite(13,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(12,LOW);
      delay(500);
      flag=1;
      
      for (angle = 0;angle < 180;angle += 10)
      {
      myservo.write(angle);        
      delay(2000);                   
      }
      for (angle= 180;angle>= 0; angle -= 10)
      {
      myservo.write(angle);              
      delay(2000);                       
      }
    }

    else if(Data=='3')
    {
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(8,LOW);
      flag=1;
    }
   
}
