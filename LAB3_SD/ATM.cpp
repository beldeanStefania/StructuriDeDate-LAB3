#include"ATM.h"

void ATM::afisareColectie(Element bancnote[], int lungime, int k)
{
    cout << k << ")";
    k++;
    for (int i = 0; i < lungime; i++)
        cout << bancnote[i].valoare << "->" << bancnote[i].nr_aparitii << ' ';
    cout << endl;
}

ATM::ATM(const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii)
{
    this->colectie_bancnote = colectie;
    this->tranzactii = new Tranzactie[nr_tranzactii];
    this->nr_tranzactii = nr_tranzactii;
    for (int i = 0; i < nr_tranzactii; i++)
        this->tranzactii[i] = tranzactie[i];
}

void ATM::retragereNumerar(int id, int suma, int lungime, Element bancnote[])
{
    int ok = 1;
    for (int i = 0; i < lungime; i++)
        if (bancnote[i].nr_aparitii > this->colectie_bancnote.nroccurrences(bancnote[i].valoare)) {
            ok = 0;
        }
    if (!ok)
        cout << "Momentan ATM-ul nu dispune de toate bancnotele necesare tranzactiei" << endl;
    else
    {
        cout << "Tranzactie efectuata cu succes" << endl;
        for (int i = 0; i < lungime; i++) {
            Element a;
            a.valoare = bancnote[i].valoare;
            a.nr_aparitii = this->colectie_bancnote.nroccurrences(a.valoare) - bancnote[i].nr_aparitii;
            this->colectie_bancnote.set_numar_bancnote(a);
        }
        this->tranzactii[this->nr_tranzactii] = Tranzactie(id, suma, bancnote, lungime);
        this->nr_tranzactii++;
    }
}

void ATM::addBancnote(TElem valoare)
{
    this->colectie_bancnote.add(valoare);
}

void ATM::elimBancnota(TElem valoare)
{
    this->colectie_bancnote.remove(valoare);
}

void ATM::getTranzactia(int& poz_stop, int suma, Element bancnote[], int lungime, int poz)
{
    if (suma == 0)
    {
        poz_stop--;
        bancnote[lungime].valoare = -1;
    }
    else {
        for (int i = poz; i < this->colectie_bancnote.get_lungime() && poz_stop; i++) {
            if (poz_stop == 0) break;
            int k = 0;
            TElem bancnota = this->colectie_bancnote.get_val(i);
            while (suma >= 0) {
                suma = suma - bancnota;
                k++;
                bancnote[lungime].valoare = bancnota;
                bancnote[lungime].nr_aparitii = k;
                getTranzactia(poz_stop, suma, bancnote, lungime + 1, i + 1);
                if (poz_stop == 0) break;
            }
            if (suma < 0) {
                suma = suma + bancnota;
                k--;
                bancnote[lungime].nr_aparitii = k;
            }
            suma = suma + k * bancnota;
        }
    }
}

void ATM::generareTranzactii(int& indice, int suma, Element bancnote[], int lungime, int poz)
{
    if (suma == 0)
        afisareColectie(bancnote, lungime, indice);
    else {
        for (int i = poz; i < this->colectie_bancnote.get_lungime(); i++) {
            int k = 0;
            TElem bancnota = this->colectie_bancnote.get_val(i);
            while (suma >= 0) {
                suma = suma - bancnota;
                k++;
                bancnote[lungime].valoare = bancnota;
                bancnote[lungime].nr_aparitii = k;
                if (suma == 0) indice++;
                generareTranzactii(indice, suma, bancnote, lungime + 1, i + 1);
            }
            if (suma < 0) {
                suma = suma + bancnota;
                k--;
                bancnote[lungime].nr_aparitii = k;
            }
            suma = suma + k * bancnota;
        }
    }
}

void ATM::Destructor()
{
	this->colectie_bancnote.Destructor();
	this->tranzactii->Destructor();
}

ostream& operator<<(ostream& os, ATM atm)
{
	// TODO: insert return statement here
    cout << "BANCNOTE DISPONIBILE:" << endl;
    for (int i = 0; i < atm.colectie_bancnote.get_lungime(); i++)
        cout << "val: " << atm.colectie_bancnote.get_val(i) << ", numar: " << atm.colectie_bancnote.getAt(i) << endl;
    cout << endl << "TRANZACTII EFECTUATE: " << endl;
    for (int i = 0; i < atm.nr_tranzactii; i++) {
        cout << atm.tranzactii[i];
        cout << endl;
    }
    return os;
}
