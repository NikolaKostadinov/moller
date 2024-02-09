#pragma once

#include <cstddef>

// 
// class `Generator`
//
// A `Generator` generates a pointer to
// values which are the result of an given
// function acting on a given pointer.
// This class acts as an interface.
//

template <class T>
class Generator
{   
    public:

        Generator(size_t _data_size_);
        
        size_t    getSize()                                const;
        void      setSize(size_t _data_size_)                   ;

        virtual T function  (T  _input_  )                 const;  // default: identity function
        T*        generate  (T* _to_data_)                 const;
        void      generateTo(T* _to_data_, T* _to_result_) const;

    protected:

        size_t    _data_size;
};