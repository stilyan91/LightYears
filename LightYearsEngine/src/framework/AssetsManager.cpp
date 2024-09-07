#include "framework/AssetsManager.h"

namespace ly
{   
    unique<AssetsManager> AssetsManager::assetsManager = nullptr;

    AssetsManager::AssetsManager()
    {
        
    }

    AssetsManager& AssetsManager::Get()
    {
        if(!assetsManager)
        {
            assetsManager = unique<AssetsManager>{new AssetsManager};
        }
        return *assetsManager; 
    }

    shared<sf::Texture> AssetsManager::LoadTexture(const std::string& texturePath)
    {
        auto found = mLoadedTextureMap.find(texturePath);
        if(found != mLoadedTextureMap.end())
        {
            return found->second;
        }

        shared<sf::Texture> newTexture {new sf::Texture};
        if(newTexture->loadFromFile(texturePath))
        {
            mLoadedTextureMap.insert({texturePath, newTexture});
            return newTexture;
        }

        return shared<sf::Texture>{nullptr};
    }
}