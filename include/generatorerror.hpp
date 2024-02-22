#pragma once

#include <random>
#include <iostream>

#include "../include/generator.hpp"

// 
// class `GeneratorError<T>`
//
// A `GeneratorError<T>` is an extension
// of a `Generator<T>`. The additional structure
// of `GeneratorError<T>` is a generating
// function for absolute errors.
//
// To inherit this class one must override
// the virtual methods `T finction(T) const`
// and `T errorFunction(T) const`.
//
// `Generator<T>` -> `GeneratorError<T>`
//

template <class T>
class GeneratorError : public Generator<T>
{
    public:

        GeneratorError(size_t _data_size_);

        virtual T errorFunction(T     _input_)                 const;      // default: 100% relative error
        T*        generate(     T* _to_input_)                 const;
        T*        generateError(T* _to_input_)                 const;
        void      generateTo(   T* _to_input_, T* _to_output_) const;
};