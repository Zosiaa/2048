#include <iostream>
#include "Game.h"
#include <vector>
#define ENTER 13

using namespace std;

int main()
{

	Game gra;


	cout << "doard" << endl;
	gra.display_board();

	cout << "down" << endl;
	gra.move_down();
	gra.display_board();

	cout << "right" << endl;
	gra.move_right();
	gra.display_board();

	cout << "left" << endl;
	gra.move_left();
	gra.display_board();



	cout << "up" << endl;
	gra.move_up();
	gra.display_board();
	cout << "down" << endl;
	gra.move_down();
	gra.display_board();

	cout << "right" << endl;
	gra.move_right();
	gra.display_board();

	cout << "left" << endl;
	gra.move_left();
	gra.display_board();



	cout << "up" << endl;
	gra.move_up();
	gra.display_board();
	cout << "down" << endl;
	gra.move_down();
	gra.display_board();

	cout << "right" << endl;
	gra.move_right();
	gra.display_board();

	cout << "left" << endl;
	gra.move_left();
	gra.display_board();



	cout << "up" << endl;
	gra.move_up();
	gra.display_board();
	cout << "left" << endl;
	gra.move_left();
	gra.display_board();



	cout << "up" << endl;
	gra.move_up();
	gra.display_board();
	cout << "down" << endl;
	gra.move_down();
	gra.display_board();

	cout << "right" << endl;
	gra.move_right();
	gra.display_board();

	cout << "left" << endl;
	gra.move_left();
	gra.display_board();



	cout << "up" << endl;
	gra.move_up();
	gra.display_board();
	cout << "down" << endl;
	gra.move_down();
	gra.display_board();

	cout << "right" << endl;
	gra.move_right();
	gra.display_board();

	cout << "left" << endl;
	gra.move_left();
	gra.display_board();



	cout << "up" << endl;
	gra.move_up();
	gra.display_board();

	/*
	cout <<"\nSTART GAME!"<<endl;
	Game game;



	char hotkey;

	while(1)
	{
	game.display_board();
	cin >> hotkey;

	switch(hotkey)
	{
	case 72: game.move_up();
	case 80: game.move_down();
	case 77: game.move_right();
	case 75: game.move_left();
	case 27: return 0;
	}
	game.display_board();
	if(game.is_game_over())
	break;

	}

	cout<<"\nGAME OVER"<<endl;


	*/
	return 0;
}

