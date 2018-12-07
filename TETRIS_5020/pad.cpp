#include "pad.h"

// 実体の宣言
GamePad Pad::pad_;
GamePad::State Pad::state_;
GamePad::State Pad::state2_;

// 更新処理
void Pad::update()
{
    // 入力を取得
    // 引数で何番目のコントローラを入力を取るか決める
    state_ = pad_.GetState( 0 );
    state2_ = pad_.GetState( 1 );
}