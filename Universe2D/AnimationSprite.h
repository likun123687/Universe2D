#pragma once
#include "Object.h"

class Renderer;
class Texture;

class AnimationSprite : public Object
{
public:
	bool IsLoaded;
	bool IsUpdate;

protected:
	float m_ImageWidth;
	float m_ImageHeight;

	byte m_ColorA, m_ColorR, m_ColorG, m_ColorB;

	LPD3DXSPRITE m_D3DSprite;

private:
	int currentFrame = 0;
	int frameDelay = 0;
	std::unordered_map<int, Texture*> m_Texture;
	Renderer* m_Renderer;
	void SpriteAdd(int index, std::wstring fileName);

public:
	AnimationSprite(int frameSize, int frameDelay);
	~AnimationSprite();
	// ������ ��� �߰�
	void AddFrame(int index, std::wstring fileName);
	// �ִϸ��̼� ���
	void AnimationUpdate();
	void SetUpdate(bool IsUpdate);

public:
	inline byte GetOpacity() const { return m_ColorA; }
	void SetOpacity(byte opacity) { m_ColorA = opacity; }

	inline float GetWidth() const { return m_ImageWidth; }

	inline float GetHeight() const { return m_ImageHeight; }

	inline D3DXVECTOR2 GetCenter() const { return m_Center; }

	// Ư�� ũ�⿡ �°� Scale�� ������
	void Resize(float width, float height);

public:
	void Render() override;
};