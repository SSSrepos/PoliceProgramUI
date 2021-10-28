#ifndef SHERRIF_H
#define SHERRIF_H
#include "Officer.h"

class Sherrif : public Officer
{
public:
	Sherrif();
	Sherrif(std::string name);
	void giveFine(Civilian* target, int amount);
	bool arrest(Civilian* target);	//the target civilian gets criminal record
	~Sherrif();

};
#endif