#include<iostream>
#include<string>
#include"Elements.h"

using namespace std;

Elements::Elements()
{
	this->elements = nullptr;
}

Elements::Elements(string elements)
{
	this->elements = elements;
}

string Elements::getElement()
{
	return this->elements;
}

void Elements::setElement(string element)
{
	if (elements == "")
		throw exception("Vectorul este gol.");
	else
	{
		this->elements = new char[noElements];
		for (int i = 0; i < noElements; i++)
			this->elements[i] = elements[i];
	}
}

int Elements::getNoElements()
{
	return this->noElements;
}

void Elements::setNoElements(int noElem)
{
	if (noElem > 0)
		this->noElements = noElem;
	else
		throw exception("Numarul de elemente nu este valid.");
}

void operator<<(ostream& console, Elements& el)
{

}

void operator>>(istream& console, Elements& el)
{

}
