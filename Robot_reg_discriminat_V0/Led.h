#include <Arduino.h>

class Led {
  
  public:
 
   Led(int ledPin);
  
   void encen();
  
   void apaga();
  
   void parpadeja(int interval);

  private:
   int ledPin_;
   int tempsAbans_;
};