#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <string>
#include <vector>
using namespace std;

class Team {
	public:
		Team();
		~Team(); // Required per rubric.
		vector<Player*> teamRosterVec;
		void parse(string obj);
		void add(string pID, string name_First, string name_Last, string email, int age, int rbi1, int rbi2, int rbi3, Position position);
		void remove(string pID);
		void printAll();
		void printAverageRBI(string pID);
		void printInvalidEmail();
		void printByPosition(Position position);
};

#endif