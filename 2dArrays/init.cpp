#include <iostream>

namespace matrix {

    const int ROWS = 3;
    const int COLS = 4;

    struct initMtarix {
        int arr[ROWS][COLS];
    };

    void disp(const initMtarix &s) {
        std::cout << "2D Array:\n";

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                std::cout << s.arr[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
}

int main() {
    matrix::initMtarix m{}; 

    matrix::disp(m);

    return 0;
}