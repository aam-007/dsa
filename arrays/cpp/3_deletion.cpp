#include <iostream>
using namespace std;

void deleteElement(int arr[], int &numOfElements, int position)
{
    // Check position validity
    if (position < 0 || position >= numOfElements)
    {
        cout << "Invalid position!\n";
        return;
    }

    // Shift elements to the left
    for (int i = position; i < numOfElements - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    // Decrease the number of elements
    numOfElements--;
}

int main()
{
    int arr[10] = {1, 2, 3, 4};
    int numOfElements = 4;
    int position;

    cout << "Enter position to delete: ";
    cin >> position;

    cout << "Before deletion:\n";
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << "\t";
    }

    deleteElement(arr, numOfElements, position);

    cout << "\nAfter deletion:\n";
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;

    return 0;
}