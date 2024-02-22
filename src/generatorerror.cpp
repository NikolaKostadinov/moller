#include "../include/generatorerror.hpp"

template <class T>
GeneratorError<T>::GeneratorError(size_t _data_size_) : Generator<T>(_data_size_)
{

}

template <class T>
T GeneratorError<T>::errorFunction(T _input_) const
{
    return _input_;
}

template <class T>
T* GeneratorError<T>::generate(T* _to_input_) const
{
    T* to_output = new T[Generator<T>::_data_size];
    generateTo(_to_input_, to_output);
    return to_output;
}

template <class T>
void GeneratorError<T>::generateTo(T* _to_input_, T* _to_output_) const
{
    for (unsigned int i = 0u; i < Generator<T>::_data_size; i++)
    {
        std::random_device rand_dev;
        std::uniform_real_distribution<double> dist(-1.0, +1.0);
        double rel_err = dist(rand_dev);
        
        T this_value = *(_to_input_ + i);
        T new_value  = this->function(this_value) + rel_err*errorFunction(this_value);
        *(_to_output_ + i) = new_value;
    }
}

template <class T>
T* GeneratorError<T>::generateError(T* _to_input_) const
{
    T* to_new_errors = new T[Generator<T>::_data_size];
    for (unsigned int i = 0u; i < Generator<T>::_data_size; i++)
    {
        T this_value = *(_to_input_ + i);
        T new_error  = errorFunction(this_value);
        *(to_new_errors + i) = new_error;
    }
    return to_new_errors;
}

template class GeneratorError<int   >;
template class GeneratorError<float >;
template class GeneratorError<double>;
