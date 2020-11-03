//////////////////////////////////////////////////////
//JHXie Game Excitation                             //
//////////////////////////////////////////////////////
#include "MainHeader.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <math.h> 
#include <algorithm>
#include <cstdlib>
#include <array>

#define Card_position_file "card_position.txt"
#define Process_file "process.txt"
#define Score_file "score.txt"
#define Number_of_Pattern 10000

using namespace std;

vector<int> Game::Card_board;
vector<string> Game::Process;

Player Game::P1;
Player Game::P2;

void Game::generating_pattern(){
	//cout << "start...\n";
	for(int i=0;i<Number_of_Pattern;i++){
		//cout << "pattern: " << i <<endl;
		Game::init();
		Game::execute();
		Game::finish();
	}
	cout<< "done!\n";
}

void Game::init(){
	//cout << "init...\n";
	Card_board.clear();
 	Process.clear();
 	for(int i=0;i<18;i++){
 		Card_board.push_back(floor(i/2));
 	}
 	Card_board.push_back(9);
 	Card_board.push_back(10);
	random_shuffle(Card_board.begin(), Card_board.end());
}

void Game::execute(){
	//cout << "execute...\n";
	int flag=0;
	int first_choose;
	int second_choose;
	int on[20]={0};
	Player* master=NULL;
	while((P1.score<5)&&(P2.score<5)){
		master=(flag==0)?&P1:((flag==1)?&P2:NULL);
		first_choose=rand()%20;
		Process.push_back(to_string(first_choose));
		second_choose=rand()%20;
		Process.push_back(to_string(second_choose));
		if((Card_board[first_choose]==Card_board[second_choose])&&\
			(on[first_choose]!=-1)&&(on[second_choose]!=-1)){
			master->score=master->score+1;
			on[first_choose]=-1;
			on[second_choose]=-1;
		}
		flag=(flag==1)?0:1;
	}
}

void Game::finish(){
	//cout << "finish...\n";
	string card_position="";
	string select_position="";
	for(int i=0;i<Card_board.size();i++){
		card_position=card_position+to_string(Card_board[i])+" ";
	}
	for(int i=0;i<Process.size();i++){
		select_position=select_position+Process[i]+" ";
	}
	ofstream out_cardboard;
	ofstream out_process;
	ofstream out_score;
	out_cardboard.open(Card_position_file, ofstream::out | ofstream::app);
	out_cardboard << card_position << "\n";
	out_cardboard.close();
	out_process.open(Process_file, ofstream::out | ofstream::app);
	out_process << select_position << "\n";
	out_process.close();
	out_score.open(Score_file, ofstream::out | ofstream::app);
	out_score << P1.score << " " << P2.score << "\n";
	out_score.close();
	P1.score=0;
	P2.score=0;
}