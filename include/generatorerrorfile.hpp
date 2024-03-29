#pragma once

#include <fstream>
#include "../include/generatorerror.hpp"

#define DEFAULT_X_HEADER "X"
#define DEFAULT_Y_HEADER "Y"
#define DEFAULT_E_HEADER "E"
#define DEFAULT_DELIM    "\t"

//
// class `GeneratorErrorFile<T>`
//
// `Generator<T>` -> `GeneratorError<T>` -> `GeneratorErrorFile<T>`
//

template <class T>
class GeneratorErrorFile : public GeneratorError<T>
{
    public:

        GeneratorErrorFile(
            size_t      _data_size_,
            const char* _path_,
            const char* _x_header_ = DEFAULT_X_HEADER,
            const char* _y_header_ = DEFAULT_Y_HEADER,
            const char* _e_header_ = DEFAULT_E_HEADER,
            const char* _delim_    = DEFAULT_DELIM
        );

        void generateFile(T* _to_input_) const;

    protected:

        const char* _path;
        const char* _x_header;
        const char* _y_header;
        const char* _e_header;
        const char* _delim;
};