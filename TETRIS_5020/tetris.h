#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include "texture.h"


class Tetris
{
private:
    ID3D11ShaderResourceView* texture_;


public:
    bool init();
    bool update();
    void draw();
    void destroy();
};