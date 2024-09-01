cmake_minimum_required(VERSION 3.28.3)

project(LightYears
    VERSION 1.0.0
    LANGUAGES C CXX
    )

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

#create a variable
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)
set(CMAKE_BUILD_TYPE Debug)

set(SFML_LIB_NAME SFML)

include(FetchContent)
FetchContent_Declare(${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.5.1
    GIT_SHALLOW FALSE)


FetchContent_MakeAvailable(${SFML_LIB_NAME})

add_subdirectory(LightYears)


