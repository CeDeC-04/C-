#include "Planta_robot.h" // #include <Planta_robot.h>


PlantaRobot::PlantaRobot(int PinSensorSHC, int RegatOK/*Valor del sensor considerat com a 100% d'humitat*/,
  int RegatRega/*Valor del sensor considerat com a 0% d'humitat*/, int PinLEDVerd, int PinLEDGroc, int PinLEDVermell, int PinLEDBlau, 
  int PinRele, int VolumReg, int tempsEntreRegs, int PinBobina_1, int PinBobina_2, int PinBobina_3, int PinBobina_4) : 
  Pplanta(PinSensorSHC, PinRele, RegatOK, RegatRega, VolumReg, tempsEntreRegs), 
  LedVerd(PinLEDVerd), LedGroc(PinLEDGroc), LedVermell(PinLEDVermell), LedBlau(PinLEDBlau),
  Base(PinBobina_1, PinBobina_2, PinBobina_3, PinBobina_4) {

  RegatOK_ = RegatOK;
  RegatRega_ = RegatRega;
  PinLEDVerd_ = PinLEDVerd;
  PinLEDGroc_ = PinLEDGroc;
  PinLEDVermell_ = PinLEDVermell;
  PinLEDBlau_ = PinLEDBlau;
  PinSensorSHC_ = PinSensorSHC;
  VolumReg_ = VolumReg;
  tempsEntreRegs_ = tempsEntreRegs;
  PinRele_ = PinRele;
  PinBobina_1_ = PinBobina_1;
  PinBobina_2_ = PinBobina_2;
  PinBobina_3_ = PinBobina_3;
  PinBobina_4_ = PinBobina_4;
}

int PlantaRobot::HumitatSolPercent(){
  Pplanta.HumitatSolPercent();
}

bool PlantaRobot::RegXCabal(bool activa, bool estat, double QLitresMin){
  Pplanta.RegXCabal(activa, estat, QLitresMin);
}

void PlantaRobot::EntraQLitresMin(double QLitresMin){
  Pplanta.EntraQLitresMin(QLitresMin);
}

void PlantaRobot::encen(String ColorLed){
  if (ColorLed == "Verd"){
    LedVerd.encen();
  } else if (ColorLed == "Groc"){
    LedGroc.encen();
  } else if (ColorLed == "Vermell"){
    LedVermell.encen();
  } else if (ColorLed == "Blau"){
    LedBlau.encen();
  }
}
   
void PlantaRobot::apaga(String ColorLed){
  if (ColorLed == "Verd"){
    LedVerd.apaga();
  } else if (ColorLed == "Groc"){
    LedGroc.apaga();
  } else if (ColorLed == "Vermell"){
    LedVermell.apaga();
  } else if (ColorLed == "Blau"){
    LedBlau.apaga();
  }
}
   
void PlantaRobot::parpadeja(String ColorLed, int interval){
  if (ColorLed == "Verd"){
    LedVerd.parpadeja(interval);
  } else if (ColorLed == "Groc"){
    LedGroc.parpadeja(interval);
  } else if (ColorLed == "Vermell"){
    LedVermell.parpadeja(interval);
  } else if (ColorLed == "Blau"){
    LedBlau.parpadeja(interval);
  }
}

void PlantaRobot::MouArticulacio(String NomServo, int microsec){ 
  if (NomServo == "Espatlla"){ //segur que aixó es pot fer infinitament millor dinamitzant-lo i no com està ara que és estatic i s'ha de canviar cada vegada si es canvien els noms
    Espatlla.writeMicroseconds(PinEspatlla_, microsec);
  } else if (NomServo == "Colze"){
    Colze.writeMicroseconds(PinColze_, microsec);
  } else if (NomServo == "Canell"){
    Canell.writeMicroseconds(PinCanell_, microsec);
  } else if (NomServo == "Pinsa"){
    Pinsa.writeMicroseconds(PinPinsa_, microsec);
  }
}

void PlantaRobot::RotaBase(int graus, int demora, bool forsa){
  Base.gira(graus, demora, forsa);
}


/*  Futurible?¿
void EntrarDadesServo(String CodiServo){ // SG90, MG995, 20kg     

  if (CodiServo = "SG90")

Servo::writeMicroseconds(value);


*/