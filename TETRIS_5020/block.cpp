#include "texture.h"
#include "block.h"
#include "sprite.h"




enum way
{
    right,
    left
};

enum piecetag
{
    purple_tag = 2,
    brown_tag,
    water_tag,
    orenge_tag = 3,
    blue_tag   = 3,
    green_tag  = 3,
    red_tag    = 3
};




void Block::block_changer( int way, int box[ 3 ][ 3 ] )
{

    if( way == right )
    {
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                turn_box_[ i ][ j ] = box[ 2-j ][ i ];

        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = turn_box_[ i ][ j ];
 
    }


    if( way == left )
    {
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                turn_box_[ i ][ j ] = box[ j ][ 2-i ];

        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = turn_box_[ i ][ j ];
    }


}

void Block::block_changer( int way, int box[ 4 ][ 4 ] )
{

    if( way == right )
    {
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                turn_box_[ i ][ j ] = box[ 3 - j ][ i ];

        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                box[ i ][ j ] = turn_box_[ i ][ j ];
    }


    if( way == left )
    {
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                turn_box_[ i ][ j ] = box[ j ][ 3 - i ];

        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                box[ i ][ j ] = turn_box_[ i ][ j ];
    }


}