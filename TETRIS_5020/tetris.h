#pragma once


#include "texture.h"


class Tetris
{
    ID3D11ShaderResourceView* texture_;
    
    int box_[ 4 ][ 4 ];              // 描画用
    int block_color_;                //ブロックの色
    float block_move_x,  block_move_y; // ブロック座標
    float block_movelimit_y;            // 当たり判定用
    float block_pos_x, block_pos_y;     // 保存しているブロックの描画
    //float move_x, move_y;             // ブロック表示用
    //int move_i, move_j; // 配列
    DWORD t1_f, t2_f, t3_f, dt_f;   // freefall
    DWORD t1_m, t2_m, t3_m, dt_m;   // manual
    char block_speed_;
    char move_key_;
    float piecedraw_begin_x = 510.0F; // 確定しているブロックの描画開始位置
    float piecedraw_begin_y = 673.0F;
    

    // 背景
    RECT rect_view = { 0,0,1280,720 };
    
    // ミノ1ピースの座標  { top, left, right, bottom }
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
    int tetris_box[ 20 ][ 10 ];      // 保存用
    int move_s_box[ 20 ][ 10 ];      // 1ピース用保存
    int tetris_key;
   

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



    void partsinit();
    void partsinits();
    void blockerasers(int x);

    //Tetris();
    ~Tetris();
    bool init();
    void update();
    void singledraw();
    void draw();
    void destroy() { texture_  -> Release();}
};