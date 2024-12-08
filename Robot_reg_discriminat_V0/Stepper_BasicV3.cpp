#include "Stepper_BasicV3.h"


Stepper::Stepper(int PinBobina_1, int PinBobina_2, int PinBobina_3, int PinBobina_4){
  
  PinBobina_1_ = PinBobina_1;
  PinBobina_2_ = PinBobina_2;
  PinBobina_3_ = PinBobina_3;
  PinBobina_4_ = PinBobina_4;
}

void Stepper::apagat() {//aturada, repós, sense energia, aturat...

  digitalWrite(PinBobina_1_,LOW); 
  digitalWrite(PinBobina_2_,LOW);
  digitalWrite(PinBobina_3_,LOW);
  digitalWrite(PinBobina_4_,LOW);
}

void Stepper::horari(int graus, int demora){//gir "normal" en sentit horari

   unsigned long pasfinal = (graus/360.)*512;
  for (int i = 0; i <= pasfinal; i++) {
    digitalWrite(PinBobina_1_,HIGH); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 1
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,HIGH); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 2
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,HIGH); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 3
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,HIGH); delay(demora); //pas 4
}
}

 void  Stepper::antihorari(int graus, int demora){//gir "normal" en sentit antihorari

  int pasfinal = (graus/360.)*512;
  for (int i = 0; i <= pasfinal; i++) {

    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,HIGH); delay(demora); //pas 4
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,HIGH); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 3
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,HIGH); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 2
    digitalWrite(PinBobina_1_,HIGH); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 1
  }
}

void Stepper::horaritorke(int graus, int demora){//gir "força" en sentit horari (doble bobina)
  
  int pasfinal = (graus/360.)*512;
  for (int i = 0; i <= pasfinal; i++) {

    digitalWrite(PinBobina_1_,HIGH); digitalWrite(PinBobina_2_,HIGH); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 1
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,HIGH); digitalWrite(PinBobina_3_,HIGH); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 2
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,HIGH); digitalWrite(PinBobina_4_,HIGH); delay(demora); //pas 3
    digitalWrite(PinBobina_1_,HIGH); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,HIGH); delay(demora); //pas 4
}
}

void Stepper::antihoraritorke(int graus, int demora){//gir "força" en sentit antihorari (doble bobina)

  int pasfinal = (graus/360.)*512;
  for (int i = 0; i <= pasfinal; i++) {
 
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,HIGH); digitalWrite(PinBobina_4_,HIGH); delay(demora); //pas 4
    digitalWrite(PinBobina_1_,LOW); digitalWrite(PinBobina_2_,HIGH); digitalWrite(PinBobina_3_,HIGH); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 3
    digitalWrite(PinBobina_1_,HIGH); digitalWrite(PinBobina_2_,HIGH); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,LOW); delay(demora); //pas 2
    digitalWrite(PinBobina_1_,HIGH); digitalWrite(PinBobina_2_,LOW); digitalWrite(PinBobina_3_,LOW); digitalWrite(PinBobina_4_,HIGH); delay(demora); //pas 1
}
}

void Stepper::gira(int graus, int demora, bool forsa){
  
  if (graus < 0){//antihorari
    graus = -graus;
    if (forsa){
      Stepper::antihoraritorke(graus, demora);
    } else{
        Stepper::antihorari(graus, demora); 
    }
  } else {
      if (forsa){
        Stepper::horaritorke(graus, demora);
      } else {
        Stepper::horari(graus, demora);
     }
    }
  }
