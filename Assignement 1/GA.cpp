#include "GA.h"
#include <string>
#include <iostream>

using namespace std;

GA::GA(int populationSize, RandomGenerator *rand, int numGenes, int selectionSize)
{
    cout << "starting GA" << endl;
    this->populationSize = populationSize;
    this->selectionSize = selectionSize;
    cout << "populating population" << endl;

    for (int i = 0; i < numGenes; i++)
    {
        this->population[i] = new Chromosome(numGenes, rand);
    }
}

GA::GA(GA *geneticAlgorithm)
{
    this->populationSize = geneticAlgorithm->populationSize;
    this->selectionSize = geneticAlgorithm->selectionSize;
    this->population = new Chromosome *[this->populationSize];

    for (int i = 0; i < this->populationSize; i++)
    {
        this->population[i] = new Chromosome(geneticAlgorithm->population[i]);
    }
}

GA::~GA()
{
    for (int i = 0; i < populationSize; i++)
    {
        delete[] population[i];
    }
    delete[] population;
}

Chromosome **GA::run(FitnessFunction *fitnessFunction)
{
    Chromosome **winners = selection(fitnessFunction);
    Chromosome **losers = inverseSelection(fitnessFunction);
    Chromosome **offspring = new Chromosome *[3];
    Chromosome **P = new Chromosome *[populationSize];

    for (int i = 0; i < 2 * selectionSize; i++)
    {
        Chromosome nChromosome = new Chromosome(winners[i]);
        nChromosome = *crossOver(winners[i], winners[i + 1]);
        offspring[i] = new Chromosome(nChromosome);
        offspring[i + 1] = new Chromosome(nChromosome);
    }

    for (int i = 0; i < selectionSize; i++)
    {
        offspring[i + 2 * selectionSize] = mutate(winners[i + 2 * selectionSize]);
    }

    for (int i = 0; i < 3; i++)
    {
        Chromosome *dyingChromosome = losers[i];
        int u = i;
        P[u] = offspring[i];
        u++;
    }

    return P;
}

//! Might be incomplete
double **GA::run(FitnessFunction *fitnessFunction, int numGenerations)
{
    double **results = new double *[numGenerations];
    for (int i = 0; i < 3; i++)
    {
        results[i] = new double[i];
    }
    for (int i = 0; i < numGenerations; i++)
    {
        results[i][0] = calculateAvgAccuracy(fitnessFunction);
        results[i][1] = calculateStd(fitnessFunction);
        results[i][2] = calculateVariance();
    }

    return results;
}

Chromosome **GA::selection(FitnessFunction *fitnessFunction)
{
    for (int i = 0; i < populationSize; i++)
    {
        if (fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) > fitnessFunction->calculateFitness(population[i + 1], population[i + 1]->getNumGenes()))
        {
            Chromosome *temp = population[i];
            population[i] = population[i + 1];
            population[i + 1] = temp;
        }
    }

    return population;
}

Chromosome **GA::inverseSelection(FitnessFunction *fitnessFunction)
{
    for (int i = 0; i < populationSize; i++)
    {
        if (fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) < fitnessFunction->calculateFitness(population[i + 1], population[i + 1]->getNumGenes()))
        {
            Chromosome *temp = population[i];
            population[i] = population[i + 1];
            population[i + 1] = temp;
        }
    }

    return population;
}

Chromosome **GA::crossOver(Chromosome *c1, Chromosome *c2)
{
    Chromosome **children = new Chromosome *[2];
    children[0] = new Chromosome(c1);
    children[1] = new Chromosome(c2);
    return children;
}

Chromosome *GA::mutate(Chromosome *c1)
{
    return new Chromosome(c1);
}

double GA::calculateAvgAccuracy(FitnessFunction *fitnessFunction)
{
    double avg = 0;
    for (int i = 0; i < populationSize; i++)
    {
        avg += fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes());
    }
    return avg / populationSize;
}

double GA::calculateStd(FitnessFunction *fitnessFunction)
{
    double avg = 0;
    for (int i = 0; i < populationSize; i++)
    {
        avg += fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes());
    }
    avg /= populationSize;
    double std = 0;
    for (int i = 0; i < populationSize; i++)
    {
        std += pow(fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) - avg, 2);
    }

    return sqrt(std / populationSize);
}

double GA::calculateVariance()
{
    double avg = 0;
    for (int i = 0; i < populationSize; i++)
    {
        avg += *population[i]->getGenes();
    }

    return avg / populationSize;
}

void GA::setPopulation(Chromosome **p)
{
    this->population = p;
}