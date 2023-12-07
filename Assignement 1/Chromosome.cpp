#include "Chromosome.h"
#include "FitnessFunction.h"
#include <string>
#include <iostream>

using namespace std;

Chromosome::Chromosome(int numGenes, RandomGenerator *rand)
{
    this->genes = new bool[numGenes];
    this->numGenes = numGenes;

    if (numGenes < 0)
    {
        this->genes = new bool[0];
    }
    else if (rand = NULL)
    {
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = false;
        }
    } 
    else 
    {
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = rand;
        }
    }
}

Chromosome::Chromosome(Chromosome *chromosome)
{
    if (chromosome == NULL)
    {
        numGenes = 0;
        genes[0];
        this->numGenes = 0;
        this->genes = genes;
    }
    else
    {
        bool *deepCopy = new bool[this->numGenes];
        for (int i = 0; i < this->numGenes; i++)
        {
            deepCopy[i] = chromosome;
            this->genes[i] = deepCopy[i];
        }
    }
}

Chromosome::Chromosome(bool *genes, int numGenes)
{
    this->genes = genes;
    this->numGenes = numGenes;

    if (numGenes < 0)
    {
        this->numGenes = 0;
        genes[0];
        this->genes = genes;
    }
    else if (genes == NULL)
    {
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = false;
        }
    }
    else
    {

        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = genes[i];
        }
    }
}

Chromosome::~Chromosome()
{
    for (int i = 0; i < this->numGenes; i++)
    {
        genes[i] = NULL;
    }
    delete[] genes;
}

double Chromosome::fitness(FitnessFunction *fitnessFunction, Chromosome *chromosome, int numGenes)
{
    double ret, calculatedFitness;

    calculatedFitness = fitnessFunction->calculateFitness(chromosome, numGenes);

    if (calculatedFitness == NULL)
    {
        ret = 0;
    }
    else
    {
        ret = calculatedFitness;
    }

    if (chromosome == NULL)
    {
        ret = 0;
    }
    else
    {
        ret = calculatedFitness;
    }

    if (numGenes <= 0)
    {
        ret = 0;
    }
    else
    {
        ret = calculatedFitness;
    }

    return ret;
}

int Chromosome::getNumGenes()
{
    return this->numGenes;
}

Chromosome *Chromosome::crossOver(Chromosome *c2)
{

    double crossOverPoint = floor(c2->getNumGenes() / 2);
    bool *nGenes = new bool(this->numGenes);
    for (int i = 0; i < crossOverPoint; i++)
    {
        nGenes[i] = this->genes[i];
    }

    for (int i = crossOverPoint; i < this->numGenes; i++)
    {
        nGenes[i] = c2->genes[i];
    }

    return new Chromosome(nGenes, this->numGenes);
}

Chromosome *Chromosome::mutate()
{

    bool *nGenes = new bool(this->numGenes);
    bool *inverseGenes = genes;
    for (int i = 0; i < this->numGenes; i++)
    {
        if (inverseGenes[i] == true)
        {
            nGenes[i] = false;
        }
        else
        {
            nGenes[i] = true;
        }
    }

    for (int i = 0; i < this->numGenes; i++)
    {
        nGenes[i] = inverseGenes[i];
    }

    return new Chromosome(nGenes, this->numGenes);
}

string Chromosome::toString()
{
    string ret;

    if (numGenes = 0)
    {
        ret = "";
    }

    for (int i = 0; i < numGenes; i++)
    {
        if (genes[i] == true)
        {
            ret += "1";
        }
        else if (genes[i] == false)
        {
            ret += "0";
        }
    }

    return ret;
}

bool *Chromosome::getGenes()
{
    return genes;
}