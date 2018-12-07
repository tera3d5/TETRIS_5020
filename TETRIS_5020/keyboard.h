#pragma once

#include <Windows.h>
#include <Keyboard.h>

using namespace DirectX;


// Class
class Key
{
private:
    static Keyboard* keyboard_;
    static Keyboard::State state_;
    

public:
    static bool init();
    static const Keyboard::State& getState();

};