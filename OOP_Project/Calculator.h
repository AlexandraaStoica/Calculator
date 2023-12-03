#pragma once

#include<iostream>
#include<string>

using namespace std;

class Calculator
{
	int batteryLevel;
	bool hasBattery;

public:

	Calculator();
	Calculator(int batteryLevel);

	int getBatteryLevel();

	bool isWorking(int batteryLevel);

	friend void operator>>(istream& console, const Calculator& c);
	friend void operator<<(ostream& console, const Calculator& c);

	~Calculator();
};