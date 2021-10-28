#Change this to compiler -- either g++ or clang++
  CC = g++
 
  MAIN = Civilian-test.cpp
  CIVILIAN = Civilian.cpp

all: Civilian UI

Civilian: $(MAIN) $(CIVILIAN)
	#Compiling Civilian
	$(CC) $(MAIN) $(CIVILIAN) -o CivilianTest
	#Running Tests
	./CivilianTest < Civilian-input.txt

#Compiling the Riot test file
RiotTest: Civilian.cpp Riot.cpp Officer.cpp RiotTest.cpp
	$(CC) Civilian.cpp Riot.cpp Officer.cpp RiotTest.cpp -o RiotTest
#Compiling the Sherrif test file
SherrifTest: Sherrif.cpp Civilian.cpp Officer.cpp SherrifTest.cpp
	$(CC) Sherrif.cpp Civilian.cpp Officer.cpp SherrifTest.cpp -o SherrifTest

#Use this command for final build
UI5: UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp					
	$(CC) UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_05

#Test file for final build
Test-UI5: UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_05
