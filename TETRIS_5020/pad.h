#pragma once


using namespace DirectX;

class Pad
{
private:
    static GamePad pad_;           // ゲームパッドクラス
    static GamePad::State state_;  // 入力格納構造体1
    static GamePad::State state2_; // 入力格納構造体2

public:
    static void update();// 更新処理

    // 入力構造体を返す
    static const GamePad::State& getState() { return state_; }
    static const GamePad::State& getState2() { return state2_; }

    // 振動の設定(0.0F〜1.0Fの間で設定)
    static void setVibration( const float Left, const float Right )
    {
        pad_.SetVibration( 0, Left, Right );
    }
};