#include "FitnessFunction.h"
#include <string>

using namespace std;

// Might be working
double FitnessFunction::calculateFitness(Chromosome *chromosome, int numGenes)
{
    double m, n, ret = 0;

    for (int i = 0; i < numGenes; i++)
    {
        if (*chromosome->getGenes() = true)
        {
            m++;
        }
        else if (*chromosome->getGenes() = false)
        {
            n++;
        }
    }

    ret = m / n;

    return ret;
}