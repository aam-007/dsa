#include <iostream>
#include <cstddef>

void traversal(const std::size_t arr[], std::size_t lb, std::size_t ub) {
    for (std::size_t k{lb}; k < ub; ++k) {
        std::cout << arr[k] << ' ';
    }
    std::cout << '\n';
}

bool isEmpty(std::size_t ub, std::size_t lb) {
    return ub <= lb;
}

int main() {
    std::size_t arr[] = {2, 8, 9, 10};

    std::size_t lb{0};
    std::size_t ub = sizeof(arr) / sizeof(arr[0]);

    traversal(arr, lb, ub);

    if (isEmpty(ub, lb)) {
        std::cout << "empty";
    } else {
        std::cout << "not empty";
    }

    return 0;
}
