#include "framework/Core.h"
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
            float frameDeltaTime = mTickClock.restart().asSeconds();
            accumulatedTime += mTickClock.restart().asSeconds();
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
                Render();
            }
            LOG("ticking at framerate: %f\n", 1.f / frameDeltaTime);

        }
    }

    void Application::RenderInternal()
    {
        mWindow.clear();
        Render();
        mWindow.display();
    }

    void Application::Render()
    {
        sf::RectangleShape rect(sf::Vector2f(100, 100));
        rect.setFillColor(sf::Color::Green);
        rect.setOrigin(50, 50);
        rect.setPosition(mWindow.getSize().x / 2.0f, mWindow.getSize().y / 2.0f);
        mWindow.draw(rect);
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
       
    }
    
    void Application::Tick(float deltaTime)
    {
       
    }
}
