/*
 * Serial-RGB-LED
 * 
 * 通过串口输入信息调整LED的颜色
 * 指令示例： r128g100b20
 *          以上指令将LED的RGB数值调整为（128，100，20）
 *          
 * by 太极创客
 * www.taichi-maker.com
*/
const int rLedPin = 6; //引脚R
const int gLedPin = 5; //引脚G
const int bLedPin = 3; //引脚B
 
int ledR  = 0; //R Led 亮度
int ledG  = 0; //G Led 亮度
int ledB  = 0; //B Led 亮度
 
void setup() 
{
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Taichi-Maker RGB Led Tutorial.");
  Serial.println("Please Input RGB value(eg. r128g100b20).");
}
 
void loop() 
{
  
  if (Serial.available()>0) { 
    char serialCmdChar = Serial.read();  
    serialCmd(serialCmdChar);       
  }
  delay(50);      
}
 
void serialCmd(char serialCmdChar) 
{  //r128g100b20
  switch (serialCmdChar)
  {
    case 'r':
      ledR = Serial.parseInt();
      break;
 
    case 'g':
      ledG = Serial.parseInt();
      break;
 
    case 'b':
      ledB = Serial.parseInt();
      break;    
 
    case 'c':
      ledR = 0;
      ledG = 0;
      ledB = 0;
  }
 
  analogWrite(rLedPin, ledR);
  delay(100);
  analogWrite(gLedPin, ledG);
  delay(100);
  analogWrite(bLedPin, ledB); 
  delay(100); 
  
  Serial.print ("Red Value = ");
  Serial.println (ledR);
  Serial.print ("Green Value = ");
  Serial.println (ledG);
  Serial.print ("Blue Value = ");
  Serial.println (ledB);
  Serial.println ("-------------");    
}
