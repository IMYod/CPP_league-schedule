#pragma once

#include <string>

namespace ariel{

struct Team{
	const double skills; //[0,1)
	const std::string name;
	uint win = 0, lose = 0;
	int total_points = 0; // for winnig with the result 80-70 -> set +10

	//generates team with random skills and name
	Team();

	/*For compiling*/
	bool operator< (const Team &other) const;
	Team(double _skills, std::string _name): skills(_skills), name(_name) {;}
};

}
