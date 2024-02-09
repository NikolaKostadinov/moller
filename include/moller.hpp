#pragma once

#include <cmath>
#include "../include/generatorerrorfile.hpp"

#define LIMIT_RELATIVISTIC 0x00
#define LIMIT_CLASSICAL    0x01
#define LIMIT_ULTRA        0x02

#define DEFAULT_MASS       1.00000000
#define DEFAULT_COUPLING   0.30282212
#define DEFAULT_LIMIT      LIMIT_RELATIVISTIC

#define MOLLER_PATH        "./data/moller.dat"
#define MOLLER_X_HEADER    "THETA"
#define MOLLER_Y_HEADER    "SIGMA"
#define MOLLER_E_HEADER    "ERROR"

class Moller : public GeneratorErrorFile<double, double>
{
    public:

        Moller(
            size_t _dataSize_,
            double _momentum_,
            double _mass_     = DEFAULT_MASS,
            double _coupling_ = DEFAULT_COUPLING,
            char   _limit_    = DEFAULT_LIMIT
        );

        double      function(double _input_) const override;
        double errorFunction(double _input_) const override;
    
    private:

        double _momentum;
        double _mass;
        double _coupling;
        char   _limit;
};