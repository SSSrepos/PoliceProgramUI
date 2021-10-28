#include "Sherrif.h"
#include "Civilian.h"
#include <iostream>
using namespace std;

int main()
{
	{
		cout << "Testing default constructor\n";
		
		Sherrif officer = Sherrif();
		cout << "Expected Result:\n";
		cout << "Officer name: null | Officer role: Sherrif\n";
		cout << "Actual result:\n";
		cout << "Officer name: " << officer.getName() << " | " << "Officer role: " << officer.getRole() << endl << endl;
	}
	cout << endl;
	{
		cout << "Testing paramter constructor\n";
		
		Sherrif officer = Sherrif("Tom");
		cout << "Expected Result:\n";
		cout << "Officer name: Tom | Officer role: Sherrif\n";
		cout << "Actual result:\n";
		cout << "Officer name: " << officer.getName() << " | " << "Officer role: " << officer.getRole() << endl << endl;
	}
	cout << endl;
	{
		cout << "Testing paramter constructor with no name (Edge case)\n"; 
		
		Sherrif officer = Sherrif("");
		cout << "Expected Result:\n";
		cout << "Officer name: | Officer role: Sherrif\n";
		cout << "Actual result:\n";
		cout << "Officer name: " << officer.getName() << " | " << "Officer role: " << officer.getRole() << endl << endl;
	}
	cout << endl;
	{
		cout << "Testing setRole()\n";
		Sherrif officer = Sherrif();
		cout << "Expected Result: Sherrif Captain\n";
		officer.setRole("Sherrif Captain");
		cout << "Actual Result: " << officer.getRole() << endl;
	}
	cout << endl;
	{
		cout << "Testing setRole() with blank input (Edge case)\n";
		Sherrif officer = Sherrif();
		cout << "Expected Result: \n";
		officer.setRole("");
		cout << "Actual Result: " << officer.getRole() << endl;
	}
	cout << endl;
	{
		cout << "Testing getRole()\n";
		Sherrif officer = Sherrif("bob");
		cout << "Expected result: test123\n";
		cout << "Actual result: " << officer.getRole() << endl;
	}
	cout << endl;
	{
		cout << "Testing setName()" << endl;
		Sherrif officer = Sherrif();

		cout << "standard case" << endl;
		officer.setName("Jeb");
		cout << "Expected result: Jeb\n";
		cout << "Actual result: " << officer.getName() << endl;
		
		cout << "Numbers only (Edge case)" << endl;
		officer.setName("123");
		cout << "Expected result: 123\n";
		cout << "Actual result: " << officer.getName() << endl;
	}
	cout << endl;
	{
		cout << "Testing getName()\n";
		Sherrif officer1 = Sherrif();
		Sherrif officer2 = Sherrif("Bob");
		cout << "Expected Result for officer1: null\n";
		cout << "Actual result for officer1: " << officer1.getName() << endl;
		cout << "Expected Result for officer2: Bob\n";
		cout << "Actual result for officer2: " << officer2.getName() << endl;
		
	}
	cout << endl;
	{
		cout << "Testing arrest function\n";
		
		Sherrif officer = Sherrif("Bob");
		Civilian target = Civilian("Janet");
		bool action = officer.arrest(&target);
		cout << "Expected Result: 1 1\n";
		cout << "Actual result: ";
		if(action == true)
		{
			cout << target.getDetained() << " " << target.getCriminalRecord() << endl << endl;
		}
		else
		{
			cout << " Error - arrest failed.";
		}
	}
	
	return 0;
}