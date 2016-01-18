#ifndef MCRESULTS
#define MCRESULTS

#include <vector>
#include <numeric>
#include <iosfwd>
#include <cmath>

#include <boost/optional.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/optional.hpp>

#define EIGEN_NO_AUTOMATIC_RESIZING
#include <eigen3/Eigen/Core>


template <typename Ti>
struct UncertainQuantity {

  Ti mean, sigma;

  UncertainQuantity() {}

  UncertainQuantity( Ti mean_init, Ti sigma_init )
    : mean( mean_init ), sigma( sigma_init ) { }

  template< typename Te >
  UncertainQuantity( const std::vector<Te>& binmeans ) {
    // calculate the average of the binmeans
    mean =
      static_cast<Ti>(
        accumulate( binmeans.begin(), binmeans.end(), Te(0) )
      ) / static_cast<Ti>( binmeans.size() );

    // calculate the variance of the binmeans
    Ti binmeans_variance =
      static_cast<Ti>( binmeans.size() ) /
      static_cast<Ti>( binmeans.size() - 1 ) *
      (
        static_cast<Ti>( accumulate(
          binmeans.begin(), binmeans.end(), Te(0),
          []( Te sum, Te m ) { return sum + m * m; }
        ) ) / static_cast<Ti>( binmeans.size() )
        - mean * mean
      );

    // if binmeans variance is negative this is floating point precision
    // problem (cancellation when subtracting mean^2)
    binmeans_variance = std::max( binmeans_variance, 0.0 );

    // uncertainty of the mean is sqrt(variance / num_bins)
    sigma = std::sqrt( binmeans_variance / static_cast<Ti>( binmeans.size() ) );
  }

  // make UncertainQuantity serializable
  friend class boost::serialization::access;
  template<class Archive>
  void serialize( Archive& ar, const unsigned int ) {
    ar & mean;
    ar & sigma;
  }
};


struct MCCResults {

  boost::optional< UncertainQuantity<double> > E;
  boost::optional< UncertainQuantity<double> > m;
  boost::optional< Eigen::MatrixXd > sscorr;

  void write_to_files( const boost::filesystem::path& dir ) const;
};
std::ostream& operator<<( std::ostream& out, const MCCResults& res );


#endif // MCRESULTS

