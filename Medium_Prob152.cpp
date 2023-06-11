/* You are given n numbers as well as n probabilities that sum up to 1. 
Write a function to generate one of the numbers with its corresponding probability.*/

#include <iostream>
#include <vector>

using namespace std;

void generateAccordingNumber(vector<float>& probability, vector<float>& numbers)
{
    int n = numbers.size();

    // Random generator
    srand(time(0));
    float random = (float)(rand()) / (float)(RAND_MAX);

    float bornInf = 0;
    float bornSup = probability[0];

    bool notFind = true;
    int iterator = 0;

    while(notFind)
    {
        cout << "R " << random << " B+ " << bornSup << " i " << iterator << endl;
        if (random > bornSup)
        {
            iterator += 1;
            if (iterator + 1 == n)
            {
                bornSup = 1;
            }
            else
            {
                bornSup += probability[iterator];
            }
        }
        else
        {
            notFind = false;
        }
    }

    cout << numbers[iterator] << endl;
}

int main(int argc, char *argv[])
{
    vector<float> list = {5,4,3,2,1};
    vector<float> proba = {0.05,0.2,0.2,0.1,0.45};

    generateAccordingNumber(proba, list);
    
}