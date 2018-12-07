#include "tetris.h"
#include "sprite.h"
#include "keyboard.h"
#include "pad.h"
#include "error.h"


Texture texture;


bool Tetris::init()
{
    texture_ = texture.load( L"Tetris11_SingleT.png" );
    if( texture_ == NULL )
    {
        Error::showDialog( "ƒeƒgƒŠƒX‚Ì‰æ–Ê‚ª‚È‚¢‚ñ‚¶‚á`" );
        return false;
    }
    
    return true;
}

bool Tetris::update()
{
    const GamePad::State pad = Pad::getState();

    if( Key::getState().Escape || pad.buttons.start )
    {
        return false;
    }
}

void Tetris::draw()
{
    RECT rect;
    

    Sprite::draw( texture_, Vector2( 0.0F, 0.0F ), NULL );
}

void Tetris::destroy()
{
    texture_->Release();
}