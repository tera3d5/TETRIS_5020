#pragma once

#include "texture.h"


class Block
{
private:
    //ID3D11ShaderResourceView* texture_piece_;


public:
    RECT send(int r); // �`��͈͂�Ԃ�(���j
    void block_return( int r ); // �u���b�N���̂��ׂĂ�����
};