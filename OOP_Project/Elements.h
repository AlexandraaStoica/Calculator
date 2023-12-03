#pragma once

#include<iostream>
#include<string>

using namespace std;

class Elements
{
	string elements;
	int noElements;

public:
	Elements();
	Elements(string elements);

	string getElement();
	void setElement(string elements);

	int getNoElements();
	void setNoElements(int noElem);

	friend void operator<<(ostream& console, Elements& el);
	friend void operator>>(istream& console, Elements& el);

		
};