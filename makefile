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

Officer: Officer.cpp Sherrif.cpp Civilian.cpp sherrifTest.cpp
	$(CC) Officer.cpp Sherrif.cpp Civilian.cpp sherrifTest.cpp -o officer

Riot: Officer.cpp  Civilian.cpp Riot.cpp riotTest.cpp
	$(CC) Officer.cpp  Civilian.cpp Riot.cpp riotTest.cpp -o riot

Sherrif: Sherrif.cpp sherrifTest.cpp Officer.cpp  Civilian.cpp
	$(CC) Sherrif.cpp sherrifTest.cpp Officer.cpp  Civilian.cpp -o sherrif

RiotTest: Civilian.cpp Riot.cpp Officer.cpp RiotTest.cpp
	$(CC) Civilian.cpp Riot.cpp Officer.cpp RiotTest.cpp -o RiotTest

SherrifTest: Sherrif.cpp Civilian.cpp Officer.cpp SherrifTest.cpp
	$(CC) Sherrif.cpp Civilian.cpp Officer.cpp SherrifTest.cpp -o SherrifTest


UI0: UI_00.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_00.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_00

UI1: UI_01.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_01.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_01

UI2: UI_02.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_02.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_02

UI3: UI_03.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_03.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_03

UI4: UI_04.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_04.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_04

#Use this command for final build
UI5: UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp					
	$(CC) UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_05


Test-UI1: UI_01.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_01.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_01_Test
	./UI_01_Test < UI_01Input1.txt

Test-UI2: UI_02.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_02.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_02_Test

Test-UI3: UI_03.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_03.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_03_Test

Test-UI4: UI_04.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_04.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_04_Test

#Test file for final build
Test-UI5: UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp
	$(CC) UI_05.cpp UI_Functions.cpp Civilian.cpp Sherrif.cpp Riot.cpp Officer.cpp -o UI_05