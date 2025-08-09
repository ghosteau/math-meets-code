// LinearAlgebra.h
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <vector>
#include <stdexcept>

class LinearAlgebra
{
public:
    static int determinant(std::vector<std::vector<int>> matrix);
};

#endif