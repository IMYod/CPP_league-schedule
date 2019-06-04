#pragma once

#include<vector>
#include "schedule.hpp"

namespace ariel{


class league : public schedule{
	int number_of_teams;
	std::vector<Team> table; //sorted by: 1. wins. 2. total points.

	public:

	league(uint number) : number_of_teams(number) {;}

	league(std::vector<ariel::Team>::iterator begin, std::vector<ariel::Team>::iterator end, uint more_teams=0);

	void create_league(){
		//If we should init new teams, it will be done in this loop:
		for (int i=table.size(); i<number_of_teams; i++)
			//TODO
		create(table);
	}

	void play() {
		play_all_games();
		set_results_to_table();
	}

	void set_results_to_table();

	int size() const {return number_of_teams;}
	const std::vector<Team>& _table() const {return table;}

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
