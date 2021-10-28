#ifndef CIVILIAN
#define CIVILIAN
#include <iostream>

class Civilian
{
public:
Civilian(); //Default constructor
Civilian(std::string name); //Constructor with parameters
void setName(std::string newName); //Changes a criminals name
std::string getName(); //Returns a criminals name
void giveFine(int amount); //Adds fine to _finesOwed 
bool payFine(int amount); //Removes amount from _finesOwed
int getFines(); //returns total fines civilian has
bool getCriminalRecord(); //Returns a civilians criminal record
void setCriminalRecord(bool record); //modifies the Civilian’s criminal record
void setDetained(bool status); //modifies the criminal's detained status
bool getDetained();
~Civilian(); //Deconstructor

private:
std::string _name; //A string representing the name of the civilian
bool _criminalRecord; //A boolean referring to whether the Civilian has a criminal record
bool _detained;
int _finesOwed; //An integer representing how much money a civilian owes in fines.
};
#endif