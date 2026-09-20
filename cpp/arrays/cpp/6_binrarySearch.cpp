/*
unsorted array --> bubble sort ---> sorted array ---> binary search
three funcs: buSort, biSearch, disp
*/

#include <iostream>
using namespace std; 

void buSort(int arr[], int numOfelements);
bool biSearch(int arr[], int numOfelements, int key);
void disp(int arr[], int numOfelements);

int main()
{
    int arr[] = {1, 8, 6, 0, 5, 89, 0, 76};
    int numOfelements = sizeof(arr)/sizeof(arr[0]);
    int key = 200; 

    cout << "array is: " << '\n';
    disp(arr, numOfelements); cout << '\n'; 

    cout << "sorted array is: " << '\n';
    buSort(arr, numOfelements); 
    disp(arr, numOfelements); cout << '\n'; 

    cout << "Search: \n";

    if(biSearch(arr, numOfelements, key)){
        cout << "Exists!" << '\n'; 
    }

    else{
        cout << "does not exist" << '\n'; 
    }

    return 0; 
    
}

void disp(int arr[], int numOfelements){
    for (int k=0; k<numOfelements; k++){
        cout << arr[k] << '\t'; 
    }
}

void buSort(int arr[], int numOfelements){
    for (int i = 0 ; i<numOfelements-1; i++){
        for(int j = 0; j < numOfelements-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

bool biSearch(int arr[], int numOfelements, int key){
    int low=0;
    int high = numOfelements -1;

    while(low<=high){
        int mid = (high+low)/2;

        if(arr[mid] == key){
            return true; 
        }

        else if (key < arr[mid]){
            high = mid-1; 
        }

        else{
            low = mid+1; 
        }
    }

    return false; 
}