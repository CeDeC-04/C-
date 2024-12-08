// En el moment en que hi hagi detectors de cabal, caldrà canviar el "tempsreg = VolumReg_;" de la 
// funció "Planta::Reg(bool activa, bool estat){" i canviar de la funció relemillis a reledelay amb espera 0.. 
  

#include "Planta.h" //#include <Planta.h>


Planta::Planta(int PinSensorSHC, int PinRele, int RegatOK /*en valor del sensor corresponent al 100% del nivell d'humitat*/, 
  int RegatRega/*en valor del sensor corresponent al 0% del nivell d'humitat*/, int VolumReg /*en litres*/, 
  int tempsEntreRegs /*en minuts*/) : RelePlant(PinRele), Shumitat(PinSensorSHC, RegatRega, RegatOK) {

  RegatOK_ = 100;  // en %
  RegatMig_ = map((2 / 3 * RegatOK_), RegatRega, RegatOK, RegatRega_, RegatOK_);  // en %
  RegatBaix_ = map((0.18 * RegatOK_), RegatRega, RegatOK, RegatRega_, RegatOK_);  // en %
  RegatRega_ = 0;  // en %
  VolumReg_ = VolumReg;             // en litres
  esperacontrol_ = tempsEntreRegs * 60000;  // en milisegons (x Minuts * 60 segons/minut * 1000 milisegons/segon)
  PinRele_ = PinRele;
  PinSensorSHC_ = PinSensorSHC;

}

void Planta::EntraQLitresMin(double QLitresMin){
  QLitresMin_ = QLitresMin;
}

int Planta::HumitatSolPercent(){
  return Shumitat.HumitatPercent();
}

bool Planta::RegXCabal(bool activa, bool estat, double QLitresMin_){
  tempsreg_ = (VolumReg_ / QLitresMin_) * 60000; // litres / ((litres * min * 60000 milisegons/min) = milisegons
  return (RelePlant.ReleMillisControl(activa, estat, tempsreg_, esperacontrol_)); // ReleMillisControl retorna un bool ("activa")

}


