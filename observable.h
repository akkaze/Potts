#ifndef OBSERVABLE_H
#define OBSERVABLE_H


#include <boost/mpi/communicator.hpp>
#include <boost/optional.hpp>

#define EIGEN_NO_AUTOMATIC_RESIZING
#include <eigen3/Eigen/Core>

#include "qstatepotts.h"
#include "mcresults.h"

enum observables_t {
  OBSERVABLE_E,
  OBSERVABLE_M,
  OBSERVABLE_SPIN_SPIN_CORRELATION
};


struct ObservableCache final
{
  boost::optional<double> E;
  boost::optional< Eigen::VectorXi > s;

  void clear() {
    E = boost::none;
    s = boost::none;
  }
};


class Observable
{
  public:

    virtual ~Observable() {}

    virtual void measure(
      const ModelManager& model,
      ObservableCache& cache
    ) = 0;

    virtual void completebin() = 0;

    virtual void collect_and_write_results(
      const boost::mpi::communicator& mpicomm,
      MCCResults& results
    ) const = 0;
    virtual void send_results_to_master(
      const boost::mpi::communicator& mpicomm
    ) const = 0;
};
#endif // OBSERVABLE_H
