#include "framework/Application.h"

namespace ly
{

    Application::Application() : mWindow{sf::VideoMode(800, 600), "Light Years"} {
                                 };

    void Application::Run()
    {
        while(mWindow.isOpen())
        {
            sf::Event event;
            while(mWindow.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    mWindow.close();
                }
            }
            mWindow.clear();
            mWindow.display();
        }
    }
}