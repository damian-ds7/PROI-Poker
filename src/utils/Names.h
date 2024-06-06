#pragma once
#include <vector>
#include <string>
#include <random>
#include <algorithm>


namespace RandomNames {
    extern std::vector<std::string> random_names;

    std::vector<std::string> get_random_names(std::vector<std::string> vector_names = random_names);
}