#include <Encoder.h>



Encoder myEnc1(A8, A9);
Encoder myEnc2(A7, A6);


void setup()
{                
  Serial.begin(250000);
  Keyboard.begin();
  
}

long oldPosition1  = -999;
long oldPosition2  = -999;
long newPosition1  = -999;
long newPosition2  = -999;
void loop()   
{
 
  // Exposure for CaptureOne
   long newPosition1 = myEnc1.read();
   if(oldPosition1!=newPosition1){
      if (newPosition1 > oldPosition1) {
        
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('+');
      }else{
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('-');
      }
      
      oldPosition1 = newPosition1;
      
      Serial.println(newPosition1);
      delay(200);
      Keyboard.releaseAll();
   }
   // Contrast
   long newPosition2 = myEnc2.read();
   if(oldPosition2!=newPosition2){
      if (newPosition2 > oldPosition2) {
        
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('+');
      }else{
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('-');
      }
      
      oldPosition2 = newPosition2;
      
      Serial.println(newPosition2);
      delay(200);
      Keyboard.releaseAll();
   }
   // Apply Ajustment
   if (analogRead(A3) == 1) {
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('v');
        delay(200);
        Keyboard.releaseAll();
        delay(200);
   }
   // Copy Ajustment
   if (analogRead(A1) == 1) {
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('c');
        delay(200);
        Keyboard.releaseAll();
        delay(200);
   }
  
  
}
