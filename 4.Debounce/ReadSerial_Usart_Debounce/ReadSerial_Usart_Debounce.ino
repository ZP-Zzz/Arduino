//按钮按一下串口就输出一下
int pushButton = 7;
int beforeState=0;
int count=0;
void setup()
{
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() 
{
  int buttonState = digitalRead(pushButton);
  if(buttonState==1 and beforeState==0)
  {
    Serial.println("hi~~");
    count++;
    Serial.println(count);
  }
  beforeState=buttonState; //把之前的状态给beforeState，防止按住时一直输出
  if(buttonState!=beforeState)
  {
     delay(20);  
  }
  //delay(1000);      
}
