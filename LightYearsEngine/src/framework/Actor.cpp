#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
    Actor::Actor(World *owningWorld)
        : mOwningWorld(owningWorld),
          mHasBeganPlay(false)
    {

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

    void Actor::BeginPlay()
    {
        LOG("Actor begin play");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("Actor ticking");
    }
}