#include "Precompiled.h"
#include "ResourceManager.h"

#include "Texture.h"

ResourceManager::ResourceManager()
{
}
ResourceManager::~ResourceManager()
{
}

Texture* ResourceManager::LoadTextureFromFile(std::wstring fileName)
{
    if (!m_TextureMap[fileName])
    {
        auto texture = Texture::Create(fileName);
     
        // �ؽ��� ������ �����ߴٸ� nullptr ��ȯ
        if (!texture)
            return nullptr;

        m_TextureMap[fileName] = texture;
    }

    return m_TextureMap[fileName];
}

Sound * ResourceManager::LoadSoundFromFile(std::wstring fileName)
{
	return nullptr;
}
