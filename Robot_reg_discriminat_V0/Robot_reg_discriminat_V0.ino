#include "Planta_robot.h" // #include <Planta_robot.h>
///////////////////////////////////////posar els pindel reles i del pas a pas


int PinSensorSHC_1 = A0;
int RegatOK_1 = 600;
int RegatRega_1 = 200;
int PinLEDVerd_1 = 2;
int PinLEDGroc_1 = 3;
int PinLEDVermell_1 = 4;
int PinLEDBlau_1 = 5;
int PinRele_1 = 0000;
int VolumReg_1 = 200;
int tempsEntreRegs_1 = 5000;
int PinBobina_1_1 = 0000000;
int PinBobina_2_1 = 0000000;
int PinBobina_3_1 = 0000000;
int PinBobina_4_1 = 0000000;

//int RegatMig_;
//int RegatBaix_;
//int RegatOK_2 = 75;
//int RegatRega_2 = 15;

int VolumReg =          00000000000;
int tempsEntreRegs =        0000000000;


PlantaRobot PR (PinSensorSHC_1, RegatOK_1, RegatRega_1, PinLEDVerd_1, PinLEDGroc_1, PinLEDVermell_1, PinLEDBlau_1,
  PinRele_1, VolumReg_1, tempsEntreRegs_1, PinBobina_1_1, PinBobina_2_1, PinBobina_3_1, PinBobina_4_1); /*: 
  Pplanta Pl(PinSensorSHC_1, PinRele_1, RegatOK_1, RegatRega_1, VolumReg_1, tempsEntreRegs_1), 
  LedVerd LVd(PinLEDVerd_1), LedGroc LG(PinLEDGroc_1), LedVermell LVl(PinLEDVermell_1), LedBlau LB(PinLEDBlau_1),
  Base Bs(PinBobina_1_1, PinBobina_2_1, PinBobina_3_1, PinBobina_4_1);*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

/*
Objectes -> funcions
  PlantaRobot(
      HumitatSolPercent(
      RegXCabal(
      EntraQLitresMin(
      encen(
      apaga(
      parpadeja(
      EntrarDadesServo(
      MouArticulacio(
      RotaBase(
      Planta Pplanta;
      LedVerd
      LedGroc
      LedVermell
      LedBlau
      Adafruit_PWMServoDriver Espatlla
      Adafruit_PWMServoDriver Colze
      Adafruit_PWMServoDriver Canell
      Adafruit_PWMServoDriver Pinsa
      Stepper Base

  Pplanta(
    Planta(
    HumitatSolPercent(
    RegXCabal(
    EntraQLitresMin(
    SHC Shumitat
    Rele RelePlant
    
  LedVerd(
  LedGroc(
  LedVermell(
  LedBlau(
    encen(
    apaga(
    parpadeja(

  Base(
    gira(
*/




