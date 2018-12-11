#include <ctime>
#include "tetris.h"
#include "sprite.h"
#include "block.h"
#include "keyboard.h"
#include "pad.h"
#include "error.h"


Texture texture;
Block block;

Tetris::Tetris()
{
    
}

namespace
{
    const int piece_width = 23;
    const int piece_height = 23;
    const int map_width = 230;
    const int map_height = 483;
}

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



bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "ƒeƒgƒŠƒX‚Ì‘fŞ‚ª‚È‚¢‚ñ‚¶‚á`" );
        return false;
    }
    //block.init();

    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 20; j++ )
            tetris_box[ i ][ j ] = 0;
    srand( (unsigned int) time (NULL) );
    block_r = rand() % 7;

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
    RECT rect_view; // ”wŒi
    rect_view.top = 0;
    rect_view.left = 0;
    rect_view.right = 1280;
    rect_view.bottom = 720;
    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_view );


    Sprite::draw( texture_, Vector2( 636.0F, 174.0F ), &block.send( block_r ) );
   

}

void Tetris::destroy()
{
    texture_->Release();
}