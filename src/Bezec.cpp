#include "Bezec.h"
#include <iostream>

using namespace std;

Bezec::Bezec(int ID)
{
    this->cislo_bezce=ID+1;
	this->prumerna_rychlost = (rand() % (R2 - R1)) + R1;
	this->vydrz = (rand() % (V2 - V1)) + V1;
	this->koeficient_odpocinku = rand() / (RAND_MAX + 1.);

	this->Celkem_ubehnuto = 0;
	this->odpociva = false;
	this->muze_ubehnout = this->vydrz * this->prumerna_rychlost;
}

void Bezec::Pokracovat()
{
    this->Celkem_ubehnuto += this->prumerna_rychlost;

    if(this->Celkem_ubehnuto >= vydrz)
    {
        this->prumerna_rychlost = this->prumerna_rychlost/2;
        this->vydrz = this->vydrz/2;
        this->muze_ubehnout = this->vydrz * this->prumerna_rychlost;
    }
}

void Bezec::Odpocinout(int minuty)
{
    if (minuty>1){
    this->odpociva = true;
    }
    this->vydrz += this->vydrz * this->koeficient_odpocinku;
    this->zbyvaOdpocinku=minuty;
}

void Bezec::OdecitaniOdpocinku(){
    this->zbyvaOdpocinku--;
    if(this->zbyvaOdpocinku<=1)
    {
        odpociva=false;
    }
}

void Bezec::Vypis()
{
        cout << "ID: " << this->cislo_bezce << "\t";
        cout << "Ubehl: " << this->Celkem_ubehnuto << "\t";
        cout << "rychlost: " << this->prumerna_rychlost << "\t";
        cout << "muze ubehnout: " << this->muze_ubehnout << "\t";
}

void Bezec::PrvniVypis()
{
        cout << "ID: " << this->cislo_bezce << "\t";
        cout << "rychlost: " << this->prumerna_rychlost << "\t";
        cout << "vydrz: " << this->vydrz << "\t";
        cout << "Koeficient odpocinku: " << this->koeficient_odpocinku << endl;
}

int Bezec::Cislo()
{
    return this->cislo_bezce;
}

int Bezec::Vydrz()
{
    return this->vydrz;
}

int Bezec::CelkemUbehnuto()
{
    return this->Celkem_ubehnuto;
}

int Bezec::Vzdalenost()
{
    return this->Celkem_ubehnuto;
}

int Bezec::ZbyvaOdpocinku()
{
    return this->zbyvaOdpocinku;
}

