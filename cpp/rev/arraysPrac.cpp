/*
Array Operations
- Display
- Insert
- Delete
- Bubble Sort
- Linear Search
- Binary Search

Author: aditya.mishra10@nmims.in
*/

#include <iostream>
using namespace std;

// Function Prototypes
void disp(int arr[], int numOfElements);
void insert(int arr[], int &numOfElements, int pos, int item);
void del(int arr[], int &numOfElements, int pos);
void buSort(int arr[], int numOfElements);
int LSearch(int arr[], int numOfElements, int key);
int biSearch(int arr[], int numOfElements, int key);
bool isSorted(int arr[], int numOfElements);

int main()
{
    cout << "Full Array Operations\n\n";

    // Initial array
    int arr[12] = {2, 0, 45, 96, 34, 90, 46, 23, 89, 45};
    int numOfElements = 10;

    int item = 67;
    int insertPos = 4;
    int deletePos = 7;

    int linearKey = 69;
    int binaryKey = 45;

    // Display array
    cout << "Original Array:\n";
    disp(arr, numOfElements);
    cout << "\n\n";

    // Sort if required
    if (!isSorted(arr, numOfElements))
    {
        cout << "Array not sorted. Applying Bubble Sort...\n";
        buSort(arr, numOfElements);

        cout << "Sorted Array:\n";
        disp(arr, numOfElements);
        cout << "\n\n";
    }
    else
    {
        cout << "Array already sorted.\n\n";
    }

    // Insert element
    cout << "Inserting " << item << " at index " << insertPos << '\n';
    insert(arr, numOfElements, insertPos, item);

    // Keep array sorted
    buSort(arr, numOfElements);

    disp(arr, numOfElements);
    cout << "\n\n";

    // Delete element
    cout << "Deleting element at index " << deletePos << '\n';
    del(arr, numOfElements, deletePos);

    // Keep array sorted
    buSort(arr, numOfElements);

    disp(arr, numOfElements);
    cout << "\n\n";

    // Linear Search
    int index = LSearch(arr, numOfElements, linearKey);

    if (index == -1)
        cout << linearKey << " not found.\n";
    else
        cout << linearKey << " found at index " << index << '\n';

    // Binary Search
    index = biSearch(arr, numOfElements, binaryKey);

    if (index == -1)
        cout << binaryKey << " not found.\n";
    else
        cout << binaryKey << " found at index " << index << '\n';

    return 0;
}

// Display array
void disp(int arr[], int numOfElements)
{
    cout << "[ ";

    for (int i = 0; i < numOfElements; i++)
        cout << arr[i] << " ";

    cout << "]";
}

// Insert element
void insert(int arr[], int &numOfElements, int pos, int item)
{
    for (int i = numOfElements; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = item;
    numOfElements++;
}

// Delete element
void del(int arr[], int &numOfElements, int pos)
{
    for (int i = pos; i < numOfElements - 1; i++)
        arr[i] = arr[i + 1];

    numOfElements--;
}

// Bubble Sort
void buSort(int arr[], int numOfElements)
{
    for (int i = 0; i < numOfElements - 1; i++)
    {
        for (int j = 0; j < numOfElements - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Linear Search
int LSearch(int arr[], int numOfElements, int key)
{
    for (int i = 0; i < numOfElements; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int biSearch(int arr[], int numOfElements, int key)
{
    int low = 0;
    int high = numOfElements - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// Check if sorted
bool isSorted(int arr[], int numOfElements)
{
    for (int i = 0; i < numOfElements - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}