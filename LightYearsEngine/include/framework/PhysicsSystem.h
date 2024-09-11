#pragma once
#include <box2d/b2_world.h>

#include "framework/Core.h"
#include "framework/Actor.h"


namespace ly
{   
    class PhysicsContactListener : public b2ContactListener
    {
        virtual void BeginContact(b2Contact* contact) override;
        virtual void EndContact(b2Contact* contact) override;
    };

    class PhysicsSystem
    {
        public:
            static PhysicsSystem& Get();
            void Step(float deltaTime);
            b2Body* AddListener(Actor* listener);
            void RemoveListener(b2Body* bodyToRemove);
            
            float GetPhysicsScale() const {return mPhisicsScale;}
            
            static void CleanUp();
            
        protected:
            PhysicsSystem();
        private:
            void ProcessPendingRemoveListeners();
            static unique <PhysicsSystem> phisicsSystem;
            b2World mPhysicsWorld;
            float mPhisicsScale;
            int mVelocityIterations;
            int mPositionIterations;
            PhysicsContactListener mContactListener;
            
            Set<b2Body*> mPendingRemoveListeners;

    };

}