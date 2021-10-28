#ifndef RIOT_H
#define RIOT_H
#include "Officer.h"

class Riot : public Officer
{
public:
	Riot();
	Riot(std::string name);
	bool arrest(Civilian* target);	//the target civilian gets Detained condition set to true, w/o criminalRecord being changed
	~Riot();

};
#endif