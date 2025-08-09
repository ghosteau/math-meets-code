#include "LinearAlgebra.h"

int LinearAlgebra::determinant(std::vector<std::vector<int>> matrix)
{
    int n = matrix.size();

    // Edge cases
    if (n == 0)
    {
        throw std::invalid_argument("Empty matrix passed as argument");
    }

    if (n == 1)
    {
        return matrix[0][0];
    }

    // Determinant is only defined for n x n matrices
    if (matrix.size() != matrix[0].size())
    {
        throw std::invalid_argument("Rows and columns have to have the same dimensions");
    }

    // Technically LaPlace expansion would break down 2 x 2 matrices into their respective cofactors as well, but this simple formula works much easier
    // This is our real base-case
    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    // Go across columns
    std::vector<int> cols = matrix[0];
    std::vector<int> terms;

    // We need this outer loop to make sure we find every single necessary term, not just one
    for (int j = 0; j < n; j++)
    {
        int cofactor = cols[j];

        // We will be expanding down row one always for this implementation... so that means 'i' (from the formula) will always equal 1
        // We add 1 to j because j starts at zero in our program, but in the formula j starts at 1. We could simplify the if to just be j % 2 using this fact if we wanted
        // Anyways, all we gotta do is check if we have an odd power and then apply the negation if so
        if (((j + 1) + 1) % 2 != 0)
        {
            cofactor = -(cofactor);
        }

        // Find the minor matrix (that we have to take the determinant of)
        std::vector<std::vector<int>> minor;
        for (int k = 0; k < n; k++)
        {
            if (k == 0)
            {
                continue;
            }

            std::vector<int> row;
            for (int l = 0; l < n; l++)
            {
                if (l == j)
                {
                    continue;
                }

                row.push_back(matrix[k][l]);
            }

            minor.push_back(row);
        }

        terms.push_back(cofactor * determinant(minor));
    }

    // Because we just stored all of the terms in an array, we can just go through and add each one up per the formula
    // This seemed like the easiest way to go about it to me (with LaPlace Expansion), but I am sure there are others
    int determinant = 0;
    for (int term : terms)
    {
        determinant += term;
    }

    return determinant;
}