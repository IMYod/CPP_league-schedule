#include "schedule.hpp"
#include <set>
#include <vector>

using namespace ariel;
using std::set, std::vector;

//create random schedule
//each team play against all other teams twice: at home and away
void schedule::create(vector<Team> teams){
	//TODO
}

void schedule::play_all_games(){
	for (std::vector<game> round : all_games)
		for (game _game : round)
			_game.play();
}


