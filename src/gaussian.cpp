#include "../include/gaussian.hpp"

Gaussian::Gaussian(size_t _dataSize_, double _mean_, double _deviation_) :
    GeneratorFile<double>(_dataSize_, "./data/gauss.dat"),
    _mean(_mean_),
    _deviation(_deviation_)
{
    
}

double Gaussian::function(double _input_) const
{
    double x = (_input_ - _mean)/_deviation;
    return exp(-x*x/2);
}