#include "utils.hpp"
#include <random>
#include <iostream>

using namespace std;

// Generate a random number between min and max (include min and max)
int randomNumber(int min, int max){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(min,max); // distribution in range [min, max]

    return dist6(rng);
}