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

		// CacheMap�� ����Ѵ�
		m_TextureCacheMap[fileName] = texture;
    }

    return m_TextureCacheMap[fileName];
}

Sound* ResourceManager::LoadSoundFromFile(const std::wstring& fileName)
{
	return nullptr;
}
