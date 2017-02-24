#include "Precompiled.h"
#include "ResourceManager.h"

#include "Texture.h"

ResourceManager::ResourceManager()
{
}
ResourceManager::~ResourceManager()
{
}

Texture* ResourceManager::LoadTextureFromFile(const std::wstring& fileName)
{
	// ĳ�øʿ� �ؽ��İ� ������ ���� �����ؼ� ĳ�÷� ����մϴ�
    if (!m_TextureCacheMap.count(fileName))
    {
        auto texture = Texture::Create(fileName);

        // �ؽ��� ������ �����ߴٸ� nullptr ��ȯ
        if (texture == nullptr)
            return nullptr;

		// CacheMap�� ����ϰ� ���� ī���͸� ������ŵ�ϴ�
		m_TextureCacheMap[fileName] = texture;
		texture->Retain();
    }

    return m_TextureCacheMap[fileName];
}

Sound* ResourceManager::LoadSoundFromFile(const std::wstring& fileName)
{
	return nullptr;
}
