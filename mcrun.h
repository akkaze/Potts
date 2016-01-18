#ifndef MCRUN_H
#define MCRUN_H

#include <set>

#include <boost/mpi/communicator.hpp>

#define EIGEN_NO_AUTOMATIC_RESIZING
#include <eigen3/Eigen/Core>

#include "mcresults.h"
#include "observable.h"


MCCResults mccrun_master(
  const QstatePotts& model, unsigned int num_bins,
  const std::set<observables_t>& obs, const boost::mpi::communicator& mpicomm
);

void mccrun_slave(
  const QstatePotts& model,const std::set<observables_t>& obs,
  const boost::mpi::communicator& mpicomm
);
#endif // MCRUN_H
