#pragma once

#include<iostream>
#include<string>

using namespace std;

class Ecuation
{
	char* ecuation;
	

public:
	Ecuation();
	Ecuation(char* ecuation);

	char* getEcuation();
	void setEcuation(char* ecuation);


	friend void operator>>(istream& console, Ecuation& e);
	friend void operator<<(ostream & console,Ecuation& e);
	Ecuation& operator=(Ecuation& e);
}; 