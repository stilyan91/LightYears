#pragma once
#include "framework/Core.h"
#include "framework/Application.h"
#include <utility>

namespace ly
{
    class Actor;
    class Application;
    class World
    {
    public:
        World(Application *owningApp);

        void BeginPlayInternal();
        void TickInternal(float deltaTime);
        void Render(sf::RenderWindow& window);

        virtual ~World();

        template <typename ActorType, typename ...Args>
        weak<ActorType> SpawnActor(Args... args);

        sf::Vector2u GetWindowSize() const;
    private:
        void BeginPlay();
        void Tick(float deltaTime);

        Application *mOwmingApp;
        bool mBeginPlay;

        List<shared<Actor>> mActors;
        List<shared<Actor>> mpendingActors;
    };

    template <typename ActorType,typename ...Args>
    weak<ActorType> World::SpawnActor(Args... args)
    {
        shared<ActorType> newActor = std::make_shared<ActorType>(this, std::forward<Args>(args)...);
        mpendingActors.push_back(newActor);
        return newActor;
    }
}