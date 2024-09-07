#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace ly 
{
    class AssetsManager
    {
        protected:
            AssetsManager();

        public:
            static AssetsManager& Get();
            shared<sf::Texture> LoadTexture(const std::string& texturePath);
        private:
            static unique<AssetsManager> assetsManager;
            Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
    };
}