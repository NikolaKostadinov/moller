#pragma once

#include <cstdlib>
#include <time.h>
#include "../include/generator.hpp"

#define ERROR_CONST 1.2e+07

template <class T, typename E>                            // `E` could be `float` or `double` 
class GeneratorError : public Generator<T>
{
    public:

        GeneratorError(size_t _data_size_);

        virtual E errorFunction(T  _input_  ) const;      // default: random function
        E*        generateError(T* _to_data_) const;
};