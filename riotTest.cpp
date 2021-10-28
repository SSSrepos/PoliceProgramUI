#include "Riot.h"
#include <iostream>
using namespace std;

int main()
{
	{
		cout << "Testing default constructor\n";
		
		Riot officer = Riot();
		cout << "Expected Result:\n";
		cout << "Officer name: null | Officer role: Riot\n";
		cout << "Actual result:\n";
		cout << "Officer name: " << officer.getName() << " | " << "Officer role: " << officer.getRole() << endl << endl;
	}
	cout << endl;
	{
		cout << "Testing setRole()\n";
		Riot officer = Riot();
		cout << "Expected Result: Riot Captain\n";
		officer.setRole("Riot Captain");
		cout << "Actual Result: " << officer.getRole() << endl;
	}
	cout << endl;
	{
		cout << "Testing setRole() with no parameter (Edge case)\n";
		Riot officer = Riot();
		cout << "Expected Result: Riot Captain\n";
		officer.setRole("");
		cout << "Actual Result: " << officer.getRole() << endl;
	}
	cout << endl;
	{
		cout << "Testing getRole()\n";
		Riot officer = Riot("bob", "test123");
		cout << "Expected result: test123\n";
		cout << "Actual result: " << officer.getRole() << endl;
	}
	cout << endl;
	{
		cout << "Testing setName()\n";
		Riot officer = Riot();
		//Reasonable case
		officer.setName("Jeb");
		cout << "Expected result: Jeb\n";
		cout << "Actual result: " << officer.getName() << endl;
		//numbers only
		officer.setName("123");
		cout << "Expected result: 123\n";
		cout << "Actual result: " << officer.getName() << endl;
	}
	cout << endl;
	{
		cout << "Testing getName()\n";
		Riot officer1 = Riot();
		Riot officer2 = Riot("Bob", "Riot Party Officer");
		cout << "Expected Result for officer1: null\n";
		cout << "Actual result for officer1: " << officer1.getName() << endl;
		cout << "Expected Result for officer2: Bob\n";
		cout << "Actual result for officer2: " << officer2.getName() << endl;
		
	}
	cout << endl;
	{
		cout << "Testing specific constructor\n";
		
		Riot officer = Riot("Bob", "Riot");
		cout << "Expected Result:\n";
		cout << "Officer name: Bob | Officer role: Riot\n";
		cout << "Actual result:\n";
		cout << "Officer name: " << officer.getName() << " | " << "Officer role: " << officer.getRole() << endl << endl;
	}
	cout << endl;
	{
		cout << "Testing arrest function\n";
		
		Riot officer = Riot("Bob", "Riot");
		Civilian target = Civilian("Janet");
		bool action = officer.arrest(&target);
		cout << "Expected Result: 1\n";
		cout << "Actual result: ";
		if(action == true)
		{
			cout << target.getDetained() << endl << endl;
		}
		else
		{
			cout << " Error - arrest failed.";
		}
	}
	
	
	return 0;
}