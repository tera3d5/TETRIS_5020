#include "block.h"
#include "error.h"


enum
{
    water,
    orange,
    green,
    red,
    blue,
    brown,
    purple,
    black
};
int piece_color = water;


RECT Block::send(int r)
{
    switch( r )
    {
    case 0:
        RECT rect_piece_water;
        rect_piece_water.top = 957;
        rect_piece_water.left = 688;
        rect_piece_water.right = 713;
        rect_piece_water.bottom = 982;


        return rect_piece_water;
        break;

    case 1:
        RECT rect_piece_orange;
        rect_piece_orange.top = 957;
        rect_piece_orange.left = 713;
        rect_piece_orange.right = 738;
        rect_piece_orange.bottom = 982;

        return rect_piece_orange;
        break;

    case 2:
        RECT rect_piece_green;
        rect_piece_green.top = 957;
        rect_piece_green.left = 738;
        rect_piece_green.right = 763;
        rect_piece_green.bottom = 982;

        return rect_piece_green;
        break;

    case 3:
        RECT rect_piece_red;
        rect_piece_red.top = 957;
        rect_piece_red.left = 763;
        rect_piece_red.right = 788;
        rect_piece_red.bottom = 982;

        return rect_piece_red;
        break;

    case 4:
        RECT rect_piece_blue;
        rect_piece_blue.top = 957;
        rect_piece_blue.left = 788;
        rect_piece_blue.right = 813;
        rect_piece_blue.bottom = 982;

        return rect_piece_blue;
        break;

    case 5:
        RECT rect_piece_brown;
        rect_piece_brown.top = 957;
        rect_piece_brown.left = 813;
        rect_piece_brown.right = 838;
        rect_piece_brown.bottom = 982;

        return rect_piece_brown;
        break;

    case 6:
        RECT rect_piece_purple;
        rect_piece_purple.top = 957;
        rect_piece_purple.left = 838;
        rect_piece_purple.right = 863;
        rect_piece_purple.bottom = 982;

        return rect_piece_purple;
        break;

    }
}

void Block::box_return( int i,int j,int k )
{

    box[ i ][ j ] -= 1;

    switch( k )
    {
    case 0:
        box[ i - 1 ][ j ] += 1;

    case 1:
        box[ i + 1 ][ j ] += 1;

    case 2:
        box[ i ][ j + 1 ] += 1;
    }
}