#include "weapon/Bullet.h"
#include "framework/MathUtility.h"

namespace ly
{
    Bullet::Bullet(World *world, Actor *owner, const std::string &texturePath, float speed = 300.f, float damage = 10.f)
        : Actor(world, texturePath),
          mOwner{owner},
          mSpeed{speed},
          mDamage{damage}
    {
    }

    void Bullet::SetSpeed(float newSpeed)
    {
        mSpeed = newSpeed;
    }

    void Bullet::SetDamage(float newDamage)
    {
        mDamage = newDamage;
    }

    void Bullet::Tick(float deltaTime)
    {
        Actor::Tick(deltaTime);
        Move(deltaTime);
        if(IsActorOutOfWindow())
        {
            Destroy();
        }
    }

    void Bullet::Move(float deltaTime)
    {
        AddActorLocationOffset(GetActorForwardDirection() * mSpeed * deltaTime);
    }

}