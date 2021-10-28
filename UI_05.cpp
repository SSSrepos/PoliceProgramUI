#include <iostream>
#include "Riot.h"
#include "Sherrif.h"

using namespace std;

extern int startProgram();
extern void addCivilian(Civilian*& civilianArray, int* civilianArrayNum, int* civilianArraySize);
extern string listCivilians(Civilian* civilianArray, int num);
extern bool saveCivilians(Civilian* civilianArray, int civilianArrayNum);
extern string getCivilianName();
extern void pauseInput();

//Final version - all functions moved to seperate file
int main()
{
	system("clear");		//clear window
	string inputRole;
	Civilian* target;

	Sherrif userSherrif = Sherrif();
	Riot userRiot = Riot();

	Civilian* civilianArray = new Civilian[5];
	int civilianArraySize = 5;
	int civilianArrayNum = 0;

	int userRole;
	userRole = startProgram();
	

	//Controls riot officer's actions
	if(userRole == 1)
	{
		bool quit = false;
		int userAction = 0;

		//Loops through civilian's actions
		while (quit == false)
		{
			cout << endl << "Press enter to continue...";
			pauseInput();

			system("clear"); //Removes unnecesary info from terminal
			
			cout << "Enter an action from the choices below:" << endl;
			cout << "1 - Add a Civilian" << endl;
			cout << "2 - Arrest a civilian" << endl;
			cout << "3 - List civilians" << endl;
			cout << "4 - Quit" << endl;

			cin >> userAction;
			
			//Stops program from glitcing out with invalid input
			cin.clear();
			cin.ignore();

			
			switch(userAction)
			{
				case 1:	 //Add a Civilian
				{	
					system("clear"); //Removes unnecesary info from terminal

					addCivilian(civilianArray, &civilianArrayNum, &civilianArraySize);

					break;
				}

				case 2: //Arrest a civilian
				{
					system("clear");
					bool validName = false;
					
					//List Civilians to choose from
					cout << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" <<endl;
					for(int i=0; i<civilianArrayNum; i++)
					{
					cout << listCivilians(civilianArray, i);
					}
					cout << endl << endl;

					//Get input
					string civilianName = getCivilianName();


					//Checks given name against all Civilians in the system
					for(int i=0; i<civilianArrayNum; i++)
					{
						if(civilianName == civilianArray[i].getName())
						{
							validName = true;
							target = &civilianArray[i];
						}
					}

				if(validName == true)
				{
					userRiot.arrest(target);

					cout << target->getName() << " has been arrested by a sherrif.\n";
				}
					else
					{
						cout << "Invalid name entered!" << endl;
					}

					pauseInput();
					break;
				}

				case 3: //List Civilians
				{
					system("clear"); //Removes unnecesary info from terminal
					string userInput = "";

					cout << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" <<endl;

					for(int i=0; i<(civilianArrayNum); i++)
					{
					cout << listCivilians(civilianArray, i);
					}
					break;
				}

				case 4: //quit
				{
					saveCivilians(civilianArray, civilianArrayNum);
					pauseInput();
					system("clear");
					quit = true;
					break;
				}
			}
		}
	}





	//Sherrif section
	if(userRole == 2)
	{	
		bool quit = false;
		int userAction = 0;

		while (quit == false && userRole == 2)
		{		
			cout << endl << "Press enter to continue...";
			pauseInput();

			system("clear");

			cout << "Enter an action from the choices below:" << endl;
			cout << "1 - Add a Civilian" << endl;
			cout << "2 - Fine a civilian" << endl;
			cout << "3 - Arrest a civilian" << endl;
			cout << "4 - Fine payment" << endl;
			cout << "5 - List civilians" << endl;
			cout << "6 - Quit" << endl;
			
			cin >> userAction;
			
			//Stops program from glitcing out with invalid input
			cin.clear();
			cin.ignore();

			switch(userAction)
			{	
			//Add a Civilian to the system
				case 1:
				{	
					system("clear"); //Removes unnecesary info from terminal

					addCivilian(civilianArray, &civilianArrayNum, &civilianArraySize);

					break;
				}

				case 2:	//Fine a Civilian
				{
					system("clear");
					bool validName = false;
					int fineAmount = 0;

					//Print Civilians
					cout << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" <<endl;
					for(int i=0; i<(civilianArrayNum); i++)
					{
					cout << listCivilians(civilianArray, i);
					}
					cout << endl << endl;

					//Get input
					string civilianName = getCivilianName();

					//Checks given name against all Civilians in the system
					for(int i=0; i<civilianArrayNum; i++)
					{
						if(civilianName == civilianArray[i].getName())
						{
							validName = true;
							target = &civilianArray[i];
						}
					}

					//Only works if a civilian with given name exists in system
					if(validName == true)
					{
					cout << "How much do you want fine " << target->getName() << ": $";
					cin >> fineAmount;

					target->giveFine(fineAmount);

						if(fineAmount > 0)
						{
						cout << target->getName() << " has been fined $" << fineAmount << " by a sherrif.\n";
						}
					}
					else
					{
						cout << "Invalid name entered!" << endl;
					}

					pauseInput();
					break;
				}

				case 3:	//Arrest a civilian
				{	
					system("clear");
					bool validName = false;
					
					//List Civilians to choose from
					cout << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" <<endl;
					for(int i=0; i<civilianArrayNum; i++)
					{
					cout << listCivilians(civilianArray, i);
					}
					cout << endl << endl;

					//Get input
					string civilianName = getCivilianName();


					//Checks given name against all Civilians in the system
					for(int i=0; i<civilianArrayNum; i++)
					{
						if(civilianName == civilianArray[i].getName())
						{
							validName = true;
							target = &civilianArray[i];
						}
					}
				
				//Only works if a civilian with given name exists in system
				if(validName == true)
				{
					userSherrif.arrest(target);

					cout << target->getName() << " has been arrested by a sherrif.\n";
				}
					else
					{
						cout << "Invalid name entered!" << endl;
					}

					pauseInput();
					break;
				}

				
				case 4:	//Manage Fines
				{	
					system("clear");
					bool validName = false;
					int fineAmount = 0;

					//Print Civilians
					cout << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" <<endl;
					for(int i=0; i<(civilianArrayNum); i++)
					{
					cout << listCivilians(civilianArray, i);
					}
					cout << endl << endl;

					//Get input
					string civilianName = getCivilianName();

					//Checks given name against all Civilians in the system
					for(int i=0; i<civilianArrayNum; i++)
					{
						if(civilianName == civilianArray[i].getName())
						{
							validName = true;
							target = &civilianArray[i];
						}
					}

					//Only works if a civilian with given name exists in system
					if(validName == true)
					{
					cout << target->getName() << " owes $" << target->getFines() << endl;
					cout << "How much does " << target->getName() << " want to pay: $";
					cin >> fineAmount;

					bool fineSuccesful = target->payFine(fineAmount);

						if(fineSuccesful == true)
						{
						cout << target->getName() << " has payed $" << fineAmount << " and now owes $" << target->getFines() << endl;
						}
					}
					else
					{
						cout << "Invalid name entered!" << endl;
					}

					pauseInput();
					break;
				}

				case 5: //List civilians
				{
					system("clear"); //Removes unnecesary info from terminal
					string userInput = "";

					cout << "NAME:" <<"\t" << "FINES:" << "\t" << "CRIMINAL RECORD:" << "\t" <<"DETAINED:" <<endl;

					for(int i=0; i<(civilianArrayNum); i++)
					{
					cout << listCivilians(civilianArray, i);
					}
					break;
				}

				case 6:	//Quit procedure
				{
					quit = saveCivilians(civilianArray, civilianArrayNum);
					pauseInput();
					system("clear");
					break;
				}

				default: //Invalid input procedure
				{
					cout << "Invalid input. Try again.\n";
					pauseInput();
					break;
				}
			}
		}
	}

	delete[] civilianArray;
	return 0;
}