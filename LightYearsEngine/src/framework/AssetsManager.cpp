#include "framework/AssetsManager.h"
#include "framework/Core.h"

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

    void AssetsManager::CleanCycle()
    {
        for (auto iter = mLoadedTextureMap.begin(); iter != mLoadedTextureMap.end();)
        {
            if(iter->second.unique())
            {
                LOG("cleaning texture: %s", iter->first.c_str());
                iter = mLoadedTextureMap.erase(iter);
            } 
            else 
            {
                ++iter;
            }
        }
    }
}