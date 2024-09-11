#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetsManager.h"
#include "framework/MathUtility.h"
#include "framework/PhysicsSystem.h"

#include <box2d/b2_body.h>

namespace ly
{
    Actor::Actor(World *owningWorld, const std::string &texturePath)
        : mOwningWorld(owningWorld),
          mHasBeganPlay(false),
          mSprite{},
          mTexture{},
          mPhysicsBody(nullptr),
          mPhysicsEnabled(false)
    {
        SetTexture(texturePath);
    }

    Actor::~Actor()
    {
        LOG("Actor Destroyed");
    }

    void Actor::BeginPlayInternal()
    {
        if (!mHasBeganPlay)
        {
            BeginPlay();
            mHasBeganPlay = true;
        }
    }

    void Actor::TickInternal(float deltaTime)
    {
        if (!isPendingDestroy())
        {
            Tick(deltaTime);
        }
    }

    void Actor::BeginPlay()
    {
    }

    void Actor::Tick(float deltaTime)
    {
    }

    void Actor::SetTexture(const std::string &texturePath)
    {
        mTexture = AssetsManager::Get().LoadTexture(texturePath);
        if (!mTexture)
            return;

        mSprite.setTexture(*mTexture);

        int textureWidth = mTexture->getSize().x;
        int textureHeight = mTexture->getSize().y;
        mSprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight}});
        CenterPivot();
    }

    void Actor::Render(sf::RenderWindow &window)
    {
        if (isPendingDestroy())
        {
            return;
        }
        window.draw(mSprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f &newLoc)
    {
        mSprite.setPosition(newLoc);
        UpdatePhysicsTransform();
    }

    void Actor::SetActorRotation(float newRot)
    {
        mSprite.setRotation(newRot);
        UpdatePhysicsTransform();
    }

    sf::Vector2f Actor::GetActorLocation() const
    {
        return mSprite.getPosition();
    }

    float Actor::GetActorRotation() const
    {
        return mSprite.getRotation();
    }

    void Actor::AddActorLocationOffset(const sf::Vector2f &offsetAmt)
    {
        SetActorLocation(GetActorLocation() + offsetAmt);
    }

    void Actor::AddActorRatationOffset(float offsetAmt)
    {
        SetActorRotation(GetActorRotation() + offsetAmt);
    }

    sf::Vector2f Actor::GetActorForwardDirection() const
    {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDirection() const
    {
        return RotationToVector(GetActorRotation() + 90.0f);
    }

    void Actor::CenterPivot()
    {
        sf::FloatRect bounds = mSprite.getGlobalBounds();
        mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    }

    sf::Vector2u Actor::GetWindowSize() const
    {
        return mOwningWorld->GetWindowSize();
    }

    bool Actor::IsActorOutOfWindow() const
    {
        float windowWidth = GetWorld()->GetWindowSize().x;
        float windowHeight = GetWorld()->GetWindowSize().y;

        float width = GetActorGloablBounds().width;
        float height = GetActorGloablBounds().height;

        sf::Vector2f actorPos = GetActorLocation();

        if (actorPos.x < -width)
        {
            return true;
        }

        if (actorPos.x > width + windowWidth)
        {
            return true;
        }

        if (actorPos.y < -height)
        {
            return true;
        }

        if (actorPos.y > height + windowHeight)
        {
            return true;
        }

        return false;
    }

    sf::FloatRect Actor::GetActorGloablBounds() const
    {
        return mSprite.getGlobalBounds();
    }

    void Actor::SetEnablePhysics(bool enable)
    {
        mPhysicsEnabled = enable;
        if (mPhysicsEnabled)
        {
            InitializePhysics();
        }
        else
        {
            UnInitializePhysics();
        }
    }

    void Actor::InitializePhysics()
    {
        if (!mPhysicsBody)
        {
            mPhysicsBody = PhysicsSystem::Get().AddListener(this);
        }
    }

    void Actor::UnInitializePhysics()
    {
        if (mPhysicsBody)
        {
            PhysicsSystem::Get().RemoveListener(GetPhysicsBody());
        }
    }

    void Actor::UpdatePhysicsTransform()
    {
        if (mPhysicsBody)
        {
            float physicsScale = PhysicsSystem::Get().GetPhysicsScale();
            b2Vec2 pos(GetActorLocation().x * physicsScale, GetActorLocation().y * physicsScale);
            float rotation = DegreesToRadians(GetActorRotation());

            mPhysicsBody->SetTransform(pos, rotation);
        }
    }

    void Actor::OnActorBeginOverlap(Actor *otherActor)
    {
        LOG("OVERLAP");
    }

    void Actor::OnActorEndOverlap(Actor* otherActor)
    {
        LOG("OVERLAP FINISHED");
    }
}