#include "../include/generatorerrorfile.hpp"

template <class T, typename E>
GeneratorErrorFile<T, E>::GeneratorErrorFile(size_t _data_size_, const char* _path_, const char* _x_header_, const char* _y_header_, const char* _e_header_, const char* _delim_) :
GeneratorError<T, E>(_data_size_),
_path(_path_),
_x_header(_x_header_),
_y_header(_y_header_),
_e_header(_e_header_),
_delim(_delim_)
{

}

template <class T, typename E>
void GeneratorErrorFile<T, E>::generateFile(T* _to_data_) const
{
    std::ofstream file(_path, std::ofstream::out | std::ofstream::trunc);

    file << _x_header << _delim << _y_header << _delim << _e_header << '\n';

    for (unsigned int i = 0; i < this->_data_size; i++)
    {
        T this_value = *(_to_data_ + i);
        T new_value  = this->     function(this_value);
        E new_error  = this->errorFunction(this_value);
        file << this_value << _delim << new_value << _delim << new_error << '\n';
    }

    file.close();
}

template class GeneratorErrorFile<int,    float >;
template class GeneratorErrorFile<float,  float >;
template class GeneratorErrorFile<double, float >;
template class GeneratorErrorFile<int,    double>;
template class GeneratorErrorFile<float,  double>;
template class GeneratorErrorFile<double, double>;