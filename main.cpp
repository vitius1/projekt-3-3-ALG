#include <iostream>
#include "Bezec.h"
#include "Zavod.h"
#include "Const.h"

using namespace std;

int main()
{

    Zavod *zavod = new Zavod();

    for (int i=0; i<A; i++) {
        zavod->VlozitBezce();
    }


    cout << endl << "BEZCI" << endl << endl;
    zavod->SeznamBezcu();


    cout << endl << "ZACATEK ZAVODU" << endl << endl;
    for (int i=0; i<M; i++) {
        zavod->DalsiMinuta();
    }


    zavod->Konec();

    delete zavod;

    return 0;
}
