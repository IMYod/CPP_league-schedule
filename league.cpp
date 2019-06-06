#include "league.hpp"
#include <set>
#include <iterator>


using namespace ariel;
using std::vector;

void ariel::league::set_results_to_table(){
	//TODO
}

/*
statistics functions
*/


/*for compiling*/
vector<Team> league::top(uint num) const {
	if (num > table.size())
		return vector<Team>(table.begin(), table.end());

	auto it = table.begin();
	std::advance(it, num);
	return std::vector<Team>(table.begin(), it) ;
}

/*for compiling*/
vector<Team> league::bottom(uint num) const{
	if (num > table.size())
		return vector<Team>(table.begin(), table.end());

	auto it = table.begin();
	std::advance(it, table.size()-num);
	return vector<Team>(it, table.end()) ;
}



