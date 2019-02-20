#include "tetris.h"
#include "sprite.h"
#include "block.h"
#include "keyboard.h"
#include "pad.h"
#include "error.h"

#define DEBUG


Texture texture;

namespace
{
    const float piece_           = 25.0F;   // 1ピース分の大きさ
    const float map_width        = 230.0F;  // ゲーム表示部分の縦幅
    const float map_height       = 483.0F;  //                 横幅
    const float map_limit_left   = 485.0F;  //                 左の端座標
    const float map_limit_right  = 735.0F;  //                 右の端座標
    const float map_limit_top    = 174.0F;  //                 上限
    const float map_limit_bottom = 695.0F;  //                 下限
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
    


	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 10; j++)
			move_s_box[i][j] = 0;
        
    
    
    t2_f = timeGetTime();
    t1_f = timeGetTime();
    t3_f = t3_m = dt_f = dt_m = 0L;
	move_flag_ = false;
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





void Tetris::update()
{
    const Keyboard::State key = Key::getState();
    const GamePad::State pad = Pad::getState();


    t1_f = timeGetTime();
    dt_f = (t1_f - t2_f) + t3_f;


	if (key.Left || pad.dpad.left)
	{

		if ((block_move_x - piece_) >= map_limit_left && move_s_box[x][y - 1] == 0 && move_flag_ == false)
		{
			move_s_box[x][y] = 0;
			move_s_box[x][y - 1] = block_color_;
			y--;
			block_move_x -= piece_;
			move_flag_ = true;
		}
		if (move_flag_ == true)
		{

			t1_m = timeGetTime();
			dt_m = (t1_m - t2_m) + t3_m;


			if (dt_m > 500)
			{
				if ((block_move_x - piece_) >= map_limit_left && move_s_box[x][y - 1] == 0)
				{
					move_s_box[x][y] = 0;
					move_s_box[x][y - 1] = block_color_;
					y--;
					block_move_x -= piece_;
				}
				t2_m = t1_m;
				t3_m = dt_m % 500;
			}
		}
	}
	if (!(key.Left || pad.dpad.left) && move_flag_ == true)
	{
		move_flag_ = false;
		t2_m = t3_m = 0;
	}
	


	if (key.Right || pad.dpad.right)
	{

		if ((block_move_x + piece_) <= map_limit_right && move_s_box[x][y + 1] == 0 && move_flag_ == false)
		{
			move_s_box[x][y] = 0;
			move_s_box[x][y + 1] = block_color_;
			y++;
			block_move_x += piece_;
			move_flag_ = true;
		}

		if (move_flag_ == true)
		{

			t1_m = timeGetTime();
			dt_m = (t1_m - t2_m) + t3_m;


			if (dt_m > 500)
			{
				if ((block_move_x + piece_) <= map_limit_right && move_s_box[x][y + 1] == 0)
				{
					move_s_box[x][y] = 0;
					move_s_box[x][y + 1] = block_color_;
					y++;
					block_move_x += piece_;
				}
				t2_m = t1_m;
				t3_m = dt_m % 500;
			}
		}
	}
	if (!(key.Right || pad.dpad.right) && move_flag_ == true)
	{
		move_flag_ = false;
		t2_m = t3_m = 0;
	}
	

#ifdef DEBUG
    if( dt_f > 400 )		// 自然落下
    {
        if( (block_move_y + piece_) <= map_limit_bottom && move_s_box[x + 1][y]== 0)
        {
            move_s_box[ x ][ y ] = 0;
            move_s_box[ x + 1 ][ y ] = block_color_;
            x++;
			block_move_y += piece_;
        }	
        if((block_move_y + piece_) >= map_limit_bottom || move_s_box[x + 1][y] >= 1)
        {
            blockerasers();
            partsinits();
        }
		t2_f = t1_f;
		t3_f = dt_f % 400;
    }
#endif
#ifdef RELEASE
	if (dt_f > 1000)		// 自然落下
	{
		if ((block_move_y + piece_) <= map_limit_bottom && move_s_box[x + 1][y] == 0)
		{
			move_s_box[x][y] = 0;
			move_s_box[x + 1][y] = block_color_;
			x++;
			block_move_y += piece_;
		}
		if ((block_move_y + piece_) >= map_limit_bottom || move_s_box[x + 1][y] >= 1)
		{
			blockerasers();
			partsinits();
		}
		t2_f = t1_f;
		t3_f = dt_f % 1000;
	}
#endif
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




void Tetris::blockerasers()// 固定したところから1行分走査して消す
{
	int count1 = 0;
	bool delete_flag_ = false;
	int tetris_down_ = 1;			// テトリミノを下げる行数

	for (int i = 0;i < 10;i++)
	{
		if (move_s_box[20][i] >= 1)
			count1++;
	}

	if (count1 == 10)
	{
		for (int i = 0;i < 10;i++)
			move_s_box[20][i] = 0;

		for (int i = 0;i < 10;i++)
		{
			if (move_s_box[20 - tetris_down_][i] >= 1)
				delete_flag_ = true;

			if (delete_flag_==true)
			{
				tetris_down_++;
				delete_flag_ = false;
				continue;
			}
		}

		
		for (int i = 20;i > (20 - tetris_down_);i--)
			for (int j = 0;j < 10;j++)
				move_s_box[i][j] = move_s_box[i - 1][j];
	}

}
