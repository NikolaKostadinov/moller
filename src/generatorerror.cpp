#include "../include/generatorerror.hpp"

template <class T, typename E>
GeneratorError<T, E>::GeneratorError(size_t _data_size_) : Generator<T>(_data_size_)
{

}

template <class T, typename E>
E GeneratorError<T, E>::errorFunction(T _input_) const
{
    std::srand(time(0));
    return (E)(ERROR_CONST/rand());
}

template <class T, typename E>
E* GeneratorError<T, E>::generateError(T* _to_data_) const
{
    E* to_new_errors = new E[Generator<T>::_data_size];
    for (unsigned int i = 0; i < Generator<T>::_data_size; i++)
    {
        T this_value = *(_to_data_ + i);
        E new_error  = errorFunction(this_value);
        *(to_new_errors + i) = new_error;
    }
    return to_new_errors;
}

template class GeneratorError<int,    float >;
template class GeneratorError<float,  float >;
template class GeneratorError<double, float >;
template class GeneratorError<int,    double>;
template class GeneratorError<float,  double>;
template class GeneratorError<double, double>;