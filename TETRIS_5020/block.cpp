#include "block.h"


enum way
{
    right,
    left
};

enum tag
{
    purple_tag = 2,
    brown_tag,
    water_tag,
    orenge_tag = 3,
    blue_tag   = 3,
    green_tag  = 3,
    red_tag    = 3
};

enum color
{
    water,
    orenge,
    green,
    red,
    blue,
    brown,
    purple,
    black,
    brank
};



void Block::brockchanger( int way, int box[ 3 ][ 3 ] )
{

    if( way == right )
    {
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                enable_box_[ i ][ j ] = box[ 2-j ][ i ];
 
    }


    if( way == left )
    {
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                enable_box_[ i ][ j ] = box[ j ][ 2-i ];

    }


}

void Block::brockchanger( int way, int box[ 4 ][ 4 ] )
{

    if( way == right )
    {
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                enable_box_[ i ][ j ] = box[ 3 - j ][ i ];

    }


    if( way == left )
    {
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                enable_box_[ i ][ j ] = box[ j ][ 3 - i ];

    }


}


RECT Block::rectsend( int color )
{
    switch( color )
    {
    case water:
        return &water_piece_range;
    }
}