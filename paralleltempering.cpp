#include "paralleltempering.h"

#include <math.h>
ParallelTempering::ParallelTempering(double spin_coupling, size_t num_states)
{
    init_beta();
    systems.reserve(num_systems);
    for(size_t idx = 0;idx < num_systems;idx++) {
        QStatePotts* system = new QStatePotts(spin_coupling,num_states,betas[idx]);
        systems.push_back(system);
    }
    generator = new RandomGenerator(0,num_systems);
}

ParallelTempering::~ParallelTempering()
{
    delete generator;
    for(size_t idx = 0;idx < num_systems;idx++) {
        delete systems[idx];
    }
    systems.clear();
}

void ParallelTempering::init_beta()
{
    betas.reserve(num_systems);
    double norm = (temp_max - temp_min) / (num_systems * num_systems);
    for(size_t idx_sys; idx_sys < num_systems;idx_sys++) {
        double beta = 1.0 / (norm * idx_sys * idx_sys + temp_min);
        betas.push_back(beta);
    }
    return;
}

void ParallelTempering::move()
{
    vector<int> random_nums;
    random_nums.reserve(num_systems);
    for(size_t idx = 0;idx < num_systems; idx++)
    {
        random = generator -> generate();
        random_nums.push_back(random);
    }
    for(size_t idx_move = 0; idx_move < num_moves; idx_move++){
        for(size_t idx_sys = 0; idx_sys < num_systems - 1; idx_sys++) {
            double& beta1 = betas[idx_sys];
            double& beta2 = betas[idx_sys + 1];

            energy1 = systems[idx_sys]->energy();
            energy2 = systems[idx_sys + 1]->energy();

            if(random_nums[idx_sys] < exp((beta1 - beta2) * (energy1 - energy2) )) {
               QStatePotts* temp_sys = systems[idx_sys];
               systems[idx_sys] = systems[idx_sys + 1];
               systems[idx_sys + 1] = temp_sys;

               systems[idx_sys]->set_beta(beta2);
               systems[idx_sys + 1]->set_beta(beta1);
            }
        }
    }
}

