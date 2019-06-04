#include "Team.hpp"

#include <stdlib.h> //for rand
#include <sstream> //for ostringstream
#include <vector>
#include <string>

using namespace ariel;
using std::vector, std::string;

//generate at least 20 different team names
struct team_names_generator {
	vector<string> pre = {"Maccabi", "Happoel", "Elizoor", "Irony"};
	vector<string> city = {"Tel Aviv", "Jerusalem", "Haipha", "Ariel", "Be'er Sheva"};
	int index = 0;

	/*For compiling*/
	string operator()() {
		std::ostringstream name;
		name << pre[index%pre.size()] << " " << city[(index/pre.size())%city.size()];
		index++;
		return name.str();
	}
};

static team_names_generator static_names_generator;

Team::Team():
	skills(std::rand()),
	name(static_names_generator()) {;}

/*For compiling*/
bool Team::operator< (const Team &other) const{
	if (win < other.win)
		return true;
	if (win > other.win)
		return false;
	return (total_points < other.total_points);
}
