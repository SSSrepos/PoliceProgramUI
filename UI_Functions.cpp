#include <iostream>
#include <fstream>
#include "Officer.h"
#include "Riot.h"
#include "Sherrif.h"

using namespace std;


int startProgram()
{
	//start program
	cout << "Police Station Records\n";
	bool done = false;
	int inputRole;
	int counter = 0;

	//Allows users to input their role
	while (done == false)
	{	
		cout << "Enter your role type:" << endl;
		cout << "1 - Sherrif" << endl;
		cout << "2 - Riot" << endl;
		
		if(counter > 0)
		{
		cin.clear(); //Reset the flags, so cin can be used again if it fails
		cin.ignore(); //Empty the buffer
		}
		
		cin >> inputRole;

		system("clear");

		//Ask for role type
		if(inputRole == 2)
		{
			return 1;
		}
		else if(inputRole == 1)
		{
			return 2;
		}

		//Stops error from occuring if user enters incorrect role
		else
		{
			counter++;
			cout << "Invalid role entered. Try again\n";
		}
	}
	return 1;
}

//A function to add a new civilian to the system
void addCivilian(Civilian*& civilianArray, int* civilianArrayNum, int* civilianArraySize)
{
	//get name for civilian
	string newCivilianName;
	bool validName = true;
	cout << "Enter Civilian Name: ";
	
	getline(cin, newCivilianName);

	//double size of array if space runs out
	if(*civilianArrayNum >= *civilianArraySize-1)
	{
		//Transfer Civilians into temp array
		Civilian* tempArray = new Civilian[*civilianArraySize];
		
		for(int i=0; i<*civilianArrayNum; i++)
		{
		tempArray[i] = civilianArray[i];
		}

		//double civilianArray size
		*civilianArraySize *= 2;

		delete[] civilianArray;

		Civilian* civilianArray2 = new Civilian[*civilianArraySize];

		civilianArray = civilianArray2;

		//Transfer values back into civilianArray
		for(int i=0; i<*civilianArrayNum; i++)
		{
		civilianArray[i] = tempArray[i];
		}

		delete[] tempArray;
	}

	if(*civilianArrayNum < *civilianArraySize)
	{
		for(int i=0; i<*civilianArrayNum; i++)
		{
			if(civilianArray[i].getName() == newCivilianName)
			{
				cout << "There is already a civilian with that name!" << endl;
				validName = false;
				break;
			}
		}

		if(validName == true)
		{
		civilianArray[*civilianArrayNum] = Civilian(newCivilianName); //Create new civilian and add to array
		cout << "Added new civilian called " << civilianArray[*civilianArrayNum].getName() << endl;

		*civilianArrayNum = *civilianArrayNum + 1; //Increase civilianArrayCounter
		}
	}
	return;
}

//A function to print a list of all Civilians in the system
string listCivilians(Civilian* civilianArray, int num)
{
	string newString = civilianArray[num].getName() + "\t $" + to_string(civilianArray[num].getFines()) + "\t" + to_string(civilianArray[num].getCriminalRecord()) + "\t\t\t" + to_string(civilianArray[num].getDetained()) + "\n";
	return newString;
}

//Saves a new text file to directory
bool saveCivilians(Civilian* civilianArray, int civilianArrayNum)
{
	system("clear");
	ofstream fileHandler;
	string outputText;
	string fileName;

	cout << "Saving your civilians!\nEnter file name: ";
	getline(cin, fileName);

	//file open and print to file
	fileHandler.open(fileName);
	
	// Keep reading the file
	if(fileHandler.is_open() == true)
	{
		fileHandler << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" << "\n";

		for(int i=0; i<civilianArrayNum; i++)
		{
		outputText = listCivilians(civilianArray, i);
		fileHandler << outputText;
		}

		fileHandler.close();

		cout << endl << "Saved your civilian data to a file called " << fileName << endl << endl;
		cout << "Press enter to quit: ";
		return true;
	}

	return false;
}


//Function to get a civilians name
string getCivilianName()
{
	string civilianName;

	//User enters a civilian
	cout << "Enter name of target: ";
	cin >> civilianName;

	return civilianName;
}

//Pauses the stream until user presses enter
void pauseInput()
{
	cin.clear();
	cin.ignore(); //Empty the buffer

	return;
}