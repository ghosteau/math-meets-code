#include <iostream>
#include <vector>
#include "LinearAlgebra.h"

int main()
{
    std::vector<std::vector<int>> dead_matrix;

    std::vector<std::vector<int>> one_cell_matrix =
    {
        {12}
    };

    std::vector<std::vector<int>> small_matrix =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> regular_matrix =
    {
        {2, 3, 1, 5, 4},
        {1, 1, 2, 0, 3},
        {0, 2, 4, 1, 5},
        {3, 0, 1, 2, 1},
        {1, 4, 0, 3, 2}
    };

    std::vector<std::vector<int>> non_square_matrix =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::vector<std::vector<int>> big_matrix =
    {
        {2, 3, 1, 5, 4, 6, 7},
        {1, 2, 3, 4, 5, 6, 7},
        {4, 1, 3, 2, 7, 5, 6},
        {6, 5, 4, 3, 2, 1, 7},
        {7, 6, 5, 4, 3, 2, 1},
        {3, 4, 2, 1, 6, 7, 5},
        {5, 7, 6, 1, 3, 2, 4}
    };

    // Identity matrix should always output 1 as the determinant so this is a good test
    std::vector<std::vector<int>> big_identity_matrix =
    {
        {1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1}
    };

    std::vector<std::vector<int>> huge_matrix =
    {
        {4, 1, 7, 3, 2, 5, 9, 8, 6, 2},
        {5, 9, 3, 7, 6, 2, 4, 1, 8, 7},
        {6, 2, 8, 1, 4, 3, 5, 9, 7, 4},
        {7, 3, 5, 2, 1, 6, 8, 4, 9, 5},
        {8, 4, 1, 6, 5, 7, 3, 2, 1, 6},
        {1, 5, 9, 4, 7, 8, 6, 3, 2, 1},
        {2, 6, 4, 9, 8, 1, 7, 5, 3, 8},
        {3, 7, 6, 8, 9, 4, 2, 6, 5, 3},
        {9, 8, 2, 5, 3, 9, 1, 7, 4, 9},
        {2, 9, 7, 1, 6, 5, 8, 3, 2, 7}
    };

    // Likewise, also a good test case
    std::vector<std::vector<int>> huge_identity_matrix =
    {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    // Test some calculations (and error handling) on our matrices!
    std::cout << "Determinant of non_square_matrix: ";
    try
    {
        std::cout << LinearAlgebra::determinant(non_square_matrix) << std::endl;
    }
    catch (std::invalid_argument)
    {
        std::cout << "We can't take the determinant of a non-square matrix... so we threw an exception" << std::endl;
    }

    std::cout << "Determinant of dead_matrix: ";
    try
    {
        std::cout << LinearAlgebra::determinant(dead_matrix) << std::endl;
    }
    catch (std::invalid_argument)
    {
        std::cout << "We passed an empty matrix... so we threw an exception" << std::endl;
    }

    std::cout << "Determinant of one_cell_matrix: " << LinearAlgebra::determinant(one_cell_matrix) << std::endl;
    std::cout << "Determinant of small_matrix: " << LinearAlgebra::determinant(small_matrix) << std::endl;
    std::cout << "Determinant of regular_matrix: " << LinearAlgebra::determinant(regular_matrix) << std::endl;
    std::cout << "Determinant of big_matrix: " << LinearAlgebra::determinant(big_matrix) << std::endl;
    std::cout << "Determinant of big_identity_matrix: " << LinearAlgebra::determinant(big_identity_matrix) << std::endl;

    // 10x10 takes a bit longer. If you scale up anymore, your computer might be cooked but that's your discretion
    std::cout << "Determinant of huge_matrix: " << LinearAlgebra::determinant(huge_matrix) << std::endl;
    std::cout << "Determinant of huge_identity_matrix: " << LinearAlgebra::determinant(huge_identity_matrix) << std::endl;

    return 0;
}