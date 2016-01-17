#ifndef PARALLELTEMPERING_H
#define PARALLELTEMPERING_H

#include "qstatepotts.h"
#include "randomgenerator.h"

#include "boost/optional.hpp"
#include <vector>

using namespace std;
class ParallelTempering
{
public:
    ParallelTempering(double spin_coupling,size_t num_states);
    ~ParallelTempering();
    void init_beta();
    void move();
private:
    vector<QStatePotts*> systems;
    vector<double> betas;

    RandomGenerator* generator;
    double temp_max;
    double temp_min;
    double beta_min;
    double beta_max;
    size_t num_systems;
    size_t num_moves;
    size_t steps_per_move;
};

#endif // PARALLELTEMPERING_H
