#include "pad.h"

// ���̂̐錾
GamePad Pad::pad_;
GamePad::State Pad::state_;
GamePad::State Pad::state2_;

// �X�V����
void Pad::update()
{
    // ���͂��擾
    // �����ŉ��Ԗڂ̃R���g���[������͂���邩���߂�
    state_ = pad_.GetState( 0 );
    state2_ = pad_.GetState( 1 );
}