cmake_minimum_required(VERSION 3.28.3)

project(LightYears
    VERSION 1.0.0
    LANGUAGES C CXX
    )

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)



#create a variable
set(LIGHT_YEARS_ENGINE_TARGET_NAME LightYearsEngine)
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(LightYearsEngine)
add_subdirectory(LightYearsGame)



