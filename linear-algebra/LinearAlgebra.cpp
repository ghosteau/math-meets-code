#include "LinearAlgebra.h"

#include <stdexcept>

// Determinant via Laplace (cofactor) expansion along the first row
int LinearAlgebra::determinant(const std::vector<std::vector<int>>& matrix)
{
    const size_t n = matrix.size();

    // Edge cases
    if (n == 0)
    {
        throw std::invalid_argument("Empty matrix passed as argument");
    }

    // Determinant is only defined for n x n matrices
    for (const std::vector<int>& row : matrix)
    {
        if (row.size() != n)
        {
            throw std::invalid_argument("Rows and columns have to have the same dimensions");
        }
    }

    if (n == 1)
    {
        return matrix[0][0];
    }

    // Technically Laplace expansion would break down 2 x 2 matrices into their respective cofactors as well, but this simple formula works much easier
    // This is our real base-case
    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    int determinant = 0;

    // We need this loop to make sure we find every single necessary term, not just one
    for (size_t j = 0; j < n; j++)
    {
        int cofactor = matrix[0][j];

        // We will be expanding down row one always, so the sign is (-1)^(1 + (j + 1)), which is negative whenever j is odd
        if (j % 2 != 0)
        {
            cofactor = -cofactor;
        }

        // Find the minor matrix (that we have to take the determinant of): drop row 0 and column j
        std::vector<std::vector<int>> minor;
        for (size_t k = 1; k < n; k++)
        {
            std::vector<int> row;
            for (size_t l = 0; l < n; l++)
            {
                if (l != j)
                {
                    row.push_back(matrix[k][l]);
                }
            }

            minor.push_back(row);
        }

        determinant += cofactor * LinearAlgebra::determinant(minor);
    }

    return determinant;
}
