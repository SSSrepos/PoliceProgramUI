#include "Officer.h"
#include <fstream>
using namespace std;


Officer::Officer()
{
	_name = "null";
	_role = "null";
}

Officer::Officer(string name, string role)
{
	//username being set
	if(name.length() > 0)
	{
		_name = name;		//then also write this to file
	}
	else
	{
		cout << "No name entered. Name set to 'Default'.\n";
		_name = "Default";
	}
	
	//role being set
	if(role.length() > 0)
	{
		_role = role;
	}
	else
	{
		cout << "No role entered. Role set to 'default'\n";
		_role = "default";
	}
}


string Officer::getRole()
{
	return _role;
}

void Officer::setRole(string role)
{
	_role = role;
}

void Officer::setName(string newName)	//needs to have file opening ability
{
	_name = newName;
}

string Officer::getName()
{
	return _name;
}


Officer::~Officer()
{
}