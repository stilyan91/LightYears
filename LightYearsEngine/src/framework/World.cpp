#include <SFML/Graphics.hpp>

#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
    World::World(Application *owningApp)
        : mOwmingApp(owningApp),
          mBeginPlay{false},
          mActors{},
          mpendingActors{}
    {
    }

    void World::BeginPlayInternal()
    {
        if (!mBeginPlay)
        {
            mBeginPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime)
    {
        for (shared<Actor> actor : mpendingActors)
        {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }

        mpendingActors.clear();

        for (auto iter = mActors.begin(); iter != mActors.end();)
        {
            iter->get()->TickInternal(deltaTime);
            ++iter;
        }

        Tick(deltaTime);
    }

    World::~World()
    {
    }

    void World::BeginPlay()
    {
    }

    void World::Tick(float deltaTime)
    {
    }

    void World::Render(sf::RenderWindow &window)
    {
        for (auto &actor : mActors)
        {
            actor->Render(window);
        }
    }

    sf::Vector2u World::GetWindowSize() const
    {
        return mOwmingApp->GetWindwowSize();
    }

    void World::CleanCycle()
    {
        for (auto iter = mActors.begin(); iter != mActors.end();)
        {
            if (iter->get()->isPendingDestroy())
            {
                iter = mActors.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
    }
}