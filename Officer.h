#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include "Civilian.h"

class Officer 
{
public:
	Officer();
	Officer(std::string name, std::string role);
	virtual bool arrest(Civilian* target) = 0;
	void setRole(std::string role);
	std::string getRole();
	void setName(std::string newUsername);
	std::string getName();
	~Officer();

protected:
	std::string _name;
	std::string _role;
};
#endif