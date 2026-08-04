#include <iostream>

namespace Mat{
    template <typename T, T ROWS, T COLS>
    struct Matrix{
        T arr[ROWS][COLS]{}; 
    };

    template <typename T, T ROWS, T COLS>
    void linearSearch(const Matrix<T, ROWS, COLS> &m, int key){
        for (std::size_t i{0}; i<ROWS; ++i ){
            for (std::size_t j{0}; j<COLS; ++j){
                if (key == m.arr[i][j]){
                    std::cout << "Element found! Index: " << i << " x " <<  j  << '\n';
                    
                }
            }

            std::cout << '\n'; 
        }
    }
}


int main(){
    Mat::Matrix<int, 3,3> matrix{};
    matrix.arr[0][2] = 1;

    int key = 1;

    Mat::linearSearch(matrix, key);
    return 0; 
   
}