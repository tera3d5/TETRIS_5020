#include "tetris.h"
#include "sprite.h"
#include "keyboard.h"
#include "pad.h"
#include "error.h"


Texture texture;

Tetris::Tetris()
{
    
}

enum piece_color
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


bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "テトリスの画面がないんじゃ〜" );
        return false;
    }


    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 20; j++ )
            tetris_box[ i ][ j ] = 0;

    return true;
}

bool Tetris::update()
{
    const GamePad::State pad = Pad::getState();

    if( Key::getState().Escape || pad.buttons.start )
    {
        return false;
    }
    return true;
}

void Tetris::draw()
{
    RECT rect_view; // 背景
    rect_view.top = 0;
    rect_view.left = 0;
    rect_view.right = 1280;
    rect_view.bottom = 720;

    switch( piece_color )
    {
    default:RECT rect_piece;
        rect_piece.top = 957;
        rect_piece.left = 688 + ((piece_color) * 25);
        rect_piece.right = 713;
        rect_piece.bottom = 982;
        break;
    }
    
    
    RECT rect_piece_water;
    rect_piece_water.top = 957;
    rect_piece_water.left = 688;
    rect_piece_water.right = 713;
    rect_piece_water.bottom = 982;

    RECT rect_piece_orange;
    rect_piece_orange.top = 957;
    rect_piece_orange.left = 713;
    rect_piece_orange.right = 738;
    rect_piece_orange.bottom = 982;

    RECT rect_piece_green;
    rect_piece_green.top = 957;
    rect_piece_green.left = 738;
    rect_piece_green.right = 763;
    rect_piece_green.bottom = 982;

    RECT rect_piece_red;
    rect_piece_red.top = 957;
    rect_piece_red.left = 763;
    rect_piece_red.right = 788;
    rect_piece_red.bottom = 982;

    RECT rect_piece_blue;
    rect_piece_blue.top = 957;
    rect_piece_blue.left = 788;
    rect_piece_blue.right = 813;
    rect_piece_blue.bottom = 982;

    RECT rect_piece_brown;
    rect_piece_brown.top = 957;
    rect_piece_brown.left = 813;
    rect_piece_brown.right = 838;
    rect_piece_brown.bottom = 982;

    RECT rect_piece_purple;
    rect_piece_purple.top = 957;
    rect_piece_purple.left = 838;
    rect_piece_purple.right = 863;
    rect_piece_purple.bottom = 982;

    RECT rect_piece_black;
    rect_piece_black.top = 957;
    rect_piece_black.left = 863;
    rect_piece_black.right = 888;
    rect_piece_black.bottom = 982;



    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_view );
    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_piece_green );

}

void Tetris::destroy()
{
    texture_->Release();
}