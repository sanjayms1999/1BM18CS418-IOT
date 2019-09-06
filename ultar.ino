int trigPin=5;
int echoPin=3;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
void loop()
{
  float duration,inches,cm;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
 duration=pulseIn(echoPin,HIGH);
  inches=microsecondsToInches(duration);
  cm=microsecondsToCentimeter(duration);
  Serial.print("inches:");
  Serial.println(inches);
  Serial.print("cm:");
  Serial.println(cm);

  delay(1500);
}
float microsecondsToInches(float microseconds)
{
  return microseconds/74/2;
}
long microsecondsToCentimeter(long microseconds)
{
  return microseconds/29/2;
}

