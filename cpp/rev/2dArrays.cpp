#include <iostream>

namespace Mat{
    template <typename T, std::size_t ROWS, std::size_t COLS>

    struct Matrix{
        T arr [ROWS][COLS]{};
    };

    template <typename T, std::size_t ROWS, std::size_t COLS>
    void disp(const Matrix <T, ROWS, COLS > &m){
        for (std::size_t i = 0; i < ROWS; ++i)
        {
            for (std::size_t j = 0; j < COLS; ++j)
            {
                std::cout << m.arr[i][j] << ' ';
            }

            std::cout << '\n';

        }
    }

}

int main()
{
    Mat::Matrix<int, 3, 3> matrix{};

    std::cout << "Matrix:\n";
    Mat::disp(matrix);

    return 0;
}