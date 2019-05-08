#ifndef BEZEC_H
#define BEZEC_H
#include "Vstup.h"
#include "Const.h"


class Bezec
{
    public:
        Bezec(int ID);

        int Cislo();
        int Vydrz();
        int CelkemUbehnuto();
        int Vzdalenost();
        int ZbyvaOdpocinku();

        void Pokracovat();
        void Odpocinout(int minuty);
        void OdecitaniOdpocinku();
        void Vypis();
        void PrvniVypis();

        bool odpociva;


    private:
        int cislo_bezce;
        int prumerna_rychlost;
        int vydrz;
        int Celkem_ubehnuto;
        int muze_ubehnout;
        int zbyvaOdpocinku;
        double koeficient_odpocinku;
};

#endif // BEZEC_H
