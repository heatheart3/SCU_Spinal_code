//
// Created by lenovo on 2023/3/14.
//

#include "RNG.h"
#include <source.h>
RNG::RNG(int c, int seed): e(seed){

    //value c backup. when debugging we can check the value of mask with the correct result that is generated by c
    this-> c = c;
    //value seed backup
    this -> seed = seed;
    if( c >= 32)
    {
        this->mask = INT32_MAX;
    }
    else
    {
        this->mask = (1 << c) - 1;
    }


};

RNG::RNG():e(0) {
    seed = 0;
    c = 32;
    RNG::mask = INT32_MAX;
}

int RNG::RNGnext() {
    return  (e() & this-> mask);
}

int RNG::getC() const {
    return c;
}

int RNG::getSeed() const {
    return seed;
}

int RNG::getMask() const {
    return mask;
}

void RNG::setC(int c) {
    RNG::c = c;
}

void RNG::setSeed(int seed) {
    RNG::seed = seed;
}

void RNG::setMask(int mask) {
    RNG::mask = mask;
}
