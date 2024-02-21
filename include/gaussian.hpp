#pragma once

#include <cmath>
#include "../include/generatorfile.hpp"

#define DEFAULT_MEAN      0.0
#define DEFAULT_DEVIATION 1.0

class Gaussian : public GeneratorFile<double>
{
    public:

        Gaussian(
            size_t _dataSize_,
            double _mean_      = DEFAULT_MEAN,
            double _deviation_ = DEFAULT_DEVIATION
        );

        double function(double _input_) const override;
    
    private:

        double _mean     ;
        double _deviation;
};