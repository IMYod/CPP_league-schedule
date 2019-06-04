#pragma once

#include<vector>
#include "game.hpp"

namespace ariel{

struct schedule{

	int number_of_teams;
	std::vector<Team> all_teams;
	std::vector<std::vector<game>> all_games;

	schedule(uint number) : number_of_teams(number) {
		insert_new_random_teams();
	}

	schedule(std::vector<Team>::iterator begin, std::vector<Team>::iterator end, uint another_teams=0);

	void insert_new_random_teams() {
		//If we should init new teams, it will be done in this loop:
		for (int i=all_teams.size(); i<number_of_teams; i++)
			;//TODO
	}

	//create random shedule
	//each team play against each other group twice: at home and away
	//	each element in round is set of games:
	//	each team appears only one time on each round
	//	hint: https://en.wikipedia.org/wiki/Round-robin_tournament
	void create();

	void play_all_games();
		
};


}
