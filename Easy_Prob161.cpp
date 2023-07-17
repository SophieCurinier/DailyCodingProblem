/* Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111. */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int bits = 2;
    
    int reversedBits = ~bits;
    for (int i = 31; i >= 0; i--) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << std::endl;
    for (int i = 31; i >= 0; i--) {
        std::cout << ((reversedBits >> i) & 1);
    }
    std::cout << std::endl;
}