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
    block_move_x_init = 636.0F;
    block_move_y_init = 174.0F;

}
Tetris::~Tetris()
{
    tetris_box;
}

namespace
{
    const float piece_           = 25.0F;   // 1ピース分の大きさ
    const float map_width        = 230.0F;  // ゲーム表示部分の縦幅
    const float map_height       = 483.0F;  //                 横幅
    const float map_limit_left   = 535.0F;  //                 左の端座標
    const float map_limit_right  = 735.0F;  //                 右の端座標
    const float map_limit_top    = 174.0F;  //                 上限
    const float map_limit_bottom = 695.0F;  //                 下限
}





bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "テトリスの素材がないんじゃ～" );
        return false;
    }
    
    block_move_x = block_move_x_init;
    block_move_y = block_move_y_init;


    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 20; j++ )
            tetris_box[ i ][ j ] = 0;
    
    
    t3_f = t3_m = 0L;
    t1_f = t2_f = t1_m = t2_m = timeGetTime();

    tetris_key = move_key = 0;
    move_time = 0;

    Tetris::parts_init();


    return true;
}

void Tetris::parts_init()
{
    srand( (unsigned int)time( NULL ) );
    block_color = rand() % 7;

    switch( block_color )
    {
    case water:
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                box[ i ][ j ] = waterbox[ i ][ j ];
        break;

    case orange:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = orangebox[ i ][ j ];
        break;

    case green:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = greenbox[ i ][ j ];
        break;

    case red:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = redbox[ i ][ j ];
        break;

    case blue:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = bluebox[ i ][ j ];
        break;

    case brown:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = brownbox[ i ][ j ];
        break;

    case purple:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box[ i ][ j ] = purplebox[ i ][ j ];
        break;


    }
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
            block_move_x -= piece_;
       
        move_key = 1;
        move_time++;
        if( move_time > 10 && (block_move_x > map_limit_left) )
        {
            block_move_x -= piece_;
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
            block_move_x += piece_;

        move_key = 1;
        move_time++;
        if( move_time > 10 && (block_move_x < map_limit_right))
        {
            block_move_x += piece_;
            move_time = 0;
        }

    }

    
    if( key.Down || pad.dpad.down ) // 2
    {
        if( !((block_move_y += (piece_ * 2)) < map_limit_bottom) )
            block_move_y += piece_;
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

    
    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_view );

    if( block_color == water )
    {
        for( int i = 0; i < 4; i++ )
        {
            for( int j = 0; j < 4; j++ )
            {
                if( box[ i ][ j ] == 1 )
                {
                    Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &water_piece_range_ );
                    block_move_x += piece_;
                }
                else
                    block_move_x += piece_;

            }
            block_move_x -= (piece_ * 4);
            block_move_y += piece_;
        }
        block_move_y -= (piece_ * 4);
    }
    else
    {
        for( int i = 0; i < 3; i++ )
        {
            for( int j = 0; j < 3; j++ )
            {
                if( box[ i ][ j ] == 1 )
                {
                    switch( block_color )
                    {
                    case orange:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &orange_piece_range_ );
                        break;

                    case green:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &green_piece_range_ );
                        break;

                    case red:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &red_piece_range_ );
                        break;

                    case blue:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &blue_piece_range_ );
                        break;

                    case brown:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &brown_piece_range_ );
                        break;

                    case purple:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &purple_piece_range_ );
                        break;

                    case black:
                        Sprite::draw( texture_, Vector2( block_move_x, block_move_y ), &black_piece_range_ );
                        break;

                    }


                    block_move_x += piece_;

                }
                else
                {
                    block_move_x += piece_;
                }

            }
            block_move_x -= (piece_ * 3);
            block_move_y += piece_;
        }

        block_move_y -= (piece_ * 3);
    }



   
    if( dt_f > 1000 )
    {
        t2_f = t1_f;         
        t3_f = dt_f % 1000;

        
        block_move_y += piece_;
    }

}
