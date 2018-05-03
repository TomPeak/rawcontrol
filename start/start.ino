int val;
#include <Encoder.h>
//#include <TrinketKeyboard.h>

Encoder myEnc(A8, A9);

void setup()
{                
  Serial.begin(250000);
  Keyboard.begin();
}

long oldPosition  = -999;
void loop()   
{
   // Exposure for CaptureOne
   long newPosition = myEnc.read();
   if(oldPosition!=newPosition){
      if (newPosition > oldPosition) {
        
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('+');
      }else{
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('-');
      }
      delay(100);
      Keyboard.releaseAll();
      Serial.println(newPosition);
      oldPosition = newPosition;
   }
   
  
  
}
