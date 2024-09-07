#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetsManager.h"


namespace ly
{
    Actor::Actor(World *owningWorld, const std::string& texturePath)
        : mOwningWorld(owningWorld),
          mHasBeganPlay(false),
          mSprite{},
          mTexture{}
    {
        SetTexture(texturePath);
    }

    Actor::~Actor()
    {
        LOG("Actor Destroyed");
    }

    void Actor::BeginPlayInternal()
    {
        if(!mHasBeganPlay)
        {
            BeginPlay();
            mHasBeganPlay = true;
        }
    }

    void Actor::TickInternal(float deltaTime)
    {
        if(!isPendingDestroy())
        {
            Tick(deltaTime);
        }
    }

    void Actor::BeginPlay()
    {
        LOG("Actor begin play");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("Actor ticking");
    }

    void Actor::SetTexture(const std::string& texturePath)
    {
        mTexture = AssetsManager::Get().LoadTexture(texturePath);
        if(!mTexture) return;

        mSprite.setTexture(*mTexture);

        int textureWidth = mTexture->getSize().x;
        int textureHeight = mTexture->getSize().y;
        mSprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });

    }

    void Actor::Render(sf::RenderWindow& window)
    {
        if(isPendingDestroy())
        {
            return;
        }
        window.draw(mSprite);
    }
}