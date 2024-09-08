#pragma once
#include "framework/Core.h"

#include <framework/Application.h>
#include <spaceship/Spaceship.h>

namespace ly 
{
    class Actor;
    class GameApplication : public Application
    {   
        public:
            GameApplication();
            virtual void Tick(float deltaTime) override;
        private:
            float counter;
            weak<Spaceship> testPlayerSpaceship;
    };
}