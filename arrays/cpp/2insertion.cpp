// insert element 

#include <iostream>
using namespace std;

void insert(int arr[], int &n, int cap, int pos, int item){
    // check overflow

    if (n>cap){
        cout << "overflow";
    }

    // check valid pos

    if (pos < 0 || pos > n)
    {
        cout << "invaid pos"; 
    }

    // shiftig elements 

    for (int k =n; k > pos; k--){
        arr[k] = arr[k-1];


    }

    //insert element
    arr[pos] = item; cout << "\n";

    //inc size of array

    n++; 
}

int main()
{
    int arr[10] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cap = 10;
    int pos = 2; 
    int item; 
    cout << "Enter element to insert: "; cin >> item; 

    cout << "Elements before insertion: " << '\n';

    for (int i =0; i <= n-1; i++){
        cout << arr[i] << '\t';
    }

    insert(arr, n, cap, pos, item);
    cout << "After insertion: " << '\n';

    
    for (int i =0; i <= n-1; i++){
        cout << arr[i] << '\t';
    }
    

}