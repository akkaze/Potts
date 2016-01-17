#ifndef QSTATEPOTTS_H
#define QSTATEPOTTS_H
#include "randomgenerator.h"

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/graph_traits.hpp"

using namespace boost;
typedef adjacency_list<vecS, vecS, undirectedS> Graph;
class QStatePotts
{
public:
    QStatePotts();
    QStatePotts(double spin_coupling,size_t num_states,double beta);
    ~QStatePotts();
    double energy();

    void mcstep();
    void set_beta(double& beta);
private:
    double spin_coupling;
    size_t num_states;
    double beta;
    size_t num_sites;
    RandomGenerator* generator;

    Graph* scale_free_network;
};

#endif // QSTATEPOTTS_H
