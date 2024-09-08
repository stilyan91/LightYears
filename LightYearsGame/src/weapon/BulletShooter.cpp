#include "weapon/BulletShooter.h"
#include "framework/Core.h"
#include "framework/Actor.h"
#include "weapon/Bullet.h"
#include "framework/World.h"

namespace ly
{
    BulletShooter::BulletShooter(Actor *owner, float cooldownTime)
        : Shooter(owner),
          mCooldownClock{},
          mCooldownTime{cooldownTime}
    {
    }

    bool BulletShooter::IsOnCooldown() const
    {
        if (mCooldownClock.getElapsedTime().asSeconds() > mCooldownTime)
        {
            return false;
        }
        return true;
    }

    void BulletShooter::ShootImpl()
    {
        sf::Vector2f ownerForwardDir = GetOwner()->GetActorForwardDirection();
		sf::Vector2f ownerRightDir = GetOwner()->GetActorRightDirection();

        mCooldownClock.restart();
        weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue01.png", 300.f, 10.f);
        newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation());
        newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation());
    }

}