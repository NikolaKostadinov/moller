#include "../include/generator.hpp"

template <class T>
Generator<T>::Generator(size_t _data_size_) : _data_size(_data_size_)
{

}

template <class T>
T Generator<T>::function(T _input_) const
{
    return _input_;
}

template <class T>
T* Generator<T>::generate(T* _to_data_) const
{
    T* to_new_data = new T[_data_size];
    for (unsigned int i = 0; i < _data_size; i++)
    {
        T this_value = *(_to_data_ + i);
        T new_value  = function(this_value);
        *(to_new_data + i) = new_value;
    }
    return to_new_data;
}

template class Generator<int>;
template class Generator<float>;
template class Generator<double>;