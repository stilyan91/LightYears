#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // release build
    return "assets/";
#else // debug build
    return "/home/stilyan/Projects/LightYears/LightYearsGame/assets/";
#endif
}
