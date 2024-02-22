#pragma once

#include <cstddef>

// 
// class `Generator<T>`
//
// A `Generator<T>` generates a pointer to
// values of type/class `T` which are the
// result of an given function (`T function(T) const`)
// acting on a input pointer. This class acts
// as an interface.
//
// To inherit this class one must override
// the virtual method `T finction(T) const`. To
// generate the output of the function to a new
// pointer `T*` apply the predefined method
// `T* generate(T*) const`.
//

template <class T>
class Generator
{   
    public:

        Generator(size_t _data_size_);
        
        size_t    getSize()                                 const;
        void      setSize(size_t _data_size_)                    ;

        virtual T function  (T     _input_)                 const;  // default: identity function
        T*        generate  (T* _to_input_)                 const;
        void      generateTo(T* _to_input_, T* _to_output_) const;

    protected:

        size_t    _data_size;
};