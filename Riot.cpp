#include "Officer.h"
#include "Riot.h"
//#include "Civilian.h"
using namespace std;

Riot::Riot()
{
	_name = "null";
	_role = "Riot";
}

Riot::Riot(string name)
{
	_name = name;
	_role = "Riot";
};

bool Riot::arrest(Civilian* target)
{
	target->setDetained(true);
	if(target->getDetained() == true && target->getCriminalRecord() == false){
		return true;
	}else{
		return false;
	}
}			//the target civilian gets Detained condition set to true, w/o criminalRecord being changed

Riot::~Riot()
{
};

/*Riot::~Riot()				//used in testing
{
	cout << "Riot officer destroyed\n";
};*/