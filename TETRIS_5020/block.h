#pragma once

#include "texture.h"


class Block
{
private:
    int box[ 9 ][ 20 ];


public:
    RECT send(int r); // �`��͈͂�Ԃ�(���j
    void box_return( int i, int j,int k ); // �z�񏑂�����(box_x, box_y, type_no)
};