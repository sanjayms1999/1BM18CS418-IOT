#include <Servo.h>
Servo anyserve;
int pos=0;
int sensorpin=A0;
int sensorvalue=0;
void setup()
{
  anyserve.attach(9);
  Serial.begin(9600);
}
void loop()
{
  sensorvalue=analogRead(sensorpin);
  Serial.begin(sensorvalue);
  if(sensorvalue>300)
  {
    for (pos=0;pos<180;pos+=1)
    {
    anyserve.write(pos);
   delay(20); 
    }
     for (pos=180;pos>=0;pos-=1){
     anyserve.write(pos);
     delay(20);
  }
}

}

