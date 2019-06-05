#include <iostream>

#include "league.hpp"
#include "schedule.hpp"
#include "game.hpp"
#include "Team.hpp"

using namespace ariel;
using std::endl, std::cout;

int main() {
	

	league ariel_league(12); //league with 12 teams
	ariel_league.create();
	ariel_league.play();

	/*cout << "The winner is " << ariel_league.top(1) << endl;
	cout << "This groups continued to the final four: " << ariel_league.top(4) << endl;
	cout << "This groups have been relegated: " << ariel_league.bottom(2) << endl;*/

	int longest_winnig = ariel_league.longest_winnigs();
	cout << "The longest winnig streak was " << longest_winnig << endl;
	cout << "The longest loss sequence was " << ariel_league.longest_losses() << endl;

	cout << "There are " << ariel_league.count_positive() << " teams with positive total points" << endl;


	//Let play the final four!
	auto top4 = ariel_league.top(4);

	league final4(top4.begin(), top4.end());
	final4.create();
	final4.play();
	
	cout << "The winner of the final four is: " << final4.top(1) << endl;


	//League with some specipic teams
	Team t1 = Team(0.85, "Toronto Raptors");	
	Team t2 = Team(0.9, "Golden State Warriors");
	std::vector<Team> some_teams;
	some_teams.push_back(t1);
	some_teams.push_back(t2);
	league NBA(some_teams.begin(), some_teams.end(), 6);

	return 0;	
}
