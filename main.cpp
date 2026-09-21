#include "team.h"
#include <iostream>
using namespace std;

int main() {

    const string playerInfo[] =
    {
    "STAR1,John,Doe,example@mail .com,34,15,12,32,CATCHER",
    "STAR2,Jane,Doe,jdoe@mailcom,21,35,24,11,PITCHER",
    "STAR3,Jack,Doe,jack_doemail.com,31,24,36,21,PITCHER",
    "STAR4,Jill,Doe,Jill.doe@mail.net,41,52,31,31,SHORTSTOP",
    "STAR5,Jim,Doe,Jim.doe@mail.net,21,36,21,21,SHORTSTOP",
    };

    cout << "Example Project" << endl;
    cout << "Language: C++" << endl;
    cout << endl;

    int numPlys = 5;
    Team teamRoster;

    for (int i = 0; i < numPlys; ++i) {
        teamRoster.parse(playerInfo[i]);
    }

    teamRoster.printAll();
    teamRoster.printInvalidEmail();

    cout << "Average RBI" << endl;
    for (int i = 0; i < teamRoster.teamRosterVec.size(); ++i) {
        teamRoster.printAverageRBI(teamRoster.teamRosterVec.at(i)->getID());
    }
    cout << endl;

    teamRoster.printByPosition(PITCHER);
    teamRoster.remove("STAR3");
    teamRoster.printAll();
    teamRoster.remove("STAR3");
    teamRoster.~Team();

    return 0;
};

