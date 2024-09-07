#include <iostream>

#include "framework/Application.h"

namespace ly
{

    Application::Application() : mWindow{sf::VideoMode(800, 600), "Light Years"},
                                 mTargetFrameRate{60.0f}, mTickClock{} {

                                 };

    void Application::Run()
    {
        mTickClock.restart();
        float accumulatedTime = 0.0f;
        float targetDeltaTime = 1.f / mTargetFrameRate;
        while (mWindow.isOpen())
        {
            sf::Event event;
            while (mWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    mWindow.close();
                }
            }
            accumulatedTime += mTickClock.restart().asSeconds();
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                Tick(targetDeltaTime);
                Render();
            }
        }
    }

    void Application::Render()
    {

    }

    void Application::Tick(float deltaTime)
    {
        std::cout << "ticking at framerate: " << 1.f/deltaTime << std::endl;
    }

}
