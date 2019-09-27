const int s0=8;
const int s1=9;
const int s2=12;
const int s3=11;
const int out=10;
int redled=2;
int greenled=3;
int blueled=4;
int red=0;
int green=0;
int blue=0;
void setup()
{
  Serial.begin(9600);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(blueled,OUTPUT);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
}
void loop()
{
  color();
  Serial.print("R intensity:");
  Serial.print(red,DEC);
  Serial.print("G intensity:");
  Serial.print(green,DEC);
  Serial.print("B intensity:");
  Serial.print(blue,DEC);
   if(red<blue && red<green)
   {
     Serial.println("-(Red color)");
     digitalWrite(redled,HIGH);
     digitalWrite(greenled,LOW);
     digitalWrite(blueled,LOW);
   }
   else if(blue<red && blue<green)
   {
     Serial.println("-(Blue color)");
     digitalWrite(redled,LOW);
     digitalWrite(greenled,LOW);
     digitalWrite(blueled,HIGH);
   }
   else if(green<red && green<blue)
   {
     Serial.println("-(Green color)");
     digitalWrite(redled,LOW);
     digitalWrite(greenled,HIGH);
     digitalWrite(blueled,LOW);
   }
   else
   {
     Serial.println();
   }
   delay(300);
   digitalWrite(redled,LOW);
     digitalWrite(greenled,LOW);
     digitalWrite(blueled,LOW);
}
void color()
{
  digitalWrite(s2,LOW);
     digitalWrite(s3,LOW);
     red=pulseIn(out,digitalRead(out)==HIGH?LOW:HIGH);
     digitalWrite(s3,HIGH);
  blue=pulseIn(out,digitalRead(out)==HIGH?LOW:HIGH);
     digitalWrite(s2,HIGH);
  green=pulseIn(out,digitalRead(out)==HIGH?LOW:HIGH);
}
