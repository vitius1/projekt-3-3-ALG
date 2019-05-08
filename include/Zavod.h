#ifndef ZAVOD_H
#define ZAVOD_H
#include "Bezec.h"
#include "Vstup.h"
#include "Const.h"



class Zavod
{
    public:
        Zavod();
        ~Zavod();
        void VlozitBezce();
        void DalsiMinuta();
        void Setridit();
        void Stav(int i);
        void SeznamBezcu();
        void Konec();


    private:
        Bezec** pole;
        Bezec * pomocna;
        int minuty;
        int indexBezce = 0;

};

#endif // ZAVOD_H
