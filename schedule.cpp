#include "schedule.hpp"
#include <set>
#include <vector>

using namespace ariel;
using std::set, std::vector;

schedule::schedule(vector<Team>::iterator begin, vector<Team>::iterator end, uint another_teams)
{
	for (;begin != end; ++begin)
		all_teams.push_back(*begin);
	number_of_teams = another_teams + all_teams.size();
	insert_new_random_teams();
}


//create random schedule for all teams
//each team play against all other teams twice: at home and away
void schedule::create(){
	//TODO
}

void schedule::play_all_games(){
	for (std::vector<game> round : all_games)
		for (game _game : round)
			_game.play();
}


