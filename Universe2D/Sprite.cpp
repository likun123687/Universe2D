#include "Precompiled.h"
#include "Sprite.h"

#include "Application.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture.h"

Sprite::Sprite(std::wstring fileName)
	: m_ColorA(0), m_ColorR(0), m_ColorG(0), m_ColorB(0),
	m_Renderer(nullptr), m_Texture(nullptr), IsLoaded(false)
{
	m_Renderer = Application::GetInstance()->GetRenderer();
	m_Texture = ResourceManager::GetInstance()->LoadTextureFromFile(fileName);

	// �ؽ��İ� ���������� �ҷ��������� �˻�
	IsLoaded = m_Texture ? true : false;

	// �ؽ��İ� ���������������Ƿ� �׳� ����
	// ���� ó���� ���� ���� �޼����� ��� �̹����� �ٲٴ� �� ��ó���� �� �� ���� ��.
	if (!IsLoaded)
		return;

	SetSize({
		static_cast<float>(m_Texture->GetWidth()),
		static_cast<float>(m_Texture->GetHeight())
	});

	D3DXCreateSprite(m_Renderer->GetDevice(), &m_D3DSprite);
}
Sprite* Sprite::Create(std::wstring fileName)
{
	auto instance = new Sprite(fileName);
	return instance;
}
Sprite::~Sprite()
{
	SAFE_RELEASE(m_D3DSprite);

	m_Texture = nullptr;
	m_Renderer = nullptr;
}

void Sprite::Resize(float width, float height)
{
	SetScale({
		width / m_Size.x,
		height / m_Size.y
	});

	SetCenter({
		m_Size.x * m_Scale.x / 2,
		m_Size.y * m_Scale.y / 2
	});
}

void Sprite::Render()
{
	if (!m_Visible || !IsLoaded) return;

	Object::Render();

	// �ϳ��� �̹������� �׷��� �κ��� ����(Rect)�� ���� �� �� ����
	RECT srcRect;
	SetRect(&srcRect,
		0,
		0,
		static_cast<int>(m_Size.x),
		static_cast<int>(m_Size.y));

	m_D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_D3DSprite->SetTransform(&m_Matrix);
	m_D3DSprite->Draw(
		m_Texture->GetD3DTexture(),
		&srcRect, NULL, &D3DXVECTOR3(-m_Size.x / 2, -m_Size.y / 2, .0f), //-m_ImageWidth / 2, -m_ImageHeight / 2
		D3DCOLOR_ARGB(255 - m_ColorA, 255 - m_ColorR, 255 - m_ColorG, 255 - m_ColorB));
	m_D3DSprite->End();
}
