#pragma once
#include "Collection.h"
#include<iostream>
using namespace std;

typedef int TElem;

class Tranzactie {
private:
    int idTranzactie;
    int suma;
    Element* bancnote;
    int nrBanconte;
public:
    Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote);   //Constructor cu parametrii
    Tranzactie();                                                        //Constructor implicit
    void Destructor();                                                   //Destructor
    friend ostream& operator<<(ostream& os, Tranzactie tranzactie);      //Supra incarcare operator afisare
    Tranzactie& operator=(const Tranzactie& tranzactie);                 //operator de atribuire
};