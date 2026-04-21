#include <iostream>
#include <algorithm>
#include "Strings.h"

std::string toLower(const std::string& data)
{
    std::string result = data;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return result;
}
