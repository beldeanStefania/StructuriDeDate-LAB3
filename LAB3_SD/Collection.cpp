#include "Collection.h"

Collection::Collection()
{
	this->distinctelements = 0;
	this->capacity = 10;
}

void Collection::Destructor()
{
	this->capacity = 0;
	this->distinctelements = 0;
	this->elements.Destructor();
}

void Collection::add(TElem elem)
{
	if (search(elem))
	{
		int ok = 1;
		for(int i=0;i<this->distinctelements;i++)
			if (this->elements.getAt(i).valoare == elem)
			{
				int nrAparitii = this->elements.getAt(i).nr_aparitii+1;
				Element elem2;
				elem2.valoare = elem;
				elem2.nr_aparitii = nrAparitii;
				this->elements.update(i, elem2);
				ok = 0;
			}
	}
	else
	{
		if (this->distinctelements == capacity) redim();
		Element elem3;
		elem3.valoare = elem;
		elem3.nr_aparitii = 1;
		this->elements.push_back(elem3);
		this->distinctelements++;
	}
}

bool Collection::remove(TElem elem)
{
	if (search(elem))
	{
		int i = 0;
		while (this->elements.getAt(i).valoare != elem)
			i++;
		for (int j = i; j < this->distinctelements - 1; j++) {
			this->elements.update(j, this->elements.getAt(j + 1));
		}
		this->distinctelements--;
		return true;
	}
	return false;
}

bool Collection::search(TElem elem)
{
	for (int i = 0; i < this->distinctelements; i++)
		if (this->elements.getAt(i).valoare == elem) return true;
	return false;
}

int Collection::size()
{
	int sum = 0;
	for (int i = 0; i < this->distinctelements; i++)
		sum = sum + this->elements.getAt(i).valoare * this->elements.getAt(i).nr_aparitii;
	return sum;
}

void Collection::redim()
{
	this->capacity = this->capacity * 2;
}

int Collection::nroccurrences(TElem elem)
{
	if (search(elem)) {
		int i = 0;
		while (this->elements.getAt(i).valoare != elem)
			i++;
		return this->elements.getAt(i).nr_aparitii;
	}
	return -1;
}

int Collection::getAt(int position)
{
	return this->elements.getAt(position).nr_aparitii;
}

int Collection::get_lungime()
{
	return this->distinctelements;
}

void Collection::set_numar_bancnote(Element elem)
{
	if (search(elem.valoare))
	{
		int i = 0;
		while (this->elements.getAt(i).valoare != elem.valoare)
			i++;
		this->elements.update(i, elem);
	}
}

TElem Collection::get_val(int position)
{
	return this->elements.getAt(position).valoare;
}

Collection& Collection::operator=(const Collection& colectie)
{
	// TODO: insert return statement here
	this->distinctelements = colectie.distinctelements;
	this->capacity = colectie.capacity;
	for (int i = 0; i < this->capacity; i++)
		this->elements.update(i, colectie.elements.getAt(i));
	return *this;
}
