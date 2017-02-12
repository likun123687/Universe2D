#pragma once
#include "Object.h"

class Renderer;
class Texture;

class Sprite : public Object
{
public:
    bool IsLoaded;

protected:
    float m_ImageWidth;
    float m_ImageHeight;
    
    byte m_ColorA, m_ColorR, m_ColorG, m_ColorB;

    LPD3DXSPRITE m_D3DSprite;

private:
    Texture* m_Texture;
    Renderer* m_Renderer;

    Sprite(std::wstring fileName);
public:
    static Sprite* Create(std::wstring fileName);
    ~Sprite();

public:
    inline byte GetOpacity() const { return m_ColorA; }
    void SetOpacity(byte opacity) { m_ColorA = opacity; }

    inline int GetWidth() const { return m_ImageWidth; }
    inline int GetHeight() const { return m_ImageHeight; }

    // Ư�� ũ�⿡ �°� Scale�� ������
    void Resize(float width, float height);

public:
    void Render() override;
};

