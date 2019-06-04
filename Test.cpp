/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
#include<set>
#include <map>
using namespace std;

#include "league.hpp"
#include "schedule.hpp"
#include "game.hpp"
#include "Team.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace ariel;

//return true if each team not played twice or more
bool is_valid_round(std::vector<game> &round) {

	//for compiling
	std::set<Team> teams_in_round;
	for (game _game : round){
		teams_in_round.insert(_game.home.first);
		teams_in_round.insert(_game.away.first);
	}
	return (round.size() == teams_in_round.size());
}

//return true if played exactly (n-1)*2 games
//n is the number of teams

bool played_exact_games(schedule &sch) {
	return ( (sch.all_teams.size()-1)*2 == sch.all_games.size());
}


bool is_all_played_against_all(schedule &sch) {
	//map every team to number
	std::map<Team, int> myMap;
	int count=0;
	for (Team t : sch.all_teams){
		myMap.emplace(t, count);
		count++;
	}

	int number_of_teams = sch.all_teams.size();
	//matrix of home team / away team.
	//played[i][j] is true if team i play against team j: i - home, j - away
	bool played[number_of_teams][number_of_teams];

	//intilze false
	for (int i=0; i<number_of_teams; i++)
		for (int j=0; j<number_of_teams; j++)
			played[i][j]=false;

	//set true if i played against j
	for (std::vector<game> round : sch.all_games)
		for (game _game : round)
			played[myMap.find(_game.home.first)->second][myMap.find(_game.away.first)->second]=true;

	for (int i=0; i<number_of_teams; i++)
		for (int j=0; j<number_of_teams; j++)
			if (i!=j && played[i][j]==false)
				return false;

	return true;
}


