#include <iostream>
using namespace std;

void insert(int arr[], int &numOfEelements, int capacity, int position, int item)
{
    // Check overflow
    if (numOfEelements == capacity)
    {
        cout << "Overflow!\n";
        return;
    }

    // Check position validity
    if (position < 0 || position > numOfEelements)
    {
        cout << "Invalid position!\n";
        return;
    }

    // Shift elements to the right
    for (int k = numOfEelements; k > position; k--)
    {
        arr[k] = arr[k - 1];
    }

    // Insert item
    arr[position] = item;

    numOfEelements++;
}

int main()
{
    int arr[10] = {1, 2, 3, 4};
    int numOfEelements = 4;   // Number of elements currently present
    int capacity = 10;
    int position;
    int item = 7;

    cout << "Enter position to insert: ";
    cin >> position;

    cout << "Before insertion:\n";
    for (int k = 0; k < numOfEelements; k++)
    {
        cout << arr[k] << "\t";
    }

    insert(arr, numOfEelements, capacity, position, item);

    cout << "\nAfter insertion:\n";
    for (int k = 0; k < numOfEelements; k++)
    {
        cout << arr[k] << "\t";
    }

    cout << endl;

    return 0;
}