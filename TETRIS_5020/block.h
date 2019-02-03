#pragma once




class Block
{
    int turn_box_[ 4 ][ 4 ];

public:
    

    void block_changer( int way, int box[ 3 ][ 3 ] );
    void block_changer( int way, int box[ 4 ][ 4 ] );

};

