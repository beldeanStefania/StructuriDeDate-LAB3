#include "Tranzactie.h"

Tranzactie::Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote)
{
	this->idTranzactie = id;
	this->suma = suma;
	this->nrBanconte = nrBanconte;
	this->bancnote = new Element[nrBanconte];
	for (int i = 0; i < nrBanconte; i++)
		this->bancnote[i] = bancnote[i];
}

Tranzactie::Tranzactie()
{
	this->idTranzactie = -1;
	this->suma = -1;
	this->bancnote = new Element[1];
	this->nrBanconte = -1;
}

void Tranzactie::Destructor()
{
	delete[] this->bancnote;
}

Tranzactie& Tranzactie::operator=(const Tranzactie& tranzactie)
{
	// TODO: insert return statement here
	this->idTranzactie = tranzactie.idTranzactie;
	this->suma = tranzactie.suma;
	this->nrBanconte = tranzactie.nrBanconte;
	delete[] this->bancnote;
	this->bancnote = new Element[this->nrBanconte];
	for (int i = 0; i < this->nrBanconte; i++)
		this->bancnote[i] = tranzactie.bancnote[i];
	return *this;
}

ostream& operator<<(ostream& os, Tranzactie tranzactie)
{
	// TODO: insert return statement here
	cout << "id: " << tranzactie.idTranzactie << " suma: " << tranzactie.suma << endl;
	cout << "Plata: ";
	for (int i = 0; i < tranzactie.nrBanconte; i++)
		cout << tranzactie.bancnote[i].valoare << "->" << tranzactie.bancnote[i].nr_aparitii << ", ";
	cout << endl;
	return os;
}
