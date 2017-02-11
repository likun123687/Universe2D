#include "Precompiled.h"
#include "Texture.h"

#include "Application.h"
#include "Renderer.h"

Texture::Texture(std::wstring fileName)
{
    HRESULT hr;
    hr = D3DXCreateTextureFromFileEx(
        Application::GetInstance()->GetRenderer()->GetDevice(),
        fileName.c_str(),
        D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
        1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
        D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
        &m_Texture);

    if FAILED(hr)
    {
        // ���� ó��
        printf("[Texture] �ؽ��� ���� ���� (%s)\n", fileName);
    }
}
Texture::~Texture()
{
    SAFE_RELEASE(m_Texture);
}