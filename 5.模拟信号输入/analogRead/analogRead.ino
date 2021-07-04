int SensorRead=0;
int NewData=0;
void setup() 
{
  Serial.begin(9600); //设置波特率

}

void loop() 
{
  SensorRead=analogRead(A0);  //读取A0的数字量
  NewData=map(SensorRead,0,1023,0,255);//约束函数,把0到1023转换成0到255
  Serial.println(NewData); //打印出来
  analogWrite(3, NewData);  //模拟量的写入，控制灯的亮度
  delay(200);
}
