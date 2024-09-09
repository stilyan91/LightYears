#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>

#include "framework/MathUtility.h"
#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
namespace ly
{
    unique<PhysicsSystem> PhysicsSystem::phisicsSystem = nullptr;

    PhysicsSystem &PhysicsSystem::Get()
    {
        if (!phisicsSystem)
        {
            phisicsSystem = std::move(unique<PhysicsSystem>{new PhysicsSystem});
        }

        return *phisicsSystem;
    }

    PhysicsSystem::PhysicsSystem()
        : mPhysicsWorld{b2Vec2{0.f, 0.f}},
          mPhisicsScale{0.01f},
          mVelocityIterations{8},
          mPositionIterations{3}
    {
    }

    void PhysicsSystem::Step(float deltaTime)
    {
        mPhysicsWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
    }

    b2Body *PhysicsSystem::AddListener(Actor *listener)
    {
        if (listener->isPendingDestroy())
            return nullptr;

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;

        bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener);

        bodyDef.position.Set(listener->GetActorLocation().x * GetPhysicsScale(), listener->GetActorLocation().y * GetPhysicsScale());
        bodyDef.angle = DegreesToRadians(listener->GetActorRotation());

        b2Body *body = mPhysicsWorld.CreateBody(&bodyDef);

        b2PolygonShape shape;
        auto bounds = listener->GetActorGloablBounds();
        shape.SetAsBox(bounds.width / 2.f * GetPhysicsScale(), bounds.height / 2.f * GetPhysicsScale());

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.isSensor = true;

        body->CreateFixture(&fixtureDef);

        return body;
    }
    void PhysicsSystem::RemoveListener(b2Body *bodyToRemove)
    {
        // TODO: Implement removal of physics body
    }
}