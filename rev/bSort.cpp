// bubble sort

#include <iostream>
using namespace std; 

void bSearch(int arr[], int numOfElements);
void disp(int arr[], int numOfElements);

int main(){
    int arr[] = {1, 0, 8, 5, 9, 44, 2333334, 5376735, 5357, 1351, 2456, 9875}; 
    int numOfElements = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted: " << '\n';
    disp(arr, numOfElements); cout << '\n';

    cout << "Sorted: " << '\n';
    bSearch(arr, numOfElements);
    disp(arr, numOfElements); cout << '\n';



    
}

void disp(int arr[], int numOfElements){
    for (int k=0; k<numOfElements; k++){
        cout << arr[k] << '\t'; 
    }
}

void bSearch(int arr[], int numOfElements){
    for (int i=0; i<numOfElements-1; i++){
        for (int j=0; j<numOfElements-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}