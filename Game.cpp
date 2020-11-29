#pragma once



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
void Game::move_right()
{
	int count;
	for (int i = 0; i<board.height(); ++i)
	{
		for (int j = board.width()-1; j>=0; j--)
		{
			if (board(i, j) == board(i, j - 1) && j>0)
			{
				board(i, j) = board(i, j) + board(i, j-1);
				board(i, j - 1) = 0;
			}
			if ((board(i, j) != 0 && j != board.width() - 1) && board(i, j + 1) != 0)
			{
				count = j;
				while (board(i, count) == 0) count++;
				board(i, count) = board(i, j);

			}
		}
	}

}
