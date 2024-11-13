#pragma once

#ifdef MYTOOL_EXPORTS
#define MYTOOL_API __declspec(dllexport)
#else
#define MYTOOL_API __declspec(dllimport)
#endif

#include <random>
#include <iostream>
#include <string>   
#include <conio.h>
using namespace std;

typedef unsigned int u_int;

namespace Tools
{
    static int RandomInt(const u_int& _max, const u_int& _min)
    {
        random_device _rSeed;
        mt19937 _gen(_rSeed());
        uniform_int_distribution<> distr(_min, _max);

        return distr(_gen);
    }
}