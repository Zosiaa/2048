#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "Board.h"


class Game
{

public:

    Game();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void display_board();
    bool is_game_over();
    ~Game();


private:

    Board board;
    bool is_there_any_field_letf();
    bool is_there_2048();
    void fill_board();

};



