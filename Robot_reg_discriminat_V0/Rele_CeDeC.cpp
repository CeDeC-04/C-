#include "Rele_CeDeC.h"


Rele::Rele(int PinRele){
  PinRele_ = PinRele;
}

void Rele::ReleDelay(bool estat, int espera){//espera en ms
  // si hi ha temps d'espera, s'interpreta que ha de canviar d'estat passat aquest temps, si l'espera és 0, s'interpreta que no ha de canviar d'estat fins que se li digui
  if (espera < 0){espera *= -1;
  }; //comprovacions de la variable espera.
  
  if (espera == 0){
    digitalWrite(PinRele_, estat);
  }
  else {
    if (espera < 10){espera = 10;}; //comprovacions de la variable espera: segons DataSheed, el temps màxim de trànsit són 10ms. Agafem com a marge aquests 10ms.*/
    digitalWrite(PinRele_, estat);
    delay(espera);
    digitalWrite(PinRele_, !estat);
  };
}

bool Rele::ReleMillis(bool activa, bool estat, int espera){
  if (activa){ 
    tempsAra_ = millis();
    if (activa_){
      tempsAbans_ = tempsAra_;
      activa_ = 0;
    }
    digitalWrite(PinRele_, estat); 
    if (tempsAra_ - tempsAbans_ > espera) {
      tempsAbans_ = tempsAra_; //igual no cal
      digitalWrite(PinRele_, !estat); 
      activa = 0;
      activa_ = 1;
    } 
  }
  return (activa);
}


// la idea es que regui només si ha passat cert temps des de l'últim reg per assegurar que l'aigua es distribueix pel substrat/sol o és absorvit per la terra i no rebossa pel contenidor/escorrentia
bool Rele::ReleMillisControl(bool activa, bool estat, int espera, int esperacontrol){ 
  tempsAra_ = millis(); 
  if (control_){
    if (_control){ // "reseteja" la variable "tempsAbansControl_" per inicialitzar el comptatge del temps d'espera entre activacions
        tempsAbansControl_ = tempsAra_;
        _control = 0;
      }
    if (tempsAra_ - tempsAbansControl_ > esperacontrol) {
        tempsAbansControl_ = tempsAra_; //igual no cal
        control_ = 0;
        _control = 1;
      }
  } else {
      if (activa){ 
        if (activa_){ //inicialitza el comptador del temps de l'activació actual/en curs
          tempsAbans_ = tempsAra_;
          activa_ = 0;
        }
        digitalWrite(PinRele_, estat); 
        if (tempsAra_ - tempsAbans_ > espera) {
          tempsAbans_ = tempsAra_; //igual no cal
          digitalWrite(PinRele_, !estat); 
          activa = 0;
          activa_ = 1;
          control_ = 1;
        } 
      }
  }
  return (activa);
}


void Rele::ReleFun(bool estat, int espera){
  digitalWrite(PinRele_, estat);
  if (espera <= 15){delay(20);} else {delay(espera);}
}