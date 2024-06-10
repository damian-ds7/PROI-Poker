#pragma once
#include <vector>
#include <string>
#include <random>
#include <algorithm>

struct Names{
    static std::vector<std::string> names;
    static std::vector<std::string> get_names(int n);
};