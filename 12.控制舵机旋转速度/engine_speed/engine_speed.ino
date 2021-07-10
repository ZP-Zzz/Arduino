#include <Servo.h>
Servo servo1; 
Servo servo2;
 
int pos = 0;    // 存储伺服电机角度信息的变量
int first = 90; 
 
void setup() 
{
  servo1.attach(9);  // Servo对象连接在9号引脚 
  servo2.attach(10); 
  Serial.begin(9600);
  Serial.println("输入你要控制的舵机(a/b)和角度：") ;
  servo1.write(first);
  servo2.write(first);
}
 
void loop() 
{
  if(Serial.available())
  {
    char whichone=Serial.read();
    pos=Serial.parseInt();
    Serial.print("舵机为：");
    Serial.print(whichone);
    Serial.print("角度为：");     
    Serial.println(pos);
    if(whichone=='a')
    {
        Speed_down_servo1();  
    }
    else if(whichone=='b')
    {
        Speed_down_servo2();  
    }
    else
    {Serial.println("请输入正确的舵机信号");}
    first=pos; 
  }
}


void Speed_down_servo1()
{
    if(first>pos)
    {
      for(int i=first;i>pos;i--)
      {
        servo1.write(i);
        delay(10);
      }
    }
    if(first<pos)
    {
      for(int i=first;i<pos;i++)
      {
        servo1.write(i);
        delay(10);
      }
    }
     
}


void Speed_down_servo2()
{
    if(first>pos)
    {
      for(int i=first;i>pos;i--)
      {
        servo2.write(i);
        delay(10);
      }
    }
    if(first<pos)
    {
      for(int i=first;i<pos;i++)
      {
        servo2.write(i);
        delay(10);
      }
    } 
}
