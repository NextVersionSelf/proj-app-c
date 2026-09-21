#ifndef PLAYER_H
#define PLAYER_H
#include "position.h"
#include <string>
#include <vector>
using namespace std;

class Player {
	public:
		Player();
		Player(string pID, string name_First, string name_Last, string email, int age, vector<int> rbi_Count, Position position);

		//Getters
		string getID() const;
		string getNameFirst() const;
		string getNameLast() const;
		string getEmail() const;
		int getAge() const;
		vector<int> getrbiCount() const;
		Position getPosition() const;

		// Setters
		void setID(string pID);
		void setNameFirst(string name_First);
		void setNameLast(string name_Last);
		void setEmail(string email);
		void setAge(int age);
		void setrbiCount(vector<int> rbi_Count);
		void setPosition(Position position);

		// Print
		void print();

	private:
		string playerID;
		string playerNameFirst;
		string playerNameLast;
		string playerEmail;
		int playerAge;
		vector<int> rbiCount;
		Position playerPosition;
};

#endif