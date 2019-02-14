#include "tetris.h"
#include "sprite.h"
#include "block.h"
#include "keyboard.h"
#include "pad.h"
#include "error.h"


Texture texture;
Block block;



namespace
{
    const float piece_           = 25.0F;   // 1ピース分の大きさ
    const float map_width        = 230.0F;  // ゲーム表示部分の縦幅
    const float map_height       = 483.0F;  //                 横幅
    const float map_limit_left   = 535.0F;  //                 左の端座標
    const float map_limit_right  = 735.0F;  //                 右の端座標
    const float map_limit_top    = 174.0F;  //                 上限
    const float map_limit_bottom = 695.0F;  //                 下限
    const float block_move_limit_y = 670.0F;
    const float block_move_x_init = 611.0F;
    const float block_move_y_init = 174.0F;
    const float block_pos_y_init = 673.0F;


}





bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "テトリスの素材がないんじゃ～" );
        return false;
    }
    


    for( int i = 0; i < 21; i++ )
        for( int j = 0; j < 10; j++ )
        {
            //tetris_box[ i ][ j ] = 0;
            move_s_box[ i ][ j ] = 0;
        }
    
    
    t2_f = timeGetTime();
    t1_f = timeGetTime();
    t3_f = t3_m = dt_f = dt_m = 0L;
    tetris_key = move_key_ = 0;

    block_pos_x = 511.0F;
    block_pos_y = block_pos_y_init;

    Tetris::partsinits();


    return true;
}


void Tetris::partsinits()
{
    srand( (unsigned int)time( NULL ) );
    block_color_ = (rand() % 7) + 1;

    block_move_x = block_move_x_init;
    block_move_y = block_move_y_init;


    x = 0, y = 5;
    move_s_box[ x ][ y ] = block_color_;

}


#if 0
void Tetris::partsinit()
{
    srand( (unsigned int)time( NULL ) );
    block_color_ = (rand() % 7) + 1;
    for( int i = 0; i < 4; i++ )
        for( int j = 0; j < 4; j++ )
            box_[ i ][ j ] = 0;

    block_move_x = block_move_x_init;
    block_move_y = block_move_y_init;

    switch( block_color_ )
    {
    case water:
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                box_[ i ][ j ] = water_box[ i ][ j ];
        break;

    case orange:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box_[ i ][ j ] = orange_box[ i ][ j ];
        break;

    case green:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box_[ i ][ j ] = green_box[ i ][ j ];
        break;

    case red:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box_[ i ][ j ] = red_box[ i ][ j ];
        break;

    case blue:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box_[ i ][ j ] = blue_box[ i ][ j ];
        break;

    case brown:
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                box_[ i ][ j ] = brown_box[ i ][ j ];
        break;

    case purple:
        for( int i = 0; i < 2; i++ )
            for( int j = 0; j < 2; j++ )
                box_[ i ][ j ] = purple_box[ i ][ j ];
        break;


    }
}
#endif