void loop() {
  // put your main code here, to run repeatedly:


  Serial.print("Percentatge d'humitat és:   ");
  Serial.println(PR.HumitatSolPercent());
  //delay(1000);
 Serial.print("PinSensorSHC_1:   ");
  Serial.println(PinSensorSHC_1);

PR.encen("Groc"); delay(1000);

PR.apaga("Groc"); delay(1000);
   /* 3- Si el pas 2 dona el vist i plau -> El braç robotic agafa la mànega i es mou fins el test de la planta en qüestió. Es pot posar un Led que indica l'objectiu.*/
                          //    Si el temps ho permet, la idea és que hi hagin 4 leds:*/
      /*3a- verd    -> la planta es considera regada // s'encendrà quan el procés de regat s'hagi completat i estigui per sobre del 60% d'humitat (segons varems establerts)*/
 /* if (P_1.HumitatPercent() > RegatOK_) {
    
    dsfd

  };*/
                          /*      3b- groc    -> al planta es considera regara però el substrat s'està assecant // s'encendrà quan la gumitat estigui entre el 60-40% (segons varems establerts) i s'apagarà 3a*/
                          /*      3c- vermell -> la planta necesita regar-se // s'encendrà quan l'humitat baixi del 10% (segons varems establerts) i s'apagarà 3b*/
                          /*      3d- blau    -> la planta està en procés de regat // s'encendrà quan la humitat baixi del 0% */
                          //    Nota: els valors de percentatges d'humitat són arbitraris i tenint en compte les plantes inicials usades, "Spatiphilium sp.", que resisteixen molt i molt bé la manca d'aigua, */
                          //          a més que la planta et mostra quan li falta aigua sense patir per la seva supervivència. Aquests valors, s'hauràn d'anar ajustant amb l'experiéncia del resultat del sistema */
                          //          (calibratge in-vivo) a més d'ajustar-se a cada planta/substrat-sol*/
                          /*      3*a- en el moment que el sistema inicii el procés de regat, parpadejaran tots els sensors indicant el destí del reg actual*/
                          /*      3*b- un cop finalitzat parcialment el reg, només restarà encés el 3d*/
                          /*      3*c- mentre transcorre el temps entre regs, els leds 3a, 3b i 3c s'encendràn en funció del valor d'humitat llegits, sempre mantenint el 3d encés, indicant que està en procés de regat*/
                          /*      3*da- un cop transcorregut el temps entre regs, si la planta requereix més regs, es torna al punt 3*a*/
                          /*      3*db- si en el punt 3*da, no es requereix cap reg, el led 3d s'apaga i el 3a s'encén*/
        //  Servos
        //  Motor pas a pas
        //  Led



     /* 1- Si es detecta que el valor d'humitat baixa un determinat valor (inicialment serà una mica a ull amb els valors que s'aconsegueixin i amb l'experiència i registres s'anirà afinant)*/
       //   Sensor d'humitat*/
 
/*Començar pel 3, que indicarà els leds a encendres, un cop arribat 3d, dona l'ordre de regar que es farà de manera externa al 3, que seguirà encenent i apagant els leds en funció del nivell d'humitat,
 però el led 3d només s'apagarà quan el sistema hagi finalitzat el procés del reg
    Ordre d'execució (la tabulació és important, els del mateix niuvell inicial, vol dir q s'executen "a la vegada", mentre q els de sota trabulats, depenen de l'altre)
      3 a,b,c
      3d
        activa el 2
      2
        1/4/5
  */    

     /* 2- Si no s'ha regat en un determinat temps (A1), es te en compte el valor (la lògica funcionarà diferent, si aquest temps no ha vençut, no es llegirà el valor)*/
     
     /* 4- Una vegada la mànega està al lloc correcte, es procedeix a regar un determinat volum d'aigua (en una primera fase -> mesurat per temps(prèviament s'ha de coneixer el cabal de la bomba 
                o el cabal relatiu al volum aportat en x temps) en una segona fase es pot utilitzar un sensor de cabal per a determinar aquest volum subministrat) determinat per A1, el cabal, 
                el volum disponible fins la part superior del contenidor (o del paràmetre que es consideri a tenir en compte si és reg a terra) la capacitat d'absorció o volum màxim adminsible 
                pel volum de substrat/terra
        //  Relé que acciona el sistema de reg: electrovàlvula, bomba (en el nostre cas), etc...*/
     /* 5- Suministrat el volum predeterminat:*/
      /*  a- el relé atura el dispositiu*/
     //     Relé
    /*    b- el braç robotic desa la manega al seu lloc i espera noves ordres*/
    //      Servos
     //     Motor pas a pas
        /*6- si s'ha realitzat el suministrament del total del volum, per exemple:*/
          /*        6a- un contenidor amb dipòsit, on el que volem és omplir el diposit i ja es distribuirà la humitat al substrat.*/
            /*      6b- s'ha afegit un volum màxim predeterminat on el falor del sensor ens importi ben poc pq vol dir que alguna cosa està fallant. Realitzar alguna mena de senyal de falla/error/avís (FUTURIBLE)*/






}

