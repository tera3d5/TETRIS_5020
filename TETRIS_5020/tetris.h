#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include "texture.h"


class Tetris
{
private:
    ID3D11ShaderResourceView* texture_;
    int tetris_box[ 9 ][ 20 ];


public:
    Tetris();
    bool init();
    bool update();
    void draw();
    void destroy();
};