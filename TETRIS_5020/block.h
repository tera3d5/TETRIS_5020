#pragma once

#include<cstdio>
#include<d3d11.h>


class Block
{
	RECT water_range_  = { 957,688,713,982 };  //top, left, right, bottom
	RECT orange_range_ = { 957,713,738,982 };
	RECT green_range_  = { 957,738,763,982 };
	RECT red_range_    = { 957,763,788,982 };
	RECT blue_range_   = { 957,788,813,982 };
	RECT brown_range_  = { 957,813,838,982 };
	RECT purple_range_ = { 957,838,863,982 };
	RECT black_range_  = { 957,863,888,982 };

	int changebox[4][4];

public:
	
	void brockchanger(int way, int box[4][4]);
};