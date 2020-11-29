#pragma once
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Board
{

	vector <int> data_;
	size_t width_;
	size_t height_;


public:

	Board()
	{
		vector <int> numbers(16, 0);
		data_ = numbers;
		width_ = 4;
		height_ = 4;
	}


	size_t width()
	{
		return width_;
	}

	size_t height()
	{
		return height_;
	}

	int& operator()(size_t h, size_t w)
	{
		assert(w < width_);
		assert(h < height_);
		return data_[width_ * h + w];
	}

	int const& operator()(size_t h, size_t w) const
	{
		return const_cast <Board&> (*this)(h, w);
	}

};
