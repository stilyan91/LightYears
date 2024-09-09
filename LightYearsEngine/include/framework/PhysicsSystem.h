#pragma once
#include <box2d/b2_world.h>

#include "framework/Core.h"
#include "framework/Actor.h"


namespace ly
{   
    class PhysicsSystem
    {
        public:
            static PhysicsSystem& Get();
            void Step(float deltaTime);
            b2Body* AddListener(Actor* listener);
            void RemoveListener(b2Body* bodyToRemove);
            float GetPhysicsScale() const {return mPhisicsScale;}
        protected:
            PhysicsSystem();
        private:
            static unique <PhysicsSystem> phisicsSystem;
            b2World mPhysicsWorld;
            float mPhisicsScale;
            int mVelocityIterations;
            int mPositionIterations;

    };

}