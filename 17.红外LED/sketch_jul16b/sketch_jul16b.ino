#include <IRremote.h>

IRsend irsend;

void setup() {


}

void loop() 
{
  for(int i=0;i<3;i++)
  {
      irsend.sendNEC(0xFF30CF,32);
      delay(40);
  }
  delay(2000);
}
