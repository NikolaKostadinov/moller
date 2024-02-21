#pragma once

#include <fstream>
#include <iostream>
#include <string>

void importDataFromTo(
    const char* _path_,
    double*     _to_x_,
    double*     _to_y_,
    double*     _to_e_
)
{
    std::ifstream file(_path_);

    unsigned int i = 0;
    std::string  x;
    std::string  y;
    std::string  e;
    while (file >> x >> y >> e)
    {
      *(_to_x_ + i) = std::atof(x.c_str());
      *(_to_y_ + i) = std::atof(y.c_str());
      *(_to_e_ + i) = std::atof(e.c_str());
      i++;
    }

    file.close();
}

void importDataFromTo(
    const char* _path_,
    double*     _to_x_,
    double*     _to_y_
)
{
    std::ifstream file(_path_);

    unsigned int i = 0;
    std::string  x;
    std::string  y;
    while (file >> x >> y)
    {
      *(_to_x_ + i) = std::atof(x.c_str());
      *(_to_y_ + i) = std::atof(y.c_str());
      i++;
    }

    file.close();
}