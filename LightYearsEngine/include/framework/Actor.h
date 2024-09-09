#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"
#include "framework/World.h"


namespace ly
{
    class World;
    class Actor : public Object
    {
    public:
        Actor(World *owningWorld, const std::string& texturePath = "");
        void BeginPlayInternal();
        void SetTexture(const std::string& texturePath);
        void Render(sf::RenderWindow& window);
        void TickInternal(float deltaTime);
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);

        void SetActorLocation(const sf::Vector2f& newLoc);
        void SetActorRotation(float newRot);
        void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
        void AddActorRatationOffset(float offsetAmt);
        
        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;
        sf::Vector2f GetActorForwardDirection() const;
        sf::Vector2f GetActorRightDirection() const;
        sf::Vector2u GetWindowSize() const;

        sf::FloatRect GetActorGloablBounds() const;
        
        World* GetWorld() const {return mOwningWorld;}

        bool IsActorOutOfWindow() const;


        
        ~Actor();
    private:
        World *mOwningWorld;
        bool mHasBeganPlay; 
        void CenterPivot();

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;

    };
}