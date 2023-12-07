#include "RandomGenerator.h"
#include <string>
#include <cmath>

using namespace std;

RandomGenerator::RandomGenerator(int seed)
{
    this->seed = seed;
}

bool RandomGenerator::randomBool()
{
    int random = rand();
    bool ret;

    if (random % 2 == 0)
    {
        ret = false;
    }
    else if (random % 2 != 0)
    {
        ret = true;
    }

    return ret;
}