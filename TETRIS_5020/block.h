#pragma once

#include<cstdio>
#include<d3d11.h>


class Block
{
	RECT water_piece_range_  = { 957,688,713,982 };  //top, left, right, bottom
	RECT orange_piece_range_ = { 957,713,738,982 };
	RECT green_piece_range_  = { 957,738,763,982 };
	RECT red_piece_range_    = { 957,763,788,982 };
	RECT blue_piece_range_   = { 957,788,813,982 };
	RECT brown_piece_range_  = { 957,813,838,982 };
	RECT purple_piece_range_ = { 957,838,863,982 };
	RECT black_piece_range_  = { 957,863,888,982 };
    RECT brank_piece_range_  = { 1480,970,995,1505 };
    //RECT piece = { 512,174,199,537 };

	

public:
	
	void brockchanger(int way, int box[3][3]);

    int enable_box_[ 4 ][ 4 ];
    int waterbox[ 4 ][ 4 ]=
    {
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0}
    };

};