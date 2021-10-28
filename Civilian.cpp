#include "Civilian.h"
#include <iostream>
#include <string>
using namespace std;

/*This is a fully functional Civilian*/

Civilian::Civilian() //Default constructor
{
	_name = "Default_Name";
	_criminalRecord = false;
	_finesOwed = 0;
	_detained = false;
}

Civilian::Civilian(string name) //Constructor with parameters
{
	if(name.length()>0)
	{
	_name = name;
	}
	else
	{
	cout << "No name entered. Name set to 'DEFAULT'." << endl;
	_name = "DEFAULT";
	}

	_criminalRecord = 0;
	_detained = false;
	_finesOwed = 0;
}

void Civilian::setName(string newName) //Changes a criminals name
{
	bool namePassed = false;

	while(namePassed == false)
	{
		if(newName.length()>0)
		{
		_name = newName;
		namePassed = true;
		}
			else
			{
			cout << "No name entered. Try again:" << endl;
			cin >> newName;
			}
	}
}

std::string Civilian::getName() //Returns a criminals name
{
	return _name;
}

void Civilian::giveFine(int amount) //Adds fine to _finesOwed 
{
	if(amount >= 0)
	{
	_finesOwed += amount;
	}
	else
		cout << "Cancelled! A fine must be greater than $0." << endl;
}

bool Civilian::payFine(int amount) //Removes amount from _finesOwed
{
	if(amount >_finesOwed)
	{
		if(_finesOwed>0)
		{
		cout << "Cancelled! "<< _name << " only needs to pay $" << _finesOwed << "." << endl;
		return false;
		}
		else
		{
			cout << "Cancelled! Nothing owed." << endl;
			return false;
		}
	}
	else
	_finesOwed -= amount;
	return true;
}

int Civilian::getFines() //returns total fines civilian has
{
	return _finesOwed;
}

bool Civilian::getCriminalRecord() //Returns a civilians criminal record
{
	return _criminalRecord;
}

void Civilian::setCriminalRecord(bool record) //modifies the Civilian’s criminal record
{
	_criminalRecord = record;
}

void Civilian::setDetained(bool status)
{
	_detained = status;
	return;
}

bool Civilian::getDetained()
{
	return _detained;
}

Civilian::~Civilian() //Deconstructor
{

}