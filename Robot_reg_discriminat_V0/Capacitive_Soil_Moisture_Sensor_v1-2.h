#include <Arduino.h>

class SHC{//Sensor Humitat Capacitatiu o "Capacitive Soil Moisture Sensor v1.2"
//class CSMS
  public:
    //SHC(uint8_t PinSensorSHC, int humitatMIN, int humitatMAX);
    SHC(int PinSensorSHC, int humitatMIN, int humitatMAX);
    int humitat;
    int humitatpercentatge;    
    int HumitatValor();
    int HumitatPercent();
    String CalibraSensor();
  private:
    int humitatMIN_; // lectura d'humitat a l'aire o a PMP o mínim que dessitgem/sabem 
                     //tenir en compte que el valor és superior que el MAX pq genera més resistència (capacitància en aquest cas)
    int humitatMAX_; // lectura d'humitat a l'aigua o a CC o màxim que dessitgem/sabem 
                     //tenir en compte que el valor és inferior que el MIN pq genera menys resistència (capacitància en aquest cas)
    //uint8_t PinSensorSHC_;
    int PinSensorSHC_;
    int humitatpercentMAX_;
    int humitatpercentMIN_;

};
