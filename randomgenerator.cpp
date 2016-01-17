#include "randomgenerator.h"

RandomGenerator::RandomGenerator()
{
    std::chrono::time_point now= std::chrono::system_clock::now();
    int time_since_epoch = std::chrono::duration_cast<int>(now.time_since_epoch());
    random_device = new std::random_device();
    mt = new std::mt19937(random_device);
    mt->seed(time_since_epoch);
}

RandomGenerator::RandomGenerator(min, max)
{
    std::chrono::time_point now= std::chrono::system_clock::now();
    int time_since_epoch = std::chrono::duration_cast<int>(now.time_since_epoch());
    random_device = new std::random_device();
    mt = new std::mt19937(random_device);
    mt->seed(time_since_epoch);
    distribution = new std::uniform_int_distribution(min,max);
}

RandomGenerator::~RandomGenerator()
{
    delete random_device;
    delete mt;
    delete distribution;
}

int RandomGenerator::generate()
{
    return distribution->operator ();
}