int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {


//testing Team!
	testcase.setname("Init teams");

	//Create teams with different names

	std::vector<Team> team_v;
	for (int i=0; i<20; i++){
		Team new_team =  Team();
		for (Team t : team_v)
			testcase.CHECK_EQUAL(t.name != new_team.name, true);
		team_v.push_back(new_team);
	}

	/*Create teams by pramameters
	skills should be in [0,1)*/

	testcase.CHECK_THROWS(Team(-0.01, "name1"))
	.CHECK_THROWS(Team(1, "name2"))
	.CHECK_OK(Team(0, "name3"))
	.CHECK_OK(Team(0.99, "name4"));


//testing game!
	testcase.setname("Play games");

	Team a_team(0, "a");
	Team b_team(0.7, "b");

	std::pair<Team&, int> a{a_team, 0};
	std::pair<Team&, int> b{b_team, 0};

	game my_game{a, b};

	testcase.CHECK_OK(my_game.play())
	//home team: [55,105) + 0*10
	.CHECK_EQUAL(my_game.home.second < 105, true)
	.CHECK_EQUAL(my_game.home.second >= 55, true)
	//away team: [50,100) + 0.7*10
	.CHECK_EQUAL(my_game.away.second < 107, true)
	.CHECK_EQUAL(my_game.away.second >= 57, true);
	

//testing schedule!
	testcase.setname("Set schedule");
	Team c_team(0.2, "c");
	Team d_team(0.5, "d");

	std::vector<Team> team_v2;
	team_v2.push_back(a_team);
	team_v2.push_back(b_team);
	team_v2.push_back(c_team);
	team_v2.push_back(d_team);

	schedule test_schedule(team_v2.begin(), team_v2.end());
	for (std::vector<game> round : test_schedule.all_games)
		testcase.CHECK_EQUAL(is_valid_round(round), true);

	testcase.CHECK_EQUAL(played_exact_games(test_schedule), true)
	.CHECK_EQUAL(is_all_played_against_all(test_schedule), true);
		

//testing league!
	testcase.setname("Set league");

	const int size = 4; //league with 4 teams

	league test_league(size);
	test_league.create();

	//test schedule as above
	for (std::vector<game> round : test_league.all_games)
		testcase.CHECK_EQUAL(is_valid_round(round), true);

	testcase.CHECK_EQUAL(played_exact_games(test_league), true)
	.CHECK_EQUAL(is_all_played_against_all(test_league), true);

	//test the total number of wins and loses in the league
	testcase.CHECK_OK(test_league.play());
	int total_win=0, total_lose=0;
	int total_games = test_league.size()*(test_league.size()-1);
	for (Team team : test_league._table()){
		total_win += team.win;
		total_lose += team.lose;
	}
	testcase.CHECK_EQUAL(total_win, total_games)
	.CHECK_EQUAL(total_lose, total_games);

	//basic test for top and bottom functions
	auto up_half = test_league.top(size/2);
	auto down_half = test_league.bottom(size/2);
	for (Team up_team : up_half)
		for (Team down_team : down_half){
			testcase.CHECK_EQUAL(up_team.name != down_team.name, true)
			.CHECK_EQUAL(up_team < down_team, false);
		}
	

	testcase.setname("Test my mini league");
	league test_league2(4);
	test_league2.all_teams.push_back(a_team);
	test_league2.all_teams.push_back(b_team);
	test_league2.all_teams.push_back(c_team);
	test_league2.all_teams.push_back(d_team);

	//set all results
	game game1_1{pair<Team&,int>(a_team,70), pair<Team&,int>(b_team,80)};
	game game1_2{pair<Team&,int>(c_team,70), pair<Team&,int>(d_team,65)};
	std::vector<game> round1;
	round1.push_back(game1_1);
	round1.push_back(game1_2);
	test_league2.all_games.push_back(round1);

	game game2_1{pair<Team&,int>(c_team,70), pair<Team&,int>(a_team,80)};
	game game2_2{pair<Team&,int>(d_team,70), pair<Team&,int>(b_team,65)};
	std::vector<game> round2;
	round2.push_back(game2_1);
	round2.push_back(game2_2);
	test_league2.all_games.push_back(round2);

	game game3_1{pair<Team&,int>(a_team,70), pair<Team&,int>(d_team,80)};
	game game3_2{pair<Team&,int>(b_team,70), pair<Team&,int>(c_team,65)};
	std::vector<game> round3;
	round3.push_back(game3_1);
	round3.push_back(game3_2);
	test_league2.all_games.push_back(round3);	

	game game4_1{pair<Team&,int>(b_team,70), pair<Team&,int>(a_team,80)};
	game game4_2{pair<Team&,int>(d_team,70), pair<Team&,int>(c_team,65)};
	std::vector<game> round4;
	round4.push_back(game4_1);
	round4.push_back(game4_2);
	test_league2.all_games.push_back(round4);

	game game5_1{pair<Team&,int>(a_team,70), pair<Team&,int>(c_team,80)};
	game game5_2{pair<Team&,int>(b_team,70), pair<Team&,int>(d_team,65)};
	std::vector<game> round5;
	round5.push_back(game5_1);
	round5.push_back(game5_2);
	test_league2.all_games.push_back(round5);

	game game6_1{pair<Team&,int>(d_team,75), pair<Team&,int>(a_team,90)};
	game game6_2{pair<Team&,int>(c_team,85), pair<Team&,int>(b_team,75)};
	std::vector<game> round6;
	round6.push_back(game6_1);
	round6.push_back(game6_2);
	test_league2.all_games.push_back(round6);

	testcase.CHECK_EQUAL(test_league2.longest_winnigs(), 3) //Team d in rounds 2-4
	.CHECK_EQUAL(test_league2.longest_losses(), 3) //Team c in rounds 2-4
	.CHECK_EQUAL(test_league2.count_positive(), 2); //Teams a,c

	

	auto up_half2 = test_league2.top(size/2);
	auto down_half2 = test_league2.bottom(size/2);
	for (Team up_team : up_half2)
		for (Team down_team : down_half2){
			testcase.CHECK_EQUAL(up_team.name != down_team.name, true)
			.CHECK_EQUAL(up_team < down_team, false);
		}
	
		
 
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
