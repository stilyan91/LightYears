#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

#include "player/PlayerSpaceship.h"
#include "framework/AssetsManager.h"
#include "config.h"

ly::Application *GetApplication()
{
    return new ly::GameApplication();
}

namespace ly
{
    GameApplication::GameApplication()
        : Application(600, 900, "Light Years", sf::Style::Titlebar | sf::Style::Close),
            counter(0.0f)
    {
        AssetsManager::Get().SetAssetsRootDir(GetResourceDir());
        weak<World> newWorld = LoadWorld<World>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
        testPlayerSpaceship.lock()->SetActorRotation(0.f);

        weak<Spaceship> testSpaceship = newWorld.lock()->SpawnActor<Spaceship>();
        testSpaceship.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
        testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));

    }

    void GameApplication::Tick(float deltaTime)
    {
        counter += deltaTime;
        if(counter > 10.f)
        {
            if(!testPlayerSpaceship.expired())
            {
                testPlayerSpaceship.lock()->Destroy();
            }
        }
    }
}