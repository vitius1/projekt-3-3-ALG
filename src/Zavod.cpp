#include "Zavod.h"
#include <iostream>

using namespace std;
Zavod::Zavod()
{
    this->pole = new Bezec*[A];
}

Zavod::~Zavod()
{
    for (int i=0; i<A; i++)
    {
        this->pole[i]=nullptr;
        delete this->pole[i];
    }
    pomocna=nullptr;
}

void Zavod::VlozitBezce()
{
    Bezec* novyBezec = new Bezec(this->indexBezce);
    this->pole[this->indexBezce]=novyBezec;
    this->indexBezce+=1;

}

void Zavod::SeznamBezcu()
{
    for (int i=0; i<A; i++)
    {
        this->pole[i]->PrvniVypis();
    }
}

void Zavod::DalsiMinuta()
{
    Setridit();
    for (int i=0; i<A; i++)
    {
        this->pole[i]->Vypis();
        Stav(i);
    }
    cout << endl << endl;
}

void Zavod::Setridit()
{
    for (int i=0; i<A; i++)
    {
        for (int k=0; k<A; k++)
        {
            if(this->pole[i]->CelkemUbehnuto() > this->pole[k]->CelkemUbehnuto())
            {
                pomocna=this->pole[i];
                this->pole[i]=this->pole[k];
                this->pole[k]=pomocna;
            }
        }
    }
}

void Zavod::Stav(int i)
{
    if(this->pole[i]->odpociva == false)
        {
            int a = rand()%2;
            if(a==1)
            {
                minuty = rand()%3 + 1; // kolik minut bude odpocivat
                this->pole[i]->Odpocinout(minuty);
                cout << "Stav: " << "sel odpocinout na " << minuty << " minut. Vydrz bude " << this->pole[i]->Vydrz() << "\t" << endl;
            } else {
                this->pole[i]->Pokracovat();
                cout << "Stav: " << "pokracuje v behu" << "\t" << endl;
            }
        } else {
            this->pole[i]->OdecitaniOdpocinku();
            cout << "Stav: " << "odpociva. Vydrz bude " << this->pole[i]->Vydrz() << ". Zbyva " << this->pole[i]->ZbyvaOdpocinku() << " minuty" << "\t" << endl;
        }
}

void Zavod::Konec()
{
    cout << "KONEC ZAVODU" << endl << endl << "VYSLEDKY" << endl;
    for (int i=0; i<A; i++)
    {
        this->pole[i]->Vypis();
        cout << endl;
    }
}

