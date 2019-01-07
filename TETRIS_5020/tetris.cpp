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
    const float piece_width = 25.0F;
    const float piece_height = 25.0F;
    const float map_width = 230.0F;
    const float map_height = 483.0F;
    const float map_limit_left = 535.0F;
    const float map_limit_right = 735.0F;
    const float map_limit_top = 174.0F;
    const float map_limit_bottom = 695.0F;
}





bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "ÉeÉgÉäÉXÇÃëfçﬁÇ™Ç»Ç¢ÇÒÇ∂Ç·Å`" );
        return false;
    }
    
    block_move_x_init = block_move_x = 636.0F, block_move_y_init = block_move_y = 174.0F;


    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 20; j++ )
            tetris_box[ i ][ j ] = 0;
    srand( (unsigned int) time (NULL) );
    block_c = rand() % 7;

    t3_f = t3_m = 0L;
    t1_f = t2_f = t1_m = t2_m = timeGetTime();

    tetris_key = move_key = 0;
    move_time = 0;

    return true;
}

void Tetris::update()
{
    const Keyboard::State key = Key::getState();
    const GamePad::State pad = Pad::getState();

    t1_m = timeGetTime();
    dt_m = (t1_m - t2_m) + t3_m;


    /*if( dt_m > 250 )
    {

        t2_m = t1_m;
        t3_m = dt_m % 250;
    }*/


    if( (key.Left || pad.dpad.left) && (block_move_x > map_limit_left ) ) // case 0
    {
        
        if( move_key == 0 )
            block_move_x -= piece_width;
       
        move_key = 1;
        move_time++;
        if( move_time > 10 && (block_move_x > map_limit_left) )
        {
            block_move_x -= piece_width;
            move_time = 0;
        }

        
    }
    /*if( !(key.Left || pad.dpad.left) && move_key == 1 )
    {
        move_time = 0;
        move_key = 0;
    }*/



    if( (key.Right || pad.dpad.right) && (block_move_x < map_limit_right) ) // case 0
    {

        if( move_key == 0 )
            block_move_x += piece_width;

        move_key = 1;
        move_time++;
        if( move_time > 10 && (block_move_x < map_limit_right))
        {
            block_move_x += piece_width;
            move_time = 0;
        }

    }

    
    if( key.Down || pad.dpad.down ) // 2
    {
        if( !((block_move_y += (piece_height * 2)) < map_limit_bottom) )
            block_move_y += piece_height;
    }

    if( key.Up || pad.dpad.up ) // 3
    {
        tetris_key = 1;
    }
        
    if( !(key.Right || pad.dpad.right || key.Left || pad.dpad.left || key.Up || pad.dpad.up || key.Down || pad.dpad.down) && move_key == 1 )
    {
        move_time = 0;
        move_key = 0;
    }

    


    /*if( key.Escape || pad.buttons.start )
    {
        tetris_key = 1;
        //PostQuitMessage( 0 );
    }*/
    
    
}

void Tetris::draw()
{
    t1_f = timeGetTime();
    dt_f = (t1_f - t2_f) + t3_f;

    RECT rect_view; // îwåi
    rect_view.top = 0;
    rect_view.left = 0;
    rect_view.right = 1280;
    rect_view.bottom = 720;
    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_view );


    //Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &block.send( block_c ) );
    if( dt_f > 1000 )
    {
        t2_f = t1_f;         
        t3_f = dt_f % 1000;

        
        block_move_y += piece_height;
    }
}

void Tetris::destroy()
{
    texture_->Release();
}