#include <Arduino.h>


class Rele{

  public: 
    Rele(int PinRele);
    bool ReleMillis(bool activa, bool estat, int espera);
    void ReleDelay(bool estat, int espera);
    bool pas = 0;
    void ReleFun(bool estat, int espera);
    bool ReleMillisControl(bool activa, /*bool control_,*/ bool estat, int espera, int esperacontrol);
    

  private:
    int PinRele_;
    //int tempsAbans_ = millis();
    int tempsAbans_;
    int tempsAra_;
    bool activa_;
    int tempsAbansControl_;
    bool _control = 1;
    bool control_ = 0;
    

};