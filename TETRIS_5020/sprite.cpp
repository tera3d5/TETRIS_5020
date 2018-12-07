#include "sprite.h"
#include "direct3d.h"
#include "common.h"

SpriteBatch* Sprite::sprite_;

// 初期化
bool Sprite::init()
{
    // SpriteBatchクラスのメモリを確保
    sprite_ = new SpriteBatch( Direct3D::getContext() );

    // メモリ確保チェック
    if( !sprite_ )
    {
        // エラー
        return false;
    }

    return true;
}

// 描画開始
void Sprite::begin()
{
    sprite_->Begin( SpriteSortMode_Deferred, Common::getState()->NonPremultiplied() );
}

// 描画終了
void Sprite::end()
{
    sprite_->End();
}

// 描画
void Sprite::draw(
    ID3D11ShaderResourceView* Texture,  // テクスチャ
    const Vector2& Position,            // 座標
    const RECT* Rect,                   // 描画範囲
    const float Rotation,               // 回転
    const Vector2& Scale,               // 拡縮
    const Vector2& Origin,              // アンカーポインタ
    const SpriteEffects Effect,         // エフェクト
    const float Depth )                 // 深度
{
    sprite_->Draw(
        Texture,        // テクスチャ
        Position,      // 描画
        Rect,           // 描画範囲
        Colors::White,  // カラー
        Rotation,       // 回転値
        Origin,        // アンカーポイント（原点）
        Scale,         // 拡縮
        Effect,         // エフェクト
        Depth );        // 深度値
}

// 破棄
void Sprite::destroy()
{
    // メモリ解放
    delete sprite_;
}
