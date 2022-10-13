/*
Name: Balaaj Arbab
Student ID: 251055771
Date: 18th September 2022

Provides several helpful utility and miscellaneous functions.
*/

#include "Utility.h"

/*
GetCurrentTime
Returns a string of the current timestamp of the world, at the time of invocation.

@return string : The current time
*/
std::string GetCurrentTime()
{
    auto time = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(time);

    std::string timestamp = std::ctime(&t);

    return timestamp.substr(0, timestamp.length() - 1);
}

/*
RandomInteger
Produces a random integer between min(inclusive) and max(exclusive)

@param min Lower bound, inclusive
@param max Upper bound, exclusive
@return int : Random int between min(inclusive) and max(exclusive).
*/
int RandomInteger(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist{ min, max - 1 };

    int n = dist(mt);
    // std::cout << n << "\n";

    return n;
}

/*
RandomDouble
Produces a random double between min(inclusive) and max(exclusive)

@param min Lower bound, inclusive
@param max Upper bound, exclusive
@return int : Random double between min(inclusive) and max(exclusive).
*/
double RandomDouble(double min, double max)
{
    static std::random_device rd;
    static std::mt19937 mt{ rd() };
    std::uniform_real_distribution<> dist(min, max);

    return dist(mt);
}
