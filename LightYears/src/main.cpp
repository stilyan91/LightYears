#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
   sf::Window window(sf::VideoMode(800, 600), "Simple SFML Window");

    // Main loop that continues until the window is closed
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Key pressed: print the key to the console
            if (event.type == sf::Event::KeyPressed) {
                std::cout << "Key pressed: " << event.key.code << std::endl;
            }
            // Window resized: print the new dimensions
            if (event.type == sf::Event::Resized) {
                std::cout << "Window resized: " << event.size.width << "x" << event.size.height << std::endl;
            }
        }

        // Display the contents of the window
        window.display();
    }
    std::cout << "Hello" << std::endl;
    return 0;
}