#include "Sherrif.h"
#include "Officer.h"
using namespace std;

Sherrif::Sherrif()
{
	_role = "Sherrif";
}

Sherrif::Sherrif(string name)
{
	_name = name;
	_role = "Sherrif";
};
void Sherrif::giveFine(Civilian* target, int amount)		//the target civilian gets fine of given amount
{
	giveFine(target, amount);
}

bool Sherrif::arrest(Civilian* target)   //the target civilian gets criminal record and Detained set to true
{
	target->setCriminalRecord(true);
	target->setDetained(true);
	if(target->getCriminalRecord() == true && target->getDetained())
	{
		return true;
	}
	else
	{
		return false;
	}
}				

Sherrif::~Sherrif()
{
	
}