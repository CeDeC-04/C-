#include "Led.h"


   Led::Led(int ledPin){
    
    ledPin_ = ledPin;
       
   }
  
   void Led::encen(){
	   
    digitalWrite(ledPin_, HIGH);
	 
   }
  
   void Led::apaga(){
    
	  digitalWrite(ledPin_, LOW);
	
   }

   void Led::parpadeja(int interval){//distància en cm

    int tempsAra = millis();
    
    if (tempsAbans_ < millis()/1000000000){
      
      tempsAbans_ = millis();
      
    }

    if (tempsAra - tempsAbans_ > interval * 5) {
 
      tempsAbans_ = tempsAra;

    if (digitalRead(ledPin_) == HIGH) {

      Led::apaga(); //digitalWrite(LedPin, LOW);

    } else {

      Led::encen();  //digitalWrite(LedPin, HIGH);

    }
    }
   }
