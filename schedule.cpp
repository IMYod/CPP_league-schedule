#include "schedule.hpp"
#include <vector>

using namespace ariel;
using std::vector;

schedule::schedule(vector<Team>::iterator begin, vector<Team>::iterator end, uint another_teams)
{
	for (;begin != end; ++begin)
		all_teams.push_back(*begin);
	number_of_teams = another_teams + all_teams.size();
	insert_new_random_teams();
}

/*For compiling*/
void schedule::create(){
	//TODO
}

/*For compiling*/
void schedule::play_all_games(){
	for (std::vector<game> round : all_games)
		for (game _game : round)
			_game.play();
}


