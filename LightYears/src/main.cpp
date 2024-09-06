#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main()
{
    // allocate memory on the heep.
    std::unique_ptr < ly::Application > app = std::make_unique<ly::Application>();
    app->Run();

    return 0;
}