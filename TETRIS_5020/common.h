#pragma once


// ���O���
using namespace DirectX;

// Class
class Common
{
private:
    static CommonStates* state_;// CommonStates�N���X�|�C���^

public:
    static bool init();                                // ������
    static void destroy() { delete state_; }           // �j��
    static CommonStates* getState() { return state_; } // CommonStates�|�C���^��Ԃ�
};