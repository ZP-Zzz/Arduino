#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN); //接收器在11号引脚,建立一个对象，类似舵机
decode_results results; //定义一个新的变量，专门存储红外遥控的信息

void setup()
{
//  pinMode(13,OUTPUT);
//  digitalWrite(13,LOW);
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();              // 启动接收器
  Serial.println("Enabled IRin");
}

void loop() 
{
  if (irrecv.decode(&results)) //decode解码
  {
    Serial.println(results.value, HEX);
 //   if(results.value==0x9716BE3F)
 //   {
  //    digitalWrite(13,HIGH);
  //  } 
  //  if(results.value==0x3D9AE3F7)
  //  {
  //    digitalWrite(13,LOW);
   // }    
    irrecv.resume(); // 恢复接收下一个红外信号
  }
  delay(100);
}
