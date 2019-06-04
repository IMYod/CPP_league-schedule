#include "game.hpp"
#include <iostream>
#include <string>
#include <random>

using namespace ariel;

/*For compiling*/
int generate_result() { //in [0,50]
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(25.0,10.0);

	double number = distribution(generator);
	if (number<0)
		number = 0;
	else if (number>=50)
		number = 49;
	return int(number);
}

	//The results are randomized with normal distribution
	//For home team the result is integer in [55,105)
	//For away team the result is integer in [50,100)
	//Finaly, add to the results (skills*10) for each team respectively
	//See: http://www.cplusplus.com/reference/random/normal_distribution/

/*For compiling*/
void game::play() {
	home.second = generate_result() + 5 + 10*(home.first.skills);
	away.second = generate_result() + 10*(away.first.skills);
}

