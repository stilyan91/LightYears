#pragma once

#include <map>
#include <memory>
#include <stdio.h>
#include <unordered_map>
#include <vector>

namespace ly
{
    template<typename T>
    using unique = std::unique_ptr<T>;
    
    template<typename T>
    using shared = std::shared_ptr<T>;

    template<typename T>
    using weak = std::weak_ptr<T>;

    template<typename T>
    using List = std::vector<T>;

    template<typename keyType, typename valueType, typename Pr = std::less<keyType>>
    using Map = std::map<keyType, valueType, Pr>;

    template<typename keyType, typename valueType, typename haster = std::hash<keyType>>
    using Dictionary = std::unordered_map<keyType, valueType, haster>;

    // a MACRO
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}