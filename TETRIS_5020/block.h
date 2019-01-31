#pragma once


using namespace DirectX;

class Block
{
    int turn_box_[ 4 ][ 4 ];

public:
    
    //Block();

    void block_changer( int way, int box[ 3 ][ 3 ] );
    void block_changer( int way, int box[ 4 ][ 4 ] );


    // vectorが認識されない。余裕ができたら有効化したい
    //virtual void block_rect( int box[ 3 ][ 3 ], ID3D11ShaderResourceView* texture,Vector2& position, RECT* rect );
    //void block_rect( int box[ 4 ][ 4 ], ID3D11ShaderResourceView* texture,Vector2& position, RECT* rect );


    
    


};

