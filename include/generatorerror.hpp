#pragma once

#include <cstdlib>
#include <time.h>
#include "../include/generator.hpp"

#define ERROR_CONST 1.2e+07

// 
// class `GeneratorError<T, E>`
//
// A `GeneratorError<T, E>` is an extension
// of a `Generator<T>`. The additional structure
// of `GeneratorError<T, E>` is a generating
// function for relative errors of type `E`.
// Accepted types of `E` are `float` and `double`.
//
// To inherit this class one must override
// the virtual methods `T finction(T) const`
// and `E errorFunction(T) const`.
//
// `Generator<T>` -> `GeneratorError<T, E>`
//

template <class T, typename E>                            // `E` could be `float` or `double` 
class GeneratorError : public Generator<T>
{
    public:

        GeneratorError(size_t _data_size_);

        virtual E errorFunction(T  _input_  ) const;      // default: random function
        E*        generateError(T* _to_data_) const;
};