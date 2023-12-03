#include<iostream>
#include<string>
#include"Calculator.h"
#include"Ecuation.h"

using namespace std;

Calculator::Calculator()
{
	this->batteryLevel = 0;
}

Calculator::Calculator(int batteryLevel)
{
	this->batteryLevel = batteryLevel;
	this->hasBattery = false;
}

int Calculator::getBatteryLevel()
{
	if (batteryLevel < 0 || batteryLevel>100)
		throw exception("Nivelul bateriei e incorect!");
	else
		return this->batteryLevel;
}

bool Calculator::isWorking(int batteryLevel)
{
	if (batteryLevel == 0)
	{
		cout << "Calculatorul nu are baterie suficienta!" << endl;
		this->hasBattery = false;
	}
	else
	{
		this->hasBattery = true;
	}
}

void operator>>(istream& console, const Calculator& c)
{
	//console>> this->batteryLevel;
}
	
void operator<<(ostream& console, const Calculator& c)
{
	//console << "Nivelul bateriei este: " << c.batteryLevel;
}

//~Calculator::Calculator()