/*
coses a tenir en compte
A1- tema d'hidraulica de sols i temps d'absorció, per exemple, si s'ha regat x temps q suposem q sabem l'aigua regada, esperar 30' abans de tornar a tenir en compte el valor d'humitat mesurat
A2- fer un objecte que sigui planta on tinguem:
   els pins corresponentrs al seu sensor, 
   les coordenades o posició relativa de l aplanta
   volum d'aigua o temps de reg segons cabal per a regar per reg
   quantes vegades i en quin volum regarem fins assolir el llindar màxim (CC o el q es decideixi)
   llindar de reg i llindar de no reg (per sota quan es necesiti regar i per sobre quan ja es deixi d'afegir aigua)
   requeriments temporals, com regar de nit (futurible)
   tipus de sol/substrat (futurible)
   tipus de planta (futurible)
   

*/

/*
class PlantaRobot {

  public:
  
    PlantaRobot(int RegatOK, int RegatRega, int PinLEDVerd, int PinLEDGroc, int PinLEDVermell, int PinLEDBlau, int PinSensorSHC, int PinRele, 
      int VolumReg, int tempsEntreRegs, int PinBobina_1, int PinBobina_2, int PinBobina_3, int PinBobina_4);

    int HumitatSolPercent();
    bool RegXCabal(bool activa, bool estat, double QLitresMin);
    void EntraQLitresMin(double QLitresMin);
    void encen(String ColorLed); 
    void apaga(String ColorLed); 
    void parpadeja(String ColorLed, int interval);
    void MouArticulacio(String NomServo, int microsec); 
    void RotaBase(int graus, int demora, bool forsa);

  private:

    Planta Pplanta;
    Led LedVerd; int PinLEDVerd_;   
    Led LedGroc; int PinLEDGroc_;    
    Led LedVermell; int PinLEDVermell_; 
    Led LedBlau; int PinLEDBlau_;   
    
    // ------------------------------ FUNCIONARÀ?¿?¿?¿?¿?-----------------------------
  //  Adafruit_PWMServoDriver/*Servo*/// Espatlla; int PinEspatlla_; //servonum;
  //  Adafruit_PWMServoDriver/*Servo*/ Colze; int PinColze_;
  //  Adafruit_PWMServoDriver/*Servo*/ Canell; int PinCanell_;
  //  Adafruit_PWMServoDriver/*Servo*/ Pinsa; int PinPinsa_;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ FUNCIONARÀ?¿?¿?¿?¿?^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  /*  Stepper Base; int PinBobina_1_; int PinBobina_2_; int PinBobina_3_; int PinBobina_4_;// int PinBase;
    int PinRele_;
    int RegatOK_; 
    int RegatRega_; 
    int PinSensorSHC_;
    int VolumReg_;
    int tempsEntreRegs_;
 
class Planta{

  public:

    Planta(int PinSensorSHC, int PinRele, int RegatOK, int RegatRega, int VolumReg, int tempsEntreRegs); 

    int HumitatSolPercent();
    bool RegXCabal(bool activa, bool estat, double QLitresMin);
    void EntraQLitresMin(double QLitresMin);

  private:

    SHC Shumitat; int PinSensorSHC_; // Pin ANALOGIC sensor humitat
    Rele RelePlant; int PinRele_;   // Pin DIGITAL sensor humitat
    int RegatOK_;      // % de reg considerat com a:
    int RegatMig_;     // % de reg considerat com a:
    int RegatBaix_;    // % de reg considerat com a:
    int RegatRega_;    // % de reg considerat com a:
    int VolumReg_;     // Litres d'aigua que es posiblecapaç d'absorvir el substrat entre regs o q  
    int esperacontrol_; // Temps entre regs del relé -> tempsEntreRegs
    int tempsreg_;
    int QLitresMin_; // Cabal proporcionat per la bomba en les condicions normals de funcionament del sistema
};

*/
