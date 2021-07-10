#include <Servo.h>
Servo servo1,servo2;  

int pos = 0;    // 存储伺服电机角度信息的变量
 
void setup() 
{
  servo1.attach(9);  // Servo1对象连接在9号引脚 
  servo2.attach(10);// Servo2对象连接在10号引脚 
  Serial.begin(9600);
  Serial.println("输入你要控制的角度：") ;
}
 
void loop() 
{
  if(Serial.available())
  {
    Serial.print("角度为：");
    pos=Serial.parseInt();  
    Serial.println(pos);
    servo1.write(pos);
    servo2.write(pos);
  }
}
