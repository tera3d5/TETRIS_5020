#define _CRT_SECURE_NO_WARNINGS


#include "direct3d.h"
#include "texture.h"


ID3D11ShaderResourceView*Texture::load( const wchar_t* FileName )
{


    ID3D11ShaderResourceView* texture;

    // テクスチャの読み込み
    if( FAILED( CreateWICTextureFromFileEx(
        Direct3D::getDevice(),      // D3Dデバイスインターファイス
        Direct3D::getContext(),     // デバイスコンテキストインターファイス
        FileName,                   // ファイル名（ワイド文字で指定）
        0,                          // ミニマップレベル
        D3D11_USAGE_DEFAULT,        // 使用方法
        D3D11_BIND_SHADER_RESOURCE, // バインドの種類
        0,                          // CPUアクセス方法
        0,                          // フラグオプション
        WIC_LOADER_DEFAULT,         // SRGBフラグ
        NULL,                       // リソースデータ受け取りポインタ
        &texture ) ) )               // シェーダーリソースビュー受取先ポインタ
    {
        // エラー
        char file_name[ 256 ], str[ 256 ];
        wcstombs( file_name, FileName, 256 );
        sprintf( str, "テクスチャの読み込みに失敗(%s)", file_name );
        

        return NULL;
    }

    return texture;
}