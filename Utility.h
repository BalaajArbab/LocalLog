/*
Provides several helpful utility and miscellaneous functions.
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <chrono>
#include <ctime>
#include <random>

std::string GetCurrentTime();

int RandomInteger(int min, int max);
double RandomDouble(double min, double max);

#endif
