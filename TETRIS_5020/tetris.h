#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include "texture.h"


class Tetris
{
    ID3D11ShaderResourceView* texture_;
    
    int box[ 4 ][ 4 ];              // �`��p
    int block_color;                //�u���b�N�̐F
    float block_move_x,  block_move_y; // �u���b�N���W
    float block_movelimit_y;            // �����蔻��p
    float block_pos_x, block_pos_y;     // �ۑ����Ă���u���b�N�̕`��
    //float move_x, move_y;             // �u���b�N�\���p
    //int move_i, move_j; // �z��
    DWORD t1_f, t2_f, t3_f, dt_f;   // freefall
    DWORD t1_m, t2_m, t3_m, dt_m;   // manual
    char block_speed;
    char move_key;
    float piecedraw_begin_x = 510.0F; // �m�肵�Ă���u���b�N�̕`��J�n�ʒu
    float piecedraw_begin_y = 673.0F;
    

    // �w�i
    RECT rect_view = { 0,0,1280,720 };
    
    // �~�m1�s�[�X�̍��W  { top, left, right, bottom }
    RECT water_piece_range_  = { 957,688,713,982 };  
    RECT orange_piece_range_ = { 957,713,738,982 };
    RECT green_piece_range_  = { 957,738,763,982 };
    RECT red_piece_range_    = { 957,763,788,982 };
    RECT blue_piece_range_   = { 957,788,813,982 };
    RECT brown_piece_range_  = { 957,813,838,982 };
    RECT purple_piece_range_ = { 957,838,863,982 };
    RECT black_piece_range_  = { 957,863,888,982 };
    RECT brank_piece_range_  = { 1480,970,995,1505 };


    enum color
    {
        water = 1,
        orange,
        green,
        red,
        blue,
        brown,
        purple,
        black,
        brank
    };

    int x, y;

public:
    int tetris_box[ 20 ][ 10 ];      // �ۑ��p
    int move_s_box[ 20 ][ 10 ];      // 1�s�[�X�p�ۑ�
    int tetris_key;
   

    int waterbox[ 4 ][ 4 ] =
    {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };
    int orangebox[ 3 ][ 3 ] =
    {
        {1,1,1},
        {1,0,0},
        {0,0,0}
    };
    int greenbox[ 3 ][ 3 ] =
    {
        {0,1,1},
        {1,1,0},
        {0,0,0}
    };
    int redbox[ 3 ][ 3 ] =
    {
        {1,1,0},
        {0,1,1},
        {0,0,0}
    };
    int bluebox[ 3 ][ 3 ] =
    {
        {1,1,1},
        {0,0,1},
        {0,0,0}
    };
    int brownbox[ 3 ][ 3 ] =
    {
        {1,1,1},
        {0,1,0},
        {0,0,0}
    };
    int purplebox[ 2 ][ 2 ] =
    {
        {1,1},
        {1,1}
    };



    void parts_init();
    void parts_init_s();
    void block_eraser_s(int x);

    Tetris();
    ~Tetris();
    bool init();
    void update();
    void single_draw();
    void draw();
    void destroy() { texture_  -> Release();}
};