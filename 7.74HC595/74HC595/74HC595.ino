int ST=2;
int SH=3;
int DS=4;
void setup() 
{
  pinMode(ST,OUTPUT);
  pinMode(SH,OUTPUT);
  pinMode(DS,OUTPUT);
}

void loop() 
{
  digitalWrite(ST,LOW);
  
  put(1);
  put(1);
  put(0);
  put(0);
  put(1);
  put(1);
  put(0);
  put(0);

  digitalWrite(ST,HIGH);
}


void put(int num)
{
  digitalWrite(SH,LOW);
  digitalWrite(DS,num);
  digitalWrite(SH,HIGH);
} 
