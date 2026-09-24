#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <vector>

class LinearAlgebra
{
public:
    // Throws std::invalid_argument for empty or non-square matrices
    static int determinant(const std::vector<std::vector<int>>& matrix);
};

#endif
