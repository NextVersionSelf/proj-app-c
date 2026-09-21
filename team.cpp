#include "team.h"
#include <array>
#include <string>
#include <iostream>
using namespace std;

Team::Team() {};

void Team::add(string pID, string name_First, string name_Last, string email, int age, int rbi1, int rbi2, int rbi3, Position position) {
	vector<int> rbiVec = { rbi1, rbi2, rbi3 };
	Player* player = new Player(); // External access requirements. 
	player->setID(pID);
	player->setNameFirst(name_First);
	player->setNameLast(name_Last);
	player->setAge(age);
	player->setEmail(email);
	player->setrbiCount(rbiVec);
	player->setPosition(position);
	Team::teamRosterVec.push_back(player);
}

void Team::remove(string pID) {
	bool found = false;
	for (int i = 0; i < teamRosterVec.size(); ++i) {
		if (teamRosterVec.at(i)->getID() == pID) {
			found = true;
			teamRosterVec.erase(teamRosterVec.begin() + i); //.Erase for removal + automatic shift of elements.
			cout << "Player with ID " + pID + " was removed from the team!" << endl;
			cout << endl;
			break;
		}
	}

	if (found == false) {
		cout << "Error: Player with ID " + pID + " was not found!" << endl;
	}
}

void Team::parse(string obj) {
	
	//ID
	size_t rhs = obj.find(",");
	string tarID = obj.substr(0, rhs); //Not inclusive of last index.

	//First
	size_t lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	string tarNameFirst = obj.substr(lhs, rhs - lhs);

	//Last
	lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	string tarNameLast = obj.substr(lhs, rhs - lhs);

	//Email
	lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	string tarEmail = obj.substr(lhs, rhs - lhs);

	//Age
	lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	int tarAge = stoi(obj.substr(lhs, rhs - lhs)); //String to int, will ignore characters other than nums

	//rbi1
	lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	int tarRbi1 = stoi(obj.substr(lhs, rhs - lhs)); 

	//rbi2
	lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	int tarRbi2 = stoi(obj.substr(lhs, rhs - lhs));

	//rbi3
	lhs = rhs + 1;
	rhs = obj.find(",", lhs);
	int tarRbi3 = stoi(obj.substr(lhs, rhs - lhs));

	//Position
	Position position;
	lhs = rhs + 1;
	string tarPosition = obj.substr(lhs, rhs - lhs);

	if (tarPosition == "CATCHER") {
		position = CATCHER;
	}
	else if (tarPosition == "PITCHER") {
		position = PITCHER;
	}
	else if (tarPosition == "SHORTSTOP") {
		position = SHORTSTOP;
	}
	else {
		position = UNASSIGNED;
	}

	//Populate vector
	add(tarID, tarNameFirst, tarNameLast, tarEmail, tarAge, tarRbi1, tarRbi2, tarRbi3, position);
}

void Team::printAll() {
	for (int i = 0; i < teamRosterVec.size(); ++i) {
		teamRosterVec.at(i)->Player::print();
	}
	cout << endl;
}

void Team::printAverageRBI(string pID) {
	int total = 0;
	double totalAverage = 0.0;

	for (int i = 0; i < teamRosterVec.size(); ++i) {
		if (teamRosterVec.at(i)->getID() == pID) {
			total = teamRosterVec.at(i)->getrbiCount()[0] + teamRosterVec.at(i)->getrbiCount()[1] + teamRosterVec.at(i)->getrbiCount()[2];
			totalAverage = total / 3.0;
			cout << teamRosterVec.at(i)->getID() << ": " << totalAverage << endl;
		}
	}
}

void Team::printInvalidEmail() {
	for (int i = 0; i < teamRosterVec.size(); ++i) {
		string testStr = teamRosterVec.at(i)->getEmail();

		if (testStr.contains(" ") || not testStr.contains("@") || not testStr.contains(".")) { //.Contains available in C++ 23.
			cout << "Invalid Email: " + testStr << endl;

		}
	}
	cout << endl;
}

void Team::printByPosition(Position position) {
	cout << "Position" << endl;
	for (int i = 0; i < teamRosterVec.size(); ++i) {
		if (teamRosterVec.at(i)->getPosition() == position) {
			teamRosterVec.at(i)->Player::print();
		}
	}
	cout << endl;
}

Team::~Team() {
	for (int i = 0; i < teamRosterVec.size(); ++i) {
		delete teamRosterVec.at(i);
	}
}