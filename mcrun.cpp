#include "mcrun.h"

#include <random>
#include <memory>
#include <vector>
#include <functional>
#include <numeric>

#include <boost/mpi/collectives.hpp>

#include "msgtags.h"

MCCResults mccrun_master(
  const QstatePotts& model, unsigned int num_bins,
  const std::set<observables_t>& obs, const boost::mpi::communicator& mpicomm,
)
{
    cout << "========== NEW MONTE CARLO CYCLE ==========" << endl;
    cout << ":: Preparing the simulation" << endl;

    vector< unique_ptr<Observable> > obscalc = prepare_obscalcs( obs, opts );
    ObservableCache obscache;

    unsigned int finished_workers = 0;
    unsigned int scheduled_bins = 0;
    unsigned int completed_bins = 0;
    unsigned int enqueued_bins  = num_bins;

}

void mccrun_slave(
  const QstatePotts& model,const std::set<observables_t>& obs,
  const boost::mpi::communicator& mpicomm
)
{

}
