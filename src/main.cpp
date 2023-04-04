#include <iostream>
#include <random>
#include <climits>
#include "RNG.h"
#include <cstring>
#include <cstddef>
#include <vector>
#include <bitset>
#include "encoder.h"
#include "spookyhash.h"
using namespace std;

int main()
{

    string a;
    int k;
    vector<unsigned int> test;
    bitset<6> bs;
    bitset<64> bc;
    Encoder e(6, 8, 8,1);
    a = "325";
    e.encode(a, test);

    return 0;
}