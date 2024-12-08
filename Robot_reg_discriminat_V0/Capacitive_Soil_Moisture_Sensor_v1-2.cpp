//#include <Capacitive_Soil_Moisture_Sensor_v1-2.h>
#include "Capacitive_Soil_Moisture_Sensor_v1-2.h"


//SHC::SHC(uint8_t PinSensorSHC, int humitatMIN, int humitatMAX){
SHC::SHC(int PinSensorSHC, int humitatMIN, int humitatMAX){

  PinSensorSHC_ = PinSensorSHC;

  humitatMIN_ = humitatMIN; // lectura d'humitat a l'aire o a PMP o mínim que dessitgem/sabem 
                            //tenir en compte que el valor és superior que el MAX pq genera més resistència (capacitància en aquest cas)
  humitatMAX_ = humitatMAX; // lectura d'humitat a l'aigua o a CC o màxim que dessitgem/sabem 
                            //tenir en compte que el valor és inferior que el MIN pq genera menys resistència (capacitància en aquest cas)

}

int SHC::HumitatValor(){

  return (analogRead(PinSensorSHC_)); // retorna el valor d'humitat mesurat en ?¿?

}

int SHC::HumitatPercent(){

  //return (humitatpercentatge = map(SHC::HumitatValor(), humitatMIN_, humitatMAX_, 0, 100));
  return (map(SHC::HumitatValor(), humitatMAX_, humitatMIN_, 0, 100));
  //return (map(SHC::HumitatValor(), humitatMIN_, humitatMAX_, 0, 100));

}

String SHC::CalibraSensor(){

  humitat = analogRead(PinSensorSHC_); 
  if (humitat > humitatMAX_){ humitatMAX_ = humitat;} //el valor correspon al valor del sensor, no de l'humitat mesurada donat que el valor és inversament proporcional
  if (humitat < humitatMIN_){ humitatMIN_ = humitat;} //el valor correspon al valor del sensor, no de l'humitat mesurada donat que el valor és inversament proporcional
   //int percentatge = map(valorSensor, 370, 200, 0, 100);
  humitatpercentatge = map(humitat, humitatMAX_, humitatMIN_, 0, 100);
                                  //el valor MAX d'humitat llegida correspón a màxima conductància i per tant al valor mínim d'humitat a lo mesurat
                                  //el valor MIN d'humitat llegida correspón a mínima conductància i per tant al valor màxim d'humitat a lo mesurat
//  if (humitatpercentatge > humitatMAX_){ humitatpercentMAX_ = humitatpercentatge;} // FUTURIBLE
//  if (humitatpercentatge < humitatMIN_){ humitatpercentMIN_ = humitatpercentatge;} // FUTURIBLE
  delay(500);


  return ("Humitat mesurada és:   " + String(humitat) + " --- " + "Rang d'humitat mesurada és:   " + String(humitatMAX_) + " - " + String(humitatMIN_) + " --- " + "El percentatge d'humitat mesurada és:   " + String(humitatpercentatge));

}
  







  /*void loop() {
soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent >= 100)
*/
