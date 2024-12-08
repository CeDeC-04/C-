#include <Arduino.h>


class Stepper {

  public:

    Stepper(int PinBobina_1, int PinBobina_2, int PinBobina_3, int PinBobina_4);
    void apagat();
    void horari(int graus, int demora); //Gir "normal"
    void antihorari(int graus, int demora); //Gir "normal"
    void horaritorke(int graus, int demora); //Gir amb força
    void antihoraritorke(int graus, int demora); //Gir amb força

    void gira(int graus, int demora, bool forsa);

    int volta = 512; //número de blocs de 4 pasos per a realitzar una volta en el step motor 28BYJ-48 (de 4 bobines)

  private:

    int PinBobina_1_;
    int PinBobina_2_;
    int PinBobina_3_;
    int PinBobina_4_;

};