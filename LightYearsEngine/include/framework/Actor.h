#pragma once
#include "framework/Object.h"


namespace ly
{
    class World;
    class Actor : public Object
    {
    public:
        Actor(World *owningWorld);
        void BeginPlayInternal();
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);

        ~Actor();
    private:
        World *mOwningWorld;
        bool mHasBeganPlay; 

    };
}