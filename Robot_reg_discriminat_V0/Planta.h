#include <Arduino.h>
#include "Capacitive_Soil_Moisture_Sensor_v1-2.h" // <Capacitive_Soil_Moisture_Sensor_v1-2.h>
#include "Rele_CeDeC.h" // <Rele_CeDeC.h>

class Planta{

  public:

    Planta(int PinSensorSHC, int PinRele, int RegatOK/*Valor del sensor considerat com a 100% d'humitat*/, int RegatRega/*Valor del sensor 
        considerat com a 0% d'humitat*/, int VolumReg, int tempsEntreRegs); 
      // per fer-ho més senzill d'entrar, els valors intermitjos els faré com un 2/3 parts i un 18% del màxim

    int HumitatSolPercent();

    bool RegXCabal(bool activa, bool estat, double QLitresMin);

    void EntraQLitresMin(double QLitresMin);

    
    

  private:

    SHC Shumitat; int PinSensorSHC_; // Pin ANALOGIC sensor humitat
    Rele RelePlant; int PinRele_;   // Pin DIGITAL sensor humitat
    int RegatOK_;      // correspon al % de reg considerat com a: //Valor del sensor que correspon al % de reg considerat com a:
    int RegatMig_;     // correspon al % de reg considerat com a: //Valor del sensor que correspon al % de reg considerat com a:
    int RegatBaix_;    // correspon al % de reg considerat com a: //Valor del sensor que correspon al % de reg considerat com a:
    int RegatRega_;    // correspon al % de reg considerat com a: //Valor del sensor que correspon al % de reg considerat com a:
    int VolumReg_;     // Litres d'aigua que es posiblecapaç d'absorvir el substrat entre regs o q  
    int esperacontrol_; // Temps entre regs del relé -> tempsEntreRegs
    int tempsreg_;
    int QLitresMin_; // Cabal proporcionat per la bomba en les condicions normals de funcionament del sistema
};

