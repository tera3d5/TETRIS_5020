#pragma once

#include <GamePad.h>

using namespace DirectX;

class Pad
{
private:
    static GamePad pad_;           // ƒQ[ƒ€ƒpƒbƒhƒNƒ‰ƒX
    static GamePad::State state_;  // “ü—ÍŠi”[\‘¢‘Ì1
    static GamePad::State state2_; // “ü—ÍŠi”[\‘¢‘Ì2

public:
    static void update();// XVˆ—

    // “ü—Í\‘¢‘Ì‚ğ•Ô‚·
    static const GamePad::State& getState() { return state_; }
    static const GamePad::State& getState2() { return state2_; }

    // U“®‚Ìİ’è(0.0F`1.0F‚ÌŠÔ‚Åİ’è)
    static void setVibration( const float Left, const float Right )
    {
        pad_.SetVibration( 0, Left, Right );
    }
};