#include<iostream>
#include<string>
#include"Ecuation.h"
#include"Elements.h"

using namespace std;

Ecuation::Ecuation()
{
	this->ecuation = nullptr;
}

Ecuation::Ecuation(char* ecuation)
{
	if (ecuation != nullptr)
	{
		this->ecuation = new char[strlen(ecuation) + 1];
		strcpy_s(this->ecuation, strlen(ecuation) + 1, ecuation);
	}
	else
		this->ecuation = nullptr;
}

char* Ecuation::getEcuation()
{
	return this->ecuation;
}

void Ecuation::setEcuation(char* ecuation)
{
	if (ecuation == nullptr)
		throw exception("Vectorul este gol.");
	else
	{
		delete[] this->ecuation;
		this->ecuation = new char[strlen(ecuation)+1];
		strcpy_s(this->ecuation, strlen(ecuation) + 1, ecuation);
	}
}

void operator>>(istream& console, Ecuation& e)
{
	cout << "Dati o ecuatie: " << endl;
	string ec;
	console >> ec;
	delete[] e.ecuation;
	e.ecuation = new char[ec.size() + 1];
	strcpy_s(e.ecuation, ec.size() + 1, ec.c_str());
}

void operator<<(ostream& console, Ecuation& e)
{
	if (e.ecuation == nullptr)
		throw exception("Vectorul este null");
	else
		console << e.ecuation;
}

Ecuation& Ecuation::operator=(Ecuation& e)
{
	if (this != &e)
	{
		Ecuation::setEcuation(e.ecuation);
	}
	return *this;
}