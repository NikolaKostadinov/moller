#pragma once

#include <fstream>
#include "../include/generator.hpp"

#define DEFAULT_X_HEADER "X"
#define DEFAULT_Y_HEADER "Y"
#define DEFAULT_DELIM    "\t"

template <class T>
class GeneratorFile : public Generator<T>
{
    public:

        GeneratorFile(
            size_t      _data_size_,
            const char* _path_,
            const char* _x_header_ = DEFAULT_X_HEADER,
            const char* _y_header_ = DEFAULT_Y_HEADER,
            const char* _delim_    = DEFAULT_DELIM
        );

        void generateFile(T* _to_data_) const;

    protected:

        const char* _path;
        const char* _x_header;
        const char* _y_header;
        const char* _delim;
};