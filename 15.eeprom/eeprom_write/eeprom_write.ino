#include <EEPROM.h>
int addr = 0;

void setup() 
{
 
}

void loop() 
{
  int val = analogRead(0) / 4;  //analogRead所1读取的数值为0-1023，EEPROM只能存储0-255的数据
  EEPROM.write(addr, val);
  addr = addr + 1;
  if (addr == EEPROM.length()) 
  {
    addr = 0;
  }
  delay(100);
}
