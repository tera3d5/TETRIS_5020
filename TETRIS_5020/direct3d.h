#pragma once

#include<d3d11.h>

// Class
class Direct3D
{
private:
    static ID3D11Device* d3d_device_;                   // D3D�f�o�C�X�C���^�[�t�F�C�X
    static ID3D11DeviceContext* device_context_;        // �f�o�C�X�R���e�L�X�g�C���^�[�t�F�C�X
    static IDXGISwapChain* swap_chain_;                 // �X���b�v�`�F�[���t�F�C�X
    static D3D_FEATURE_LEVEL feature_level_;            // �@�\���x��
    static ID3D11RenderTargetView* render_target_view_; // �`��^�[�Q�b�g�r���[

public:
    static bool init( const HWND hWnd ); // ������
    static void destroy();               // �j��
    static void clear();                 // ��ʃN���A
    static void present();               // ��ʍX�V

    // �C���^�[�t�F�C�X�̎擾
    static ID3D11Device* getDevice() { return d3d_device_; }
    static ID3D11DeviceContext* getContext() { return device_context_; }
    static IDXGISwapChain* getChain() { return swap_chain_; }
};