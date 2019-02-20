#pragma once


#include "texture.h"


class Tetris
{
    ID3D11ShaderResourceView* texture_;
    
    int block_color_;                //�u���b�N�̐F
    float block_move_x,  block_move_y; // �u���b�N���W
    float block_pos_x, block_pos_y;     // �ۑ����Ă���u���b�N�̕`��

    DWORD t1_f, t2_f, t3_f, dt_f;   // freefall
    DWORD t1_m, t2_m, t3_m, dt_m;   // manual
	bool move_flag_;
    float piecedraw_begin_x = 510.0F; // �m�肵�Ă���u���b�N�̕`��J�n�ʒu
    float piecedraw_begin_y = 673.0F;
    

    // �w�i
    RECT rect_view = { 0,0,1280,720 };
    


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
    int move_s_box[ 21 ][ 10 ];      // 1�s�[�X�p�ۑ�
    

    int water_box[ 4 ][ 4 ] =
    {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };
    int orange_box[ 3 ][ 3 ] =
    {
        {1,1,1},
        {1,0,0},
        {0,0,0}
    };
    int green_box[ 3 ][ 3 ] =
    {
        {0,1,1},
        {1,1,0},
        {0,0,0}
    };
    int red_box[ 3 ][ 3 ] =
    {
        {1,1,0},
        {0,1,1},
        {0,0,0}
    };
    int blue_box[ 3 ][ 3 ] =
    {
        {1,1,1},
        {0,0,1},
        {0,0,0}
    };
    int brown_box[ 3 ][ 3 ] =
    {
        {1,1,1},
        {0,1,0},
        {0,0,0}
    };
    int purple_box[ 2 ][ 2 ] =
    {
        {1,1},
        {1,1}
    };




    void partsinits();
    void blockerasers(); // ��s�e�g���X��p


    bool init();
    void update();
    void singledraw();
    void destroy() { texture_  -> Release();}
};