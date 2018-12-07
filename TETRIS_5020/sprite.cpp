#include "sprite.h"
#include "direct3d.h"
#include "common.h"

SpriteBatch* Sprite::sprite_;

// ������
bool Sprite::init()
{
    // SpriteBatch�N���X�̃��������m��
    sprite_ = new SpriteBatch( Direct3D::getContext() );

    // �������m�ۃ`�F�b�N
    if( !sprite_ )
    {
        // �G���[
        return false;
    }

    return true;
}

// �`��J�n
void Sprite::begin()
{
    sprite_->Begin( SpriteSortMode_Deferred, Common::getState()->NonPremultiplied() );
}

// �`��I��
void Sprite::end()
{
    sprite_->End();
}

// �`��
void Sprite::draw(
    ID3D11ShaderResourceView* Texture,  // �e�N�X�`��
    const Vector2& Position,            // ���W
    const RECT* Rect,                   // �`��͈�
    const float Rotation,               // ��]
    const Vector2& Scale,               // �g�k
    const Vector2& Origin,              // �A���J�[�|�C���^
    const SpriteEffects Effect,         // �G�t�F�N�g
    const float Depth )                 // �[�x
{
    sprite_->Draw(
        Texture,        // �e�N�X�`��
        Position,      // �`��
        Rect,           // �`��͈�
        Colors::White,  // �J���[
        Rotation,       // ��]�l
        Origin,        // �A���J�[�|�C���g�i���_�j
        Scale,         // �g�k
        Effect,         // �G�t�F�N�g
        Depth );        // �[�x�l
}

// �j��
void Sprite::destroy()
{
    // ���������
    delete sprite_;
}
