#define NUM_LEDS 60

#include <FastLED.h>
#include <Encoder.h>

Encoder myEnc1(A8, A9);
Encoder myEnc2(A7, A6);

long oldPosition1  = -999;
long oldPosition2  = -999;
long newPosition1  = -999;
long newPosition2  = -999;

const int contrastUp[] = {KEY_LEFT_GUI,KEY_LEFT_SHIFT,KEY_LEFT_CTRL,'+'};
const int contrastDown[] = {KEY_LEFT_GUI,KEY_LEFT_SHIFT,KEY_LEFT_CTRL,'-'};

const int exposureUp[] = {KEY_LEFT_GUI,KEY_LEFT_CTRL,'+'};
const int exposureDown[] = {KEY_LEFT_GUI,KEY_LEFT_CTRL,'-'};
int mode = 0 ;


//modeKnobs[][][]={'up','down'};
struct CRGB *leds;
uint16_t p = 0;
int modeKnobs[][6][2][4] =
  {
    {
      {
        {KEY_LEFT_GUI,KEY_LEFT_SHIFT,KEY_LEFT_CTRL,'+'},
        {KEY_LEFT_GUI,KEY_LEFT_SHIFT,KEY_LEFT_CTRL,'-'}
       },
       {
        {KEY_LEFT_GUI,KEY_LEFT_CTRL,'+'},
        {KEY_LEFT_GUI,KEY_LEFT_CTRL,'-'} 
       }
      }
    };


void setup()
{                
  Serial.begin(250000);
  Keyboard.begin();
  FastLED.addLeds<APA102,7,11>(leds,NUM_LEDS);
  
  
}

static uint8_t hue = 0;

void pressCombi(int keys[]){
 for(int i;i<sizeof(keys);i++){
      Keyboard.press(keys[i]);
      //Serial.println(keys[i]);
      
  }  
  delay(270);
}
void loop()   
{
 
  // Exposure for CaptureOne
   long newPosition1 = myEnc1.read();
   if(oldPosition1!=newPosition1){
      if (newPosition1 > oldPosition1) {
        
        pressCombi(modeKnobs[0][0][0]);
      }else{
        pressCombi(modeKnobs[0][0][1]);
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
        
       pressCombi(modeKnobs[0][1][0]);
      }else{
        pressCombi(modeKnobs[0][1][1]);
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
        Serial.println('paste');
   }
   // Copy Ajustment
   if (analogRead(A1) == 1) 
   {
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_LEFT_GUI);
     
        Keyboard.press('c');
        delay(200);
        Keyboard.releaseAll();
        Keyboard.press(KEY_ENTER);
        delay(200);
        Keyboard.releaseAll();
        Serial.println('copy');
   }
  /* 
  leds[0] = CRGB(100, 255, 255);
  leds[4] = CRGB(20, 255, 255);
  leds[6] = CRGB(20, 255, 255);
  FastLED.show(); 
  delay(300);*/
}

