//////////////////////////////////////////////////////
//JHXie Game Excitation                             //
//////////////////////////////////////////////////////
#if !defined(MainHeaderHpp_Included)
#define MainHeaderHpp_Included

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

class Player;
class Game;	

class Player{
public:
	int score=0;
};

class Game{
public:
	static vector<int> Card_board;
	static vector<string> Process;
	static Player P1;
	static Player P2;
	static void generating_pattern();
	static void init();
	static void execute();
	static void finish();
};

#endif