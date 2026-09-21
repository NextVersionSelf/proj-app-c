#include "player.h"
#include <string>
#include <array>
#include <iostream>
#include <print> // https://en.cppreference.com/cpp/io/basic_ostream/println https://en.cppreference.com/cpp/utility/format/spec
using namespace std;

//Default
Player::Player() {
	playerID = "NA";
	playerNameFirst = "NA";
	playerNameLast = "NA";
	playerEmail = "NA";
	playerAge = 0;
	rbiCount = { 0,0,0 };
	playerPosition = UNASSIGNED;
}

Player::Player(string pID, string name_First, string name_Last, string email, int age, vector<int> rbi_Count, Position position) {
	playerID = pID;
	playerNameFirst = name_First;
	playerNameLast = name_Last;
	playerEmail = email;
	playerAge = age;
	
	for (int i = 0; i < rbi_Count.size(); ++i) {
		rbiCount.at(i) = rbi_Count.at(i);
	};

	playerPosition = position;

}

//Getters
string Player::getID() const {
	return playerID;
}

string Player::getNameFirst() const {
	return playerNameFirst;
}

string Player::getNameLast() const {
	return playerNameLast;
}

string Player::getEmail() const {
	return playerEmail;
}

int Player::getAge() const {
	return playerAge;
}

vector<int> Player::getrbiCount() const {
	return rbiCount;
}

Position Player::getPosition() const {
	return playerPosition;
}

//Setters
void Player::setID(string pID) {
	playerID = pID;
}

void Player::setNameFirst(string name_First) {
	playerNameFirst = name_First;
}

void Player::setNameLast(string name_Last) {
	playerNameLast = name_Last;
}

void Player::setEmail(string email) {
	playerEmail = email;
}

void Player::setAge(int age) {
	playerAge = age;
}

void Player::setrbiCount(vector<int> rbi_Count) {
	for (int i = 0; i < rbi_Count.size(); ++i) {
		rbiCount.at(i) = rbi_Count.at(i);
	}
}

void Player::setPosition(Position position) {
	playerPosition = position;
}

void Player::print() { //Originally if/else statements, replaced after learning switch was available
	int posIdx = getPosition();
	string posVal;

	switch (posIdx) {
		case 0:
			posVal = "CATCHER";
			break;
		case 1:
			posVal = "PITCHER";
			break;
		case 2:
			posVal = "SHORTSTOP";
			break;
		default:
			posVal = "UNASSIGNED";
	}

	println("{}\tFirst: {:<5}\tLast: {:<5}\tEmail: {:<20}\tAge: {:>3}\tRBI: [{}, {}, {}]\tPosition: {}",
		getID(), getNameFirst(), getNameLast(), getEmail(), getAge(),
		rbiCount[0], rbiCount[1], rbiCount[2], posVal);
}