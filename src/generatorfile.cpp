#include "../include/generatorfile.hpp"

template <class T>
GeneratorFile<T>::GeneratorFile(size_t _data_size_, const char* _path_, const char* _x_header_, const char* _y_header_, const char* _delim_) :
    Generator<T>(_data_size_),
    _path(_path_),
    _x_header(_x_header_),
    _y_header(_y_header_),
    _delim(_delim_)
{

}

template <class T>
void GeneratorFile<T>::generateFile(T* _to_data_) const
{
    std::ofstream file(_path, std::ofstream::out | std::ofstream::trunc);

    file << _x_header << _delim << _y_header << '\n';

    for (unsigned int i = 0; i < Generator<T>::_data_size; i++)
    {
        T this_value = *(_to_data_ + i);
        T new_value  = Generator<T>::function(this_value);
        file << this_value << _delim << new_value << '\n';
    }

    file.close();
}

template class GeneratorFile<int>;
template class GeneratorFile<float>;
template class GeneratorFile<double>;