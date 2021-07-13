char serialData;
void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() 
{
  if(Serial.available()>0)
  {
    serialData=Serial.read();
    if(serialData=='1')
    {
      Serial.print("get command:");
      Serial.println(serialData);
      Serial.println("LED-on");
      digitalWrite(13,HIGH);
    }
    else
    {
      Serial.print("get command:");
      Serial.println(serialData);
      Serial.println("LED-off");
      digitalWrite(13,LOW);
    }
  }

}
