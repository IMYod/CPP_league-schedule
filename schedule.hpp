#pragma once

#include<vector>
#include "game.hpp"

namespace ariel{

struct schedule{

	std::vector<Team> all_teams;
	std::vector<std::vector<game>> all_games;

	//create random shedule
	//each team play against each other group twice: at home and away
	//	each element in round is set of games:
	//	each team appears only one time on each round
	//	hint: https://en.wikipedia.org/wiki/Round-robin_tournament
	void create(std::vector<Team>);

	void play_all_games();
		
};


}
