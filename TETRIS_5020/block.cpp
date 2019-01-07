#include "block.h"


enum
{
    right,
    left
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