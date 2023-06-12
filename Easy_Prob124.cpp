/* You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.*/


#include <iostream>
#include <cmath>

using namespace std;

int flipCoins(int n)
{
    float random = 0.0;
    int stayingCoin = n;
    
    for (int i=0; i<n; i++)
    {
        random = (float)(rand()) / (float)(RAND_MAX);
        if (random >= 0.5)
        {
            stayingCoin -= 1;
        }
    }
    return stayingCoin;
}

int calculRounds(int n)
{
    int stayingCoin = n;
    int round = 0;

    while (stayingCoin > 0)
    {
        round += 1;
        stayingCoin = flipCoins(stayingCoin);
    }

    return round;
}

int main(int argc, char *argv[])
{
    int n = 5;
    srand(time(0));

    cout << calculRounds(n) << endl;


}