void Tetris::update()
{
    const Keyboard::State key = Key::getState();
    const GamePad::State pad = Pad::getState();


    t1_f = timeGetTime();
    dt_f = (t1_f - t2_f) + t3_f;


    if( (key.Left || pad.dpad.left) && move_s_box[ x ][ y - 1 ] == 0 ) // case 0
    {

        if( move_key_ == 0 )
        {
            move_s_box[ x ][ y ] = 0;
            move_s_box[ x ][ y - 1 ] = block_color_;
			y--;
        }
		
            
        move_key_ = 1;


    }
    if( (key.Left || pad.dpad.left) && move_s_box[ x ][ y - 1 ] == 0 && move_key_ == 1 )
    {
        t1_m = timeGetTime();
        dt_m = (t1_m - t2_m) + t3_m;


        if( dt_m > 250 )
        {
            t2_m = t1_m;
            t3_m = dt_m % 250;

            if( move_s_box[ x ][ y - 1 ] == 0 )
            {
                move_s_box[ x ][ y ] = 0;
                move_s_box[ x ][ y - 1 ] = block_color_;
				y--;
            }
        }
    }
    if( !(key.Left || pad.dpad.left) )
    {
        move_key_ = 0;
    }



    if( (key.Right || pad.dpad.right) &&move_s_box[ x ][ y + 1 ] == 0 ) // 1
    {

        if( move_key_ == 0 )
        {
            move_s_box[ x ][ y ] = 0;
            move_s_box[ x ][ y + 1 ] = block_color_;
			y++;
        }
        move_key_ = 1;


    }
    if( (key.Right || pad.dpad.right) && move_s_box[ x ][ y + 1 ] == 0 && move_key_ == 1 )
    {
        t1_m = timeGetTime();
        dt_m = (t1_m - t2_m) + t3_m;


        if( dt_m > 250 )
        {
            t2_m = t1_m;
            t3_m = dt_m % 250;

            if( move_s_box[ x ][ y + 1 ] == 0 )
            {
                move_s_box[ x ][ y ] = 0;
                move_s_box[ x ][ y + 1 ] = block_color_;
				y++;
            }
        }
    }
    if( !(key.Right || pad.dpad.right) )
    {
        move_key_ = 0;
    }

    
    /*if( key.Down || pad.dpad.down ) // 2
    {
        if( !((block_move_y += (piece_ * 2)) < map_limit_bottom) )
            block_move_y += piece_;
    }

    if( key.Up || pad.dpad.up ) // 3
    {
        tetris_key = 1;
    }*/
        
    if( !(key.Right || pad.dpad.right || key.Left || pad.dpad.left || key.Up || pad.dpad.up || key.Down || pad.dpad.down) && move_key_ == 1 )
    {

        move_key_ = 0;
    }




    if( dt_f > 1000 )		// 自然落下
    {
		t2_f = t1_f;
		t3_f = dt_f % 1000;

        if( move_s_box[ x + 1 ][ y ] == 0 )
        {
            move_s_box[ x ][ y ] = 0;
            move_s_box[ x + 1 ][ y ] = block_color_;
            x++;
        }	
        if( move_s_box[ x + 1 ][ y ] >= 1 || x >= 20)
        {
            blockerasers();
            partsinits();
        }

    }
}


void Tetris::singledraw()
{
	Sprite::draw(texture_, Vector2(0.0F, 0.0F), &rect_view); // 背景

	 
	RECT water_piece_range_;
	water_piece_range_.top = 957.0L;
	water_piece_range_.left = 688.0L;
	water_piece_range_.right = 713.0L;
	water_piece_range_.bottom = 982.0L;

	RECT orange_piece_range_;
	orange_piece_range_.top = 957.0L;
	orange_piece_range_.left = 713.0L;
	orange_piece_range_.right = 738.0L;
	orange_piece_range_.bottom = 982.0L;

	RECT green_piece_range_;
	green_piece_range_.top = 957.0L;
	green_piece_range_.left = 738.0L;
	green_piece_range_.right = 763.0L;
	green_piece_range_.bottom = 982.0L;

	RECT red_piece_range_;
	red_piece_range_.top = 957.0L;
	red_piece_range_.left = 763.0L;
	red_piece_range_.right = 788.0L;
	red_piece_range_.bottom = 982.0L;

	RECT blue_piece_range_;
	blue_piece_range_.top = 957.0L;
	blue_piece_range_.left = 788.0L;
	blue_piece_range_.right = 813.0L;
	blue_piece_range_.bottom = 982.0L;

	RECT brown_piece_range_;
	brown_piece_range_.top = 957.0L;
	brown_piece_range_.left = 813.0L;
	brown_piece_range_.right = 838.0L;
	brown_piece_range_.bottom = 982.0L;

	RECT purple_piece_range_;
	purple_piece_range_.top = 957.0L;
	purple_piece_range_.left = 838.0L;
	purple_piece_range_.right = 863.0L;
	purple_piece_range_.bottom = 982.0L;



    for( int i = 20; i >= 0; i-- )                                // 全てのブロックの描画
    {
        for( int j = 0; j < 10; j++ )
        {
            if( move_s_box[ i ][ j ] >= 1 )
            {
                switch( move_s_box[ i ][ j ] )
                {
                case water:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &water_piece_range_ );
                    break;

                case orange:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &orange_piece_range_ );
                    break;

                case green:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &green_piece_range_ );
                    break;

                case red:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &red_piece_range_ );
                    break;

                case blue:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &blue_piece_range_ );
                    break;

                case brown:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &brown_piece_range_ );
                    break;

                case purple:
                    Sprite::draw( texture_, Vector2( block_pos_x, block_pos_y ), &purple_piece_range_ );
                    break;

                }
                block_pos_x += piece_;
            }
            else if( move_s_box[ i ][ j ] == 0 )
                block_pos_x += piece_;
        }
        block_pos_x -= piece_ * 10;
        block_pos_y -= piece_;
    }
    block_pos_y = block_pos_y_init;




}


