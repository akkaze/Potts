#ifndef QSTATEPOTTS_H
#define QSTATEPOTTS_H
#include "boost/graph/adjacency_list.hpp"

class QStatePotts
{
public:
    QStatePotts();

    double energy();

    void set_beta(double& beta);
private:
    double spin_coupling;
    size_t num_states;
    double beta;

};

#endif // QSTATEPOTTS_H
