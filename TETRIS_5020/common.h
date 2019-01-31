#pragma once


// 名前空間
using namespace DirectX;

// Class
class Common
{
private:
    static CommonStates* state_;// CommonStatesクラスポインタ

public:
    static bool init();                                // 初期化
    static void destroy() { delete state_; }           // 破棄
    static CommonStates* getState() { return state_; } // CommonStatesポインタを返す
};