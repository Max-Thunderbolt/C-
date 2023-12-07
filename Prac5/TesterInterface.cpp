#include "TesterInterface.h"
#include <cstddef>
#include <iostream>

TesterInterface::TesterInterface(int maxNumTests)
{
    // std::cout << maxNumTests << std::endl;
    if (maxNumTests < 1)
    {
        this->maxNumTesters = 0;
        this->currNumTesters = 0;
        // this->testers = new NumberTester *[0];
    }
    else
    {
        this->testers = new NumberTester *[maxNumTests];
        // std::cout << "created numberTester array" << std::endl;
        this->maxNumTesters = maxNumTests;
        for (int i = 0; i < maxNumTests; i++)
        {
            this->testers[i] = NULL;
        }
        this->currNumTesters++;
    }
}

TesterInterface::TesterInterface(TesterInterface *other)
{
    // NumberTester **temp = new NumberTester *[maxNumTesters];

    // if (other == NULL)
    // {
    //     for (int i = 0; i < maxNumTesters; i++)
    //     {
    //         temp[i] = 0;
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < maxNumTesters; i++)
    //     {
    //         temp[i] = other->testers[i];
    //     }
    // }
}

TesterInterface::TesterInterface(TesterInterface &other)
{
    // NumberTester **otherTemp = new NumberTester *[maxNumTesters];

    // for (int i = 0; i < maxNumTesters; i++)
    // {
    //     otherTemp[i] = other[i];
    // }
}

TesterInterface::~TesterInterface()
{
    for (int i = 0; i < maxNumTesters; i++)
    {
        testers[i] = NULL;
        // this->currNumTesters--;
    }
    testers = NULL;
}

int TesterInterface::addTester(NumberTester *tester)
{
    // std::cout << maxNumTesters << std::endl;
    if (testers == NULL)
    {
        // std::cout << "testers is null" << std::endl;
        return -1;
    }
    // std::cout << "testers is not null" << std::;
    for (int i = 0; i < maxNumTesters; i++)
    {
        // std::cout << "adding tester " << tester << std::endl;
        if (testers[i] == NULL)
        {
            this->currNumTesters++;
            testers[i] = tester;
            return i;
        }
    }
    return -1;
}

bool TesterInterface::removeTester(int pos)
{
    bool ret;
    if (pos < 0 || pos > maxNumTesters)
    {
        ret = false;
    }
    else
    {
        testers[pos] = NULL;
        delete testers[pos];
        currNumTesters--;
        ret = true;
    }

    return ret;
}

bool TesterInterface::evaluate(int num)
{
    // std::cout << "evaluating " << num << std::endl;
    bool ret;
    // std::cout << "before for loop" << std::endl;
    for (int i = 0; i < maxNumTesters; i++)
    {
        // std::cout << "Inside for loop" << std::endl;
        if (testers[i] != NULL)
        {
            // std::cout << "inside if statement" << std::endl;
            if (testers[num] == false)
            {
                // std::cout << "inside if statement 2" << std::endl;
                ret = false;
            }
        }
    }
    ret = true;
    // std::cout << ret <<std::endl;
    return ret;
}

int *TesterInterface::failedTests(int num)
{
    int *ret = new int[maxNumTesters];
    int counter = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
        {
            if (testers[i]->evaluate(num) == false)
            {
                ret[counter] = i;
                counter++;
            }
        }
    }
    int *ret2 = new int[counter];
    for (int i = 0; i < counter; i++)
    {
        ret2[i] = ret[i];
    }
    return ret2;
}

int TesterInterface::numberOfFailedTests(int num)
{
    int counter = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
        {
            if (testers[i]->evaluate(num) == false)
            {
                counter++;
            }
        }
    }
    return counter;
}

NumberTester *TesterInterface::operator[](int pos)
{
    if (pos < 0 || pos > maxNumTesters)
    {
        return NULL;
    }
    else
    {
        return testers[pos];
    }
}

const int TesterInterface::getCurrNumTesters()
{
    return currNumTesters;
}

const int TesterInterface::getMaxNumTesters()
{
    return maxNumTesters;
}