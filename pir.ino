int calibrationTime=30;
long unsigned int lowln;
long unsigned int pause=5000;
boolean lockLow=true;
boolean takeLowTime;
int pirPin=8;
int ledPin=12;
void setup()
{
   Serial.begin(9600);
   pinMode(pirPin,INPUT);
   pinMode(ledPin,OUTPUT);
   digitalWrite(pirPin,LOW);
   Serial.print("calibrating sensor");
   for(int i=0; i<calibrationTime; i++)
   {
     Serial.print(".");
     delay(1000);
     
   }
   Serial.println("done");
   Serial.println("Sensor active");
   delay(50);
}


void loop()
{
  if(digitalRead(pirPin)==HIGH)
  {
     digitalWrite(ledPin,HIGH);
     if(lockLow)
     {
         lockLow=false;
         Serial.print("--");
         Serial.print("Motion Detected at,");
         Serial.print(millis()/1000);
         Serial.print("Sec");
         delay(50);
     }
     takeLowTime=true;
     
  }
  if(digitalRead(pirPin)==LOW)
  {
    digitalWrite(ledPin,LOW);
    if(takeLowTime)
    {
      lowln==millis();
      takeLowTime=false;
      
    }
    if(!lockLow && millis()-lowln>pause)
    {
      lockLow=true;
      Serial.print("Motion end");
      Serial.print((millis()-pause)/1000);
      Serial.print("sec");
      delay(50);
      
    }
  }
}

