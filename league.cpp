#include "league.hpp"
#include <set>

using namespace ariel;
using std::vector;

league::league(vector<Team>::iterator begin, vector<Team>::iterator end, uint other_teams)
{
	for (;begin != end; ++begin)
		table.push_back(*begin);
	number_of_teams = other_teams + table.size();
}

void league::set_results_to_table(){
	;//TODO
}

/*
statistics functions
*/


//for compiling
std::vector<Team> league::top(uint num) const {
	return std::vector<Team>(table.begin(), table.begin() + num);
}

//for compiling
std::vector<Team> league::bottom(uint num) const{
	return std::vector<Team>(table.end() - num, table.end());
}
