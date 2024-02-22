#include "../include/generatorerrorfile.hpp"

template <class T>
GeneratorErrorFile<T>::GeneratorErrorFile(size_t _data_size_, const char* _path_, const char* _x_header_, const char* _y_header_, const char* _e_header_, const char* _delim_) :
GeneratorError<T>(_data_size_),
_path(_path_),
_x_header(_x_header_),
_y_header(_y_header_),
_e_header(_e_header_),
_delim(_delim_)
{

}

template <class T>
void GeneratorErrorFile<T>::generateFile(T* _to_input_) const
{
    std::ofstream file(_path, std::ofstream::out | std::ofstream::trunc);
    file << _x_header << _delim << _y_header << _delim << _e_header << '\n';

    T* to_output = GeneratorError<T>::generate(_to_input_);
    for (unsigned int i = 0u; i < this->_data_size; i++)
    {
        T this_input  = *(_to_input_ + i);
        T this_output = *( to_output + i);
        T this_error  = this->errorFunction(this_input);
        file << this_input << _delim << this_output << _delim << this_error << '\n';
    }

    file.close();
}

template class GeneratorErrorFile<int   >;
template class GeneratorErrorFile<float >;
template class GeneratorErrorFile<double>;