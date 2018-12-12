#pragma once

#include "texture.h"


class Block
{
private:
    //ID3D11ShaderResourceView* texture_piece_;


public:
    RECT send(int r); // 描画範囲を返す(仮）
    void block_return( int r ); // ブロック部のすべてを処理
};