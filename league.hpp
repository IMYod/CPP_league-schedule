#pragma once

#include<vector>
#include<set>
#include "schedule.hpp"
#include <iostream>


namespace ariel{


class league : public schedule{
	std::set<Team> table; //sorted by: 1. wins. 2. total points.

	public:

	league(uint number) : schedule(number) {;}

	league(std::vector<ariel::Team>::iterator begin, std::vector<ariel::Team>::iterator end, uint another_teams=0):
	schedule(begin, end, another_teams) {;}

	void play() {
		play_all_games();
		set_results_to_table();
	}

	void set_results_to_table();

	int size() const {return number_of_teams;}
	const std::set<Team>& _table() const {return table;}

	/*
	statistics functions
	*/

	std::vector<Team> top(uint) const;
	std::vector<Team> bottom(uint) const;

	int longest_winnigs() const {return 1; //TODO in cpp file
}
	int longest_losses() const {return 1; //TODO in cpp file
}
 
	uint count_positive() const {return 1; //TODO in cpp file
}

};

}
