#include <cmath> 
#include <vector>
#include <iostream> 

using namespace std; 

class SignTest
{
private: 
    int testStat = 0; 
    int n = 0;

public: 
    double signtest(double median, double prop, int n)
    {
        double mean = n * prop;
        double sigma = sqrt(n * prop * (1 - prop));
        
    }
    int getTestStat(vector<int> &data, double median)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] > median)
            {
                testStat++;
            }
            if (data[i] == median)
            {
                n--;
            }
        }
        return testStat;
    }
};
