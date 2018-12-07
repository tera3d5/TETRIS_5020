#include "keyboard.h"

// À‘Ì‚ÌéŒ¾
Keyboard* Key::keyboard_;
Keyboard::State Key::state_;

bool Key::init()
{
    keyboard_ = new Keyboard;
    if( keyboard_ )
        return true;
    else
        return false;
}

const Keyboard::State& Key::getState()
{
    state_ = keyboard_->GetState();
    return state_;
}