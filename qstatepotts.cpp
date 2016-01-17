#include "qstatepotts.h"

QStatePotts::QStatePotts()
{

}

QStatePotts::QStatePotts(double spin_coupling, size_t num_states, double beta)
{
    this->spin_coupling = spin_coupling;
    this->num_states = num_states;
    this->beta = beta;

    this->generator = new RandomGenerator(0,num_sites);
    this->scale_free_network = new Graph(num_sites);
}

QStatePotts::~QStatePotts()
{
    delete generator;
    delete scale_free_network;
}

void QStatePotts::set_beta(double &beta)
{
    this->beta = beta;
}

void QStatePotts::mcstep()
{

}
