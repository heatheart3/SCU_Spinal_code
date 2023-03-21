//
// Created by lenovo on 2023/3/14.
//

#ifndef SPINAL_CODE_RNG_H
#define SPINAL_CODE_RNG_H
#include <random>
class RNG{

    private:
        int c;
        int seed;
        int mask;
        std::default_random_engine e;
    public:
        RNG();
        RNG(int c, int seed);
        int RNGnext();

    int getC() const;

    int getSeed() const;

    int getMask() const;

    void setC(int c);

    void setSeed(int seed);

    void setMask(int mask);


};
#endif //SPINAL_CODE_RNG_H
