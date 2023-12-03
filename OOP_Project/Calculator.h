#pragma once

#include<iostream>
#include<string>

using namespace std;

class Calculator
{
	int batteryLevel=0;
	bool hasBattery=false;

public:

	Calculator();
	Calculator(int batteryLevel);

	bool isWorking(int batteryLevel);

	friend void operator>>(istream& console, const Calculator& c);
	friend void operator<<(ostream& console, const Calculator& c);
};