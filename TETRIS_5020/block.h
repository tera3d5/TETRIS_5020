#pragma once

#include <cstdio>
#include <d3d11.h>
#include "tetris.h"



class Block
{

    int turn_box_[ 4 ][ 4 ];

    Vector2 draw_position_;



public:
    Block();

    void blockchanger( int way, int box[ 3 ][ 3 ] );
    void blockchanger( int way, int box[ 4 ][ 4 ] );

    void block_rect_( int box[ 3 ][ 3 ], ID3D11ShaderResourceView* texture, Vector2 position, const RECT* rect );
    void block_rect_( int box[ 4 ][ 4 ], ID3D11ShaderResourceView* texture, Vector2 position, const RECT* rect );


    
    int waterbox[ 4 ][ 4 ]=
    {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };
    int orengebox[3][3]=
    {
        {1,1,1},
        {1,0,0},
        {0,0,0}
    };
    int greenbox[3][3]=
    {
        {0,1,1},
        {1,1,0},
        {0,0,0}
    };
    int redbox[3][3]=
    {
        {1,1,0},
        {0,1,1},
        {0,0,0}
    };
    int bluebox[3][3]=
    {
        {1,1,1},
        {0,0,1},
        {0,0,0}
    };
    int brownbox[3][3]=
    {
        {1,1,1},
        {0,1,0},
        {0,0,0}
    };
    int purplebox[2][2]=
    {
        {1,1},
        {1,1}
    };


};

