int tempsense=0;
void setup()
{
  pinMode(tempsense,INPUT);
  Serial.begin(9600);
}
void loop()
{
  float value=analogRead(tempsense);
  float mvValue=((float)value/1024)*5000;
  float temp_in_c=mvValue/10;
  Serial.print("temp in celsius is");
  Serial.print(temp_in_c);
  Serial.print((9/5)*temp_in_c+32);
  delay(2000);
}

  
