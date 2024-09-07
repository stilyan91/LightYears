#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application *GetApplication()
{
    return new ly::GameApplication();
}

namespace ly
{
    GameApplication::GameApplication()
        : Application(600, 900, "Light Years", sf::Style::Titlebar | sf::Style::Close)
    {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
        actorToDestroy.lock()->SetTexture("/home/stilyan/Projects/LightYears/LightYearsGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
        counter = 0;
    }

    void GameApplication::Tick(float deltaTime)
    {
        counter += deltaTime;
        if (counter > 2.f)
        {
            if (!actorToDestroy.expired())
            {
                actorToDestroy.lock()->Destroy();
            }
        }
    }
}