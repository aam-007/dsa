#include <iostream>

namespace Mat{
    constexpr int ROWS = 3;
    constexpr int COLS = 3;

    struct Matrix{
        int arr[ROWS][COLS] {};
    };

    void disp(const Matrix &m){
        for (int i=0; i<ROWS; ++i){
            for (int k=0; k<COLS; ++k){
                std :: cout << m.arr[i][k] << " ";
            }
            std :: cout << '\n' ;
        }
    }

}

int main(){
    Mat :: Matrix matrix {}; 
    std :: cout << "Zero initialized matrix: " << '\n';
    Mat :: disp(matrix); 

    return 0; 
}