#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include "texture.h"


class Tetris
{
    ID3D11ShaderResourceView* texture_;
    int tetris_box[ 9 ][ 20 ];
    int block_c; //ブロックの色
    float block_move_x, block_move_x_init, block_move_y, block_move_y_init; // ブロック座標
    int move_i, move_j; // 配列
    DWORD t1_f, t2_f, t3_f, dt_f; // freefall
    DWORD t1_m, t2_m, t3_m, dt_m;  // manual
    char move_key;
    char move_time;
    

public:
    int tetris_key;

    Tetris();
    bool init();
    void update();
    void draw();
    void destroy();
};