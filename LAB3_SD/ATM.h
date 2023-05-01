#pragma once
#include "Collection.h"
#include "Tranzactie.h"

#include<iostream>
using namespace std;

class ATM {
private:
    Collection colectie_bancnote;
    Tranzactie* tranzactii;
    int nr_tranzactii;
    void afisareColectie(Element bancnote[], int lungime, int k);
public:
    ATM(const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii);
    void retragereNumerar(int id, int suma, int lungime, Element bancnote[]);
    friend ostream& operator<<(ostream& os, ATM atm);
    void addBancnote(TElem valoare);
    void elimBancnota(TElem valoare);
    void getTranzactia(int& poz_stop, int suma, Element bancnote[], int lungime, int poz);
    void generareTranzactii(int& indice, int suma, Element bancnote[], int lungime, int poz);
    void Destructor();
};