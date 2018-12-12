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
    const int piece_width = 25;
    const int piece_height = 25;
    const int map_width = 230;
    const int map_height = 483;
}





bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "ƒeƒgƒŠƒX‚Ì‘fŞ‚ª‚È‚¢‚ñ‚¶‚á`" );
        return false;
    }
    
    block_move_x_init = block_move_x = 636.0F, block_move_y_init = block_move_y = 174.0F;


    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 20; j++ )
            tetris_box[ i ][ j ] = 0;
    srand( (unsigned int) time (NULL) );
    block_c = rand() % 7;

    t3 = 0L;
    t1 = timeGetTime();
    t2 = timeGetTime();

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
    t1 = timeGetTime();
    dt = (t1 - t2) + t3;

    RECT rect_view; // ”wŒi
    rect_view.top = 0;
    rect_view.left = 0;
    rect_view.right = 1280;
    rect_view.bottom = 720;
    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_view );


    Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &block.send( block_c ) );
    if( dt > 1000 )
    {
        t2 = t1;         
        t3 = dt % 1000;

        
        block_move_y += piece_height;
    }
}

void Tetris::destroy()
{
    texture_->Release();
}