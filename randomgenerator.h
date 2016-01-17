#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>
#include <chrono>
class RandomGenerator
{
public:
    RandomGenerator();
    explicit RandomGenerator(int min,int max);
    ~RandomGenerator();
    int generate();
private:
    std::random_device* random_device;
    std::mt19937* mt;
    std::uniform_int_distribution* distribution;
};

#endif // RANDOMGENERATOR_H
