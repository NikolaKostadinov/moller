#pragma once

#include <cstddef>

template <class T>
class Generator
{   
    public:

        Generator(size_t _data_size_);
        
        virtual T function(T  _input_  ) const;  // default: identity function
        T*        generate(T* _to_data_) const;

    protected:

        size_t    _data_size;
};