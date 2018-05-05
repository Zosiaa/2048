#pragma once
#include "Game.h"


using namespace std;

Game::Game() :board()
{

	fill_board();

}

void Game::fill_board()
{
	unsigned seed = static_cast <int> (chrono::system_clock::now().time_since_epoch().count());
	default_random_engine generator (seed);

	uniform_int_distribution <int> distribution(0, 3);
	uniform_int_distribution <int> distribution1(0, 10);

	for (int i = 0; i < 2; i++)
	{
		int pickedRow = distribution(generator);
		int pickedCol = distribution(generator);
		int pickedNumber = distribution1(generator);

		if(pickedNumber%3 == 0)
		   board(pickedRow, pickedCol) = 4;
		else
			board(pickedRow, pickedCol) = 2;

	}



}

void Game::display_board()
{
    for(size_t i = 0; i < board.height(); ++i)
    {
            for(size_t j = 0; j < board.width(); ++j)
            {
                 cout << board(i, j) << " ";
	        }

	    cout << '\n';
    }
}



bool Game::is_there_any_field_letf()
{
    for(int i=0; i < board.height(); ++i)
    {
        for(int j=0; j < board.width(); ++j)
        {
            if(board(i,j) != 0)
                return false;
        }
    }

    return true;

}

bool  Game::is_there_2048()
{
    for(int i=0; i<board.height(); ++i)
    {
        for(int j=0; j<board.width(); ++j)
        {
            if( board(i,j) == 2048)
                return true;
        }
    }

    return false;
}

bool Game::is_game_over()
{
    return (!is_there_any_field_letf() || is_there_2048());
}

Game::~Game()
{
    
}
void Game::add_2()
{
	int count = 0;
	for (int i = 0; i < board.height(); ++i)
	{
		for (int j = 0; j < board.width(); ++j)
		{
			if (board(i, j) == 0)
				count++;
		}
	}

	unsigned seed = static_cast <int> (chrono::system_clock::now().time_since_epoch().count());
	default_random_engine generator(seed);

	uniform_int_distribution <int> distribution(0, count);
	int random_nr = distribution(generator);
	count = 0;
	for (int i = 0; i < board.height(); ++i)
	{
		for (int j = 0; j < board.width(); ++j)
		{
			if (board(i, j) == 0)
			{
				if (count == random_nr)
				{
					board(i, j) = 2;
					return;

				}
				count++;
			}
			
		}
	}

}

void Game::move_right()
{
	int c;
	for (int i = 0; i<board.height(); ++i)
	{
		for (int j = 3; j >= 0; j--)
		{
			if ( j>0 && (board(i, j) != 0) && board(i, j) == board(i, j - 1))
			{
				board(i, j) = board(i, j) + board(i, j - 1);
				board(i, j - 1) = 0;
			}
			if ((board(i, j) != 0 )&& (j !=3) && board(i, j + 1) == 0)
			{

				for ( c=j; c<3; ++c)
				{
					if (board(i, c+1) != 0)
					{
						if (  board(i, j) == board(i, c+1))
						{
							board(i, c+1) = board(i, c + 1) + board(i, j);
							board(i, j) = 0;
							break;
						}
						c-2;
						break;
					}
				}
				
				board(i, c) = board(i, j);
				board(i, j) = 0;

			}
		}
	}
	add_2();

}
void Game::move_left()
{
	int c;
	for (int i = 0; i<board.height(); ++i)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (j<3 && (board(i, j) != 0) && board(i, j) == board(i, j + 1))
			{
				board(i, j) = board(i, j) + board(i, j + 1);

				board(i, j + 1) = 0;
			}
			if ((board(i, j) != 0) && (j != 0) && board(i, j - 1) == 0)
			{

				for (c = j; c>0; --c)
				{
					if (board(i, c - 1) != 0)
					{
						if (board(i, j) == board(i, c - 1))
						{
							board(i, c - 1) = board(i, c - 1) + board(i, j);
							board(i, j) = 0;
							break;
						}
						c +2;
						break;
					}
				}

				board(i, c) = board(i, j);
				board(i, j) = 0;

			}
		}
	}
	add_2();

}
void Game::move_up()
{
	int c;
	for (int j = 0; j<board.width(); ++j)
	{
		for (int i = 0; i <= 3; i++)
		{
			if (i<3 && (board(i, j) != 0) && board(i, j) == board(i+1, j))
			{
				board(i, j) = board(i, j) + board(i+1, j );

				board(i+1, j) = 0;
			}
			if ((board(i, j) != 0) && (i != 0) && board(i-1, j) == 0)
			{

				for (c = i; c>0; --c)
				{
					if (board(c-1, j) != 0)
					{
						if (board(i, j) == board(c - 1, j))
						{
							board(c-1, j) = board(c - 1, j) + board(i, j);
							board(i, j) = 0;
							break;
						}
						c + 2;
						break;
					}
				}

				board(c, j) = board(i, j);
				board(i, j) = 0;

			}
		}
	}
	add_2();
}
void Game::move_down()
{
	int c;
	for (int j = 0; j<board.width(); ++j)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (i>0 && (board(i, j) != 0) && board(i, j) == board(i - 1, j))
			{
				board(i, j) = board(i, j) + board(i - 1, j);

				board(i - 1, j) = 0;
			}
			if ((board(i, j) != 0) && (i != 3) && board(i + 1, j) == 0)
			{
				for (c = i; c<3; ++c)
				{
					if (board(c + 1, j) != 0)
					{
						if (board(i, j) == board(c + 1, j))
						{
							board(c + 1, j) = board(c + 1, j) + board(i, j);
							board(i, j) = 0;
							break;
						}
						c - 2;
						break;
					}
				}

				board(c, j) = board(i, j);
				board(i, j) = 0;

			}
		}
	}
	add_2();
}