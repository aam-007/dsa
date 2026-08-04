#include <iostream>

namespace Mat{
    const int ROWS = 3;
    const int COLS = 3;

    struct Matrix{
        int arr[ROWS][COLS];
    };

    void disp(const Matrix &m){
        std :: cout << "Zero initialized matrix: " << '\n';
        for (int i=0; i<ROWS; ++i){
            for (int k=0; k<COLS; ++k){
                std :: cout << m.arr[i][k] << " ";
            }
            std :: cout << "\n" ;
        }
    }

}

int main(){
    Mat :: Matrix m{}; 
    Mat :: disp(m); 

    return 0; 
}