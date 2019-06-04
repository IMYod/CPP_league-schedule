#!make -f

all: demo
	./$<

demo:  Demo.o Team.o game.o schedule.o league.o
	clang++-6.0 -std=c++17 $^ -o demo

test:  Test.o Team.o game.o schedule.o league.o
	clang++-6.0 -std=c++17 $^ -o test

%.o: %.cpp Team.hpp game.hpp schedule.hpp league.hpp
	clang++-6.0 -std=c++17 --compile $< -o $@

league.o: schedule.o league.hpp league.cpp
	clang++-6.0 -std=c++17 -c league.cpp

schedule.o: game.o schedule.hpp schedule.cpp
	clang++-6.0 -std=c++17 -c schedule.cpp

game.o: Team.o game.hpp game.cpp
	clang++-6.0 -std=c++17 -c game.cpp

Team.o: Team.hpp Team.cpp
	clang++-6.0 -std=c++17 -c Team.cpp

clean:
	rm -f *.o demo test

