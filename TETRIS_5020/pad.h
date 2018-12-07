#pragma once

#include <GamePad.h>

using namespace DirectX;

class Pad
{
private:
    static GamePad pad_;           // �Q�[���p�b�h�N���X
    static GamePad::State state_;  // ���͊i�[�\����1
    static GamePad::State state2_; // ���͊i�[�\����2

public:
    static void update();// �X�V����

    // ���͍\���̂�Ԃ�
    static const GamePad::State& getState() { return state_; }
    static const GamePad::State& getState2() { return state2_; }

    // �U���̐ݒ�(0.0F�`1.0F�̊ԂŐݒ�)
    static void setVibration( const float Left, const float Right )
    {
        pad_.SetVibration( 0, Left, Right );
    }
};