#if 0
void Tetris::draw()
{
     
    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), &rect_view ); // 背景

	RECT water_piece_range_;
	water_piece_range_.top = 957.0L;
	water_piece_range_.left = 688.0L;
	water_piece_range_.right = 713.0L;
	water_piece_range_.bottom = 982.0L;

	RECT orange_piece_range_;
	orange_piece_range_.top = 957.0L;
	orange_piece_range_.left = 713.0L;
	orange_piece_range_.right = 738.0L;
	orange_piece_range_.bottom = 982.0L;

	RECT green_piece_range_;
	green_piece_range_.top = 957.0L;
	green_piece_range_.left = 738.0L;
	green_piece_range_.right = 763.0L;
	green_piece_range_.bottom = 982.0L;

	RECT red_piece_range_;
	red_piece_range_.top = 957.0L;
	red_piece_range_.left = 763.0L;
	red_piece_range_.right = 788.0L;
	red_piece_range_.bottom = 982.0L;

	RECT blue_piece_range_;
	blue_piece_range_.top = 957.0L;
	blue_piece_range_.left = 788.0L;
	blue_piece_range_.right = 813.0L;
	blue_piece_range_.bottom = 982.0L;

	RECT brown_piece_range_;
	brown_piece_range_.top = 957.0L;
	brown_piece_range_.left = 813.0L;
	brown_piece_range_.right = 838.0L;
	brown_piece_range_.bottom = 982.0L;

	RECT purple_piece_range_;
	purple_piece_range_.top = 957.0L;
	purple_piece_range_.left = 838.0L;
	purple_piece_range_.right = 863.0L;
	purple_piece_range_.bottom = 982.0L;


    for( int i = 20; i >= 0; i-- )
        for( int j = 0; j < 10; j++ )
        {
            if( move_s_box[i][j]>=1/*tetris_box[ i ][ j ] >= 1*/ )
            {
                switch( move_s_box[i][j]/*tetris_box[ i ][ j ]*/ )
                {
                case water:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &water_piece_range_ );
                    break;

                case orange:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &orange_piece_range_ );
                    break;

                case green:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &green_piece_range_ );
                    break;

                case red:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &red_piece_range_ );
                    break;

                case blue:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &blue_piece_range_ );
                    break;

                case brown:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &brown_piece_range_ );
                    break;

                case purple:
                    Sprite::draw( texture_, Vector2( piecedraw_begin_x, piecedraw_begin_y ), &purple_piece_range_ );
                    break;


                }
                piecedraw_begin_x += piece_;

            }
            else if(move_s_box[i][j]==0 /*tetris_box[ i ][ j ] == 0*/ )
                piecedraw_begin_x += piece_;
            piecedraw_begin_x = 510.0F;
            piecedraw_begin_y -= piece_;
        }
    piecedraw_begin_y = 673.0F; 



}
#endif




void Tetris::blockerasers()// 固定したところから1行分走査して消す
{
    int count = 0;
	for (int i = 0;i < 10;i++)
		if (move_s_box[20][i] >= 1)
			count++;

	if (count == 9)
		for (int i = 20;i >=0;i--)
			for(int j=0;j<10;j++)
			move_s_box[i][j] = move_s_box[i-1][j];


}