#pragma once


// ���O���
using namespace DirectX;

class Texture
{
public:

    static ID3D11ShaderResourceView*load( const wchar_t* FileName );
};