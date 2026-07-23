#include <iostream>
using namespace std;

bool biSearch(int arr[],int n, int key);
void buSort(int arr[], int n);
void disp(int arr[], int n);
bool isSorted(int arr[], int n); 

int main(){
    int arr[] = {2, 1, 9, 0, 7, 56, 45, 90, 24, 467, 178, 5432244, 5687};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 0; 

    cout << "arr: " << '\n';
    disp(arr, n); cout << '\n';

    if(isSorted(arr, n)){
        cout << "Array already sorted – Skipping Bubble sort!" << '\n';
        if (biSearch(arr, n, key)){
            cout << "Exists!" << '\n'; 
        }

        else{
            cout << "not present " << '\n'; 
        }
    
    }

    else{
        cout << "arr unsorted! applying bubble sort!" << '\n';
        buSort(arr,n);

        cout << "Sorted arr: " << '\n';
        disp(arr, n); cout << '\n';

        cout << "Does Element exist? " << '\n';

        if (biSearch(arr, n, key)){
            cout << "Yes!" << '\n';
        }

        else{
            cout << "no :( " << '\n'; 
        }
    }

    return 0;
}

void disp(int arr[], int n){
    for (int k=0; k<n; k++ ){
        cout << arr[k] << '\t'; 
    }

    cout << '\n'; 
}

/*
bool biSearch(int arr[],int n, int key);
void buSort(int arr[], int n); ----- next 
void disp(int arr[], int n); ----- Done 
bool isSorted(int arr[], int n); 
*/

void buSort(int arr[], int n){
    for (int i =0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

/*
bool biSearch(int arr[],int n, int key);
void buSort(int arr[], int n); ----- done
bool isSorted(int arr[], int n); ---- next 
*/

bool isSorted(int arr[], int n){
    for(int i=0; i<n-1; i++){
        if (arr[i] > arr[i+1]){
            return false; 
        }
    }

    return true; 
}

/*
bool biSearch(int arr[],int n, int key); ---- next
bool isSorted(int arr[], int n); ---- done 
*/

bool biSearch(int arr[],int n, int key){
    int low =0;
    int high =n-1;

    while (low<=high){
        int mid = (low+high)/2;

        if (arr[mid] ==key){
            return true; 

        }

        else if (key < arr[mid]){
            high = mid -1; 
        }

        else{
            low = mid+1; 
        }
    }

    return false; 
}
/*
bool biSearch(int arr[],int n, int key); ---- done 
*/