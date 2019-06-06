#pragma once
#include "Team.hpp"

namespace ariel{

struct game{
	std::pair<Team&, int> home;
	std::pair<Team&, int> away;
	
	void play();
	//Results in game are randomized with normal distribution
	//For home team the result is integer in [55,105)
	//For away team the result is integer in [50,100)
	//Finaly, add to the results (skills*10) for each team respectively
	//See: http://www.cplusplus.com/reference/random/normal_distribution/
	//Choose parameters as you want
};

} 
