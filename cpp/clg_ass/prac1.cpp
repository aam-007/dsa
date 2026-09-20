/*
OPERATIONS ON ARRAY

1. Traversing an array
2. Inserting an element in an array
3. Searching an element in an array
4. Deleting an element from an array
5. Find highest and lowest element in an array.
6. Find the second largest element in an array.
*/

#include <iostream>
using namespace std;

const int SIZE = 10;

void trav(int arr[], int numOfElements);
void insert(int arr[], int &numOfElements, int capacity, int pos1, int item);
int search(int arr[], int numOfElements, int key);
void del(int arr[], int &numOfElements, int pos2);
void range(int arr[], int numOfElements);
int secondLargest(int arr[], int numOfElements);

int main()
{
    int arr[SIZE] = {2, 0, 6, 9, 5, 4, 8, 1};

    int numOfElements = 8;
    int capacity = SIZE;

    cout << "Original Array:\n";
    trav(arr, numOfElements);

    // INSERT
    int pos1;
    cout << "\nEnter position to insert element: ";
    cin >> pos1;

    int item;
    cout << "Enter element to insert: ";
    cin >> item;

    insert(arr, numOfElements, capacity, pos1, item);

    cout << "\nArray after insertion:\n";
    trav(arr, numOfElements);

    // DELETE
    int pos2;
    cout << "\nEnter position to delete element: ";
    cin >> pos2;

    del(arr, numOfElements, pos2);

    cout << "\nArray after deletion:\n";
    trav(arr, numOfElements);

    // SEARCH
    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    int index = search(arr, numOfElements, key);

    if (index == -1)
        cout << "Element not found.\n";
    else
        cout << "Element found at index " << index << endl;

    // RANGE
    cout << "\nHighest and Lowest Elements:\n";
    range(arr, numOfElements);

    // SECOND LARGEST
    cout << "\nSecond Largest Element: "
         << secondLargest(arr, numOfElements)
         << endl;

    return 0;
}

// 1. Traversing an array
void trav(int arr[], int numOfElements)
{
    cout << "[ ";

    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "]\n";
}

// 2. Inserting an element
void insert(int arr[], int &numOfElements, int capacity, int pos1, int item)
{
    if (numOfElements == capacity)
    {
        cout << "Array is full.\n";
        return;
    }

    if (pos1 < 0 || pos1 > numOfElements)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = numOfElements; i > pos1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos1] = item;
    numOfElements++;
}

// 3. Searching an element
int search(int arr[], int numOfElements, int key)
{
    for (int i = 0; i < numOfElements; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// 4. Deleting an element
void del(int arr[], int &numOfElements, int pos2)
{
    if (pos2 < 0 || pos2 >= numOfElements)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos2; i < numOfElements - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    numOfElements--;
}

// 5. Highest and Lowest element
void range(int arr[], int numOfElements)
{
    if (numOfElements == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < numOfElements; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    cout << "Lowest element : " << min << endl;
    cout << "Highest element: " << max << endl;
}

// 6. Second largest element
int secondLargest(int arr[], int numOfElements)
{
    if (numOfElements < 2)
    {
        return -1;
    }

    int largest = arr[0];
    int second = arr[0];

    for (int i = 1; i < numOfElements; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    return second;
}