#include "Precompiled.h"
#include "Sprite.h"
#include "AnimationSprite.h"

#include "Application.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture.h"

AnimationSprite::AnimationSprite(int frameSize, int frameDelay)
	: m_ImageWidth(.0f), m_ImageHeight(.0f),
	m_ColorA(0), m_ColorR(0), m_ColorG(0), m_ColorB(0),
	m_Renderer(nullptr), IsLoaded(false)
{
	m_Texture.reserve(frameSize);
	this->frameDelay = frameDelay;
}

void AnimationSprite::AddFrame(int index, std::wstring fileName)
{
	m_Renderer = Application::GetInstance()->GetRenderer();
	m_Texture[index] = ResourceManager::GetInstance()->LoadTextureFromFile(fileName);

	// �ؽ��İ� ���������� �ҷ��������� �˻�
	IsLoaded = m_Texture[index] ? true : false;

	// �ؽ��İ� ���������������Ƿ� �׳� ����
	// ���� ó���� ���� ���� �޼����� ��� �̹����� �ٲٴ� �� ��ó���� �� �� ���� ��.
	if (!IsLoaded)
		return;

	m_ImageWidth = m_Texture[index]->GetWidth();
	m_ImageHeight = m_Texture[index]->GetHeight();

	m_Center = {
		m_ImageWidth / 2,
		m_ImageHeight / 2
	};

	// �ʱ� ��ġ�� ���� ���
	m_Position = m_Center;

	D3DXCreateSprite(m_Renderer->GetDevice(), &m_D3DSprite);
}

void AnimationSprite::AnimationUpdate()
{
	currentFrame++;

	if (currentFrame > m_Texture.size() - 1)
		currentFrame = 0;
}

void AnimationSprite::SetUpdate(bool IsUpdate)
{
	this->IsUpdate = IsUpdate;
}

AnimationSprite::~AnimationSprite()
{
	SAFE_RELEASE(m_D3DSprite);

	m_Renderer = nullptr;
}

void AnimationSprite::SpriteAdd(int index, std::wstring fileName)
{
	m_Renderer = Application::GetInstance()->GetRenderer();
	m_Texture[index] = ResourceManager::GetInstance()->LoadTextureFromFile(fileName);

	// �ؽ��İ� ���������� �ҷ��������� �˻�
	IsLoaded = m_Texture[index] ? true : false;

	// �ؽ��İ� ���������������Ƿ� �׳� ����
	// ���� ó���� ���� ���� �޼����� ��� �̹����� �ٲٴ� �� ��ó���� �� �� ���� ��.
	if (!IsLoaded)
		return;

	m_ImageWidth = m_Texture[index]->GetWidth();
	m_ImageHeight = m_Texture[index]->GetHeight();

	m_Center = {
		m_ImageWidth / 2,
		m_ImageHeight / 2
	};

	// �ʱ� ��ġ�� ���� ���
	m_Position = m_Center;

	D3DXCreateSprite(m_Renderer->GetDevice(), &m_D3DSprite);
}

void AnimationSprite::Resize(float width, float height)
{
	m_Scale = {
		width / m_ImageWidth,
		height / m_ImageHeight
	};
	// Resize�� ���� �纯��
	m_Center = {
		width / m_ImageWidth,
		height / m_ImageHeight
	};
}

void AnimationSprite::Render()
{
	//�̿�
	if (!m_Visible || !IsLoaded) return;
	Object::Render();

	// �ϳ��� �̹������� �׷��� �κ��� ����(Rect)�� ���� �� �� ����
	// ���Ŀ� �Ķ���ͷ� ������ ����

	RECT srcRect;
	SetRect(&srcRect, 0, 0, m_ImageWidth, m_ImageHeight);

	m_D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_D3DSprite->SetTransform(&m_Matrix);
	m_D3DSprite->Draw(
		m_Texture[currentFrame]->GetD3DTexture(),
		&srcRect, NULL, &D3DXVECTOR3(-m_ImageWidth / 2, -m_ImageHeight / 2, .0f), //-m_ImageWidth / 2, -m_ImageHeight / 2
		D3DCOLOR_ARGB(255 - m_ColorA, 255 - m_ColorR, 255 - m_ColorG, 255 - m_ColorB));
	m_D3DSprite->End();

	if (IsUpdate)
		AnimationUpdate();
}