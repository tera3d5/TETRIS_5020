#pragma once

#include "texture.h"


class Block
{
private:
    int box[ 9 ][ 20 ];


public:
    RECT send(int r); // 描画範囲を返す(仮）
    void box_return( int i, int j,int k ); // 配列書き換え(box_x, box_y, type_no)
};