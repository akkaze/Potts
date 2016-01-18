#ifndef OPTIONS_H
#define OPTIONS_H

#include <boost/program_options/variables_map.hpp>

enum optmode_t {
  OPTION_MODE_OPTIMIZATION,
  OPTION_MODE_SIMULATION,
  OPTION_MODE_ANALYSIS
};

enum optpairsym_t {
  OPTION_PAIRING_SYMMETRY_SWAVE,
  OPTION_PAIRING_SYMMETRY_DWAVE,
  OPTION_PAIRING_SYMMETRY_DWAVE_TWISTED
};

typedef boost::program_options::variables_map Options;

Options read_options( int argc, char* argv[], bool is_master );
class Options
{
public:
    Options();
};

#endif // OPTIONS_H
