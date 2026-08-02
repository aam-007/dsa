#include "array.h"
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {5, 12, 8, 21, 3, 17};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Array: ";
    printArray(numbers, size);

    cout << "Sum: " << sumArray(numbers, size) << endl;
    cout << "Max: " << maxArray(numbers, size) << endl;

    return 0;
}
