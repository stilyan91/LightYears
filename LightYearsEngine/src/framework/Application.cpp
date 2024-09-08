#include "framework/Core.h"
#include "framework/Application.h"
#include "framework/World.h"
#include "framework/AssetsManager.h"

namespace ly
{

    Application::Application(unsigned int wWidth, unsigned int wHeight, const std::string &title, sf::Uint32 style)
        : mWindow(sf::VideoMode(wWidth, wHeight), title, style),
          mTargetFrameRate{60.0f},
          mTickClock{},
          currentWorld{nullptr},
          mCleanCycleClock{},
          mCleanCycleInterval{2.f}
    {

    }

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
            accumulatedTime += frameDeltaTime;
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
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
        if(currentWorld)
        {
            currentWorld->Render(mWindow);
        }

        if(mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval)
        {
            mCleanCycleClock.restart();
            AssetsManager::Get().CleanCycle();
        }
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);

        if (currentWorld)
        {
            currentWorld->BeginPlayInternal();
            currentWorld->TickInternal(deltaTime);
        }
    }

    void Application::Tick(float deltaTime)
    {
    }
}
