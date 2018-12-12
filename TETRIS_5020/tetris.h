#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include "texture.h"


class Tetris
{
private:
    ID3D11ShaderResourceView* texture_;
    int tetris_box[ 9 ][ 20 ];
    int block_c; //ブロックの色
    float block_move_x, block_move_x_init, block_move_y, block_move_y_init;
    DWORD t1, t2, t3 , dt;
    

public:
    Tetris();
    bool init();
    bool update();
    void draw();
    void destroy();
};