#include "../include/generator.hpp"

template <class T>
Generator<T>::Generator(size_t _data_size_) : _data_size(_data_size_)
{

}

template <class T>
size_t Generator<T>::getSize() const
{
    return _data_size; 
}

template <class T>
void Generator<T>::setSize(size_t _data_size_)
{
    _data_size = _data_size_;
}

template <class T>
T Generator<T>::function(T _input_) const
{
    return _input_;
}

template <class T>
T* Generator<T>::generate(T* _to_input_) const
{
    T* to_output = new T[_data_size];
    generateTo(_to_input_, to_output);
    return to_output;
}

template <class T>
void Generator<T>::generateTo(T* _to_input_, T* _to_output_) const
{
    for (unsigned int i = 0; i < _data_size; i++)
    {
        T this_value = *(_to_input_ + i);
        T new_value  = function(this_value);
        *(_to_output_ + i) = new_value;
    }
}

template class Generator<int>;
template class Generator<float>;
template class Generator<double>;