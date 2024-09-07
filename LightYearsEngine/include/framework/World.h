#pragma once
#include "framework/Core.h"

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

        virtual ~World();

        template <typename ActorType>
        weak<ActorType> SpawnActor();

    private:
        void BeginPlay();
        void Tick(float deltaTime);

        Application *mOwmingApp;
        bool mBeginPlay;

        List<shared<Actor>> mActors;
        List<shared<Actor>> mpendingActors;
    };

    template <typename ActorType>
    weak<ActorType> World::SpawnActor()
    {
        shared<ActorType> newActor{new ActorType(this)};
        mpendingActors.push_back(newActor);
        return newActor;
    }
}