#include <Arduino.h>
#include "Led.h" //#include <Led.h>
#include "Planta.h" //#include <Planta.h>
#include <Adafruit_PWMServoDriver.h>
//#include <Servo.h>
#include "Stepper_BasicV3.h" //#include <Stepper_BasicV3.h>


class PlantaRobot {
//class PlantaRobot : public Planta {

  public:
   
    PlantaRobot(int PinSensorSHC, int RegatOK/*Valor del sensor considerat com a 100% d'humitat*/,
      int RegatRega/*Valor del sensor considerat com a 0% d'humitat*/, int PinLEDVerd, int PinLEDGroc, int PinLEDVermell, int PinLEDBlau,
      int PinRele, int VolumReg, int tempsEntreRegs, int PinBobina_1, int PinBobina_2, int PinBobina_3, int PinBobina_4);

    int HumitatSolPercent();

    bool RegXCabal(bool activa, bool estat, double QLitresMin);

    void EntraQLitresMin(double QLitresMin);
   
    void encen(String ColorLed); 
   
    void apaga(String ColorLed); 
   
    void parpadeja(String ColorLed, int interval);

    void EntrarDadesServo(); // SG90, MG995, 20kg
//                Futurible?¿
         
    void MouArticulacio(String NomServo, int microsec); // (comentari obsolet ->) valor d'entrada, el pin, el valor minim del rang, valor maxim del rang 
        //segur que aquesta funció (mirar *.cpp) es pot fer infinitament millor dinamitzant la tria del servo en funció dels que hi hagi i no com està ara que és estatic i s'ha de canviar cada vegada si es canvien els noms
          //Espatlla
          //Colze
          //Canell
          //Pinsa

    void RotaBase(int graus, int demora, bool forsa);

   // String ColorLed;
   
  private:

    Planta Pplanta;
    Led LedVerd; int PinLEDVerd_;    // 3a s'encendrà quan el procés de regat s'hagi completat i estigui per sobre del 60% d'humitat (segons varems establerts)
    Led LedGroc; int PinLEDGroc_;    // 3b- groc    -> al planta es considera regara però el substrat s'està assecant // s'encendrà quan la gumitat estigui entre el 60-40% (segons varems establerts) i s'apagarà 3a*/
    Led LedVermell; int PinLEDVermell_; // 3c- vermell -> la planta necesita regar-se // s'encendrà quan l'humitat baixi del 10% (segons varems establerts) i s'apagarà 3b 
    Led LedBlau; int PinLEDBlau_;    // 3d- blau    -> la planta està en procés de regat // s'encendrà quan la humitat baixi del 0%  
    
    // ------------------------------ FUNCIONARÀ?¿?¿?¿?¿?-----------------------------
    Adafruit_PWMServoDriver/*Servo*/ Espatlla; int PinEspatlla_; //servonum;
    Adafruit_PWMServoDriver/*Servo*/ Colze; int PinColze_;
    Adafruit_PWMServoDriver/*Servo*/ Canell; int PinCanell_;
    Adafruit_PWMServoDriver/*Servo*/ Pinsa; int PinPinsa_;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ FUNCIONARÀ?¿?¿?¿?¿?^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    Stepper Base; int PinBobina_1_; int PinBobina_2_; int PinBobina_3_; int PinBobina_4_;// int PinBase;
    int PinRele_;
    int RegatOK_;      // % de reg considerat com a: // Valor del sensor que correspon al % de reg considerat com a:
    int RegatMig_;     // % de reg considerat com a: // Valor del sensor que correspon al % de reg considerat com a:
    int RegatBaix_;    // % de reg considerat com a: // Valor del sensor que correspon al % de reg considerat com a:
    int RegatRega_;    // % de reg considerat com a: // Valor del sensor que correspon al % de reg considerat com a:
    int PinSensorSHC_;
    int VolumReg_;
    int tempsEntreRegs_;
                    
                          /*Nota: els valors de percentatges d'humitat són arbitraris i tenint en compte les plantes inicials usades, "Spatiphilium sp.", que resisteixen molt i molt bé la manca d'aigua,
                                    a més que la planta et mostra quan li falta aigua sense patir per la seva supervivència. Aquests valors, s'hauràn d'anar ajustant amb l'experiéncia del resultat del sistema
                                    (calibratge in-vivo) a més d'ajustar-se a cada planta/substrat-sol*/


};

   