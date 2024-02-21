#include "../include/moller.hpp"

#define SQ(X) (X*X)

Moller::Moller(size_t _dataSize_, double _momentum_, double _mass_, double _coupling_, char _limit_) : 
    GeneratorErrorFile<double, double>(_dataSize_, MOLLER_PATH, MOLLER_X_HEADER, MOLLER_Y_HEADER, MOLLER_E_HEADER),
    _momentum(_momentum_),
    _mass(_mass_),
    _coupling(_coupling_),
    _limit(_limit_)
{

}

double Moller::function(double _input_) const
{
    if (_input_ == 0.0   ) return 0.0;
    if (_input_ == 2*M_PI) return 0.0;
     
    double energy2 = SQ(_momentum) + SQ(_mass);
    double eaux2   = SQ(_momentum) + energy2;
    double ecm2    = 4 * energy2;
    double alpha   = SQ(_coupling)/(4 * M_PI);
    double sine    = sin(_input_);
    double cosine  = cos(_input_);
    double sin2    = SQ(sine);
    double cos2    = SQ(cosine);
    double p4      = SQ(SQ(_momentum));
    double m4      = SQ(SQ(_mass));

    double factor  = CONVERT_FACTOR*(alpha * alpha)/(ecm2 * p4 * sin2 * sin2);

    switch (_limit)
    {
        case LIMIT_RELATIVISTIC: return factor*(4*SQ(eaux2) + (4*p4 - 3*SQ(eaux2))*sin2 + p4*SQ(sin2));
        case LIMIT_CLASSICAL:    return factor*m4*  (1 + 3*cos2);
        case LIMIT_ULTRA:        return factor*p4*SQ(3 +   cos2);
        default:                 return 0.0;
    }
}

double Moller::errorFunction(double _input_) const
{
    return .1;
}