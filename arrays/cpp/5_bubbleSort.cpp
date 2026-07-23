#include <iostream>
using namespace std;

void bubbleSort(int arr[], int numOfElements); 
void disp(int arr[], int numOfElements);

int main()
{
    int arr[] = {6, 5, 9, 1, 3, 2, 7, 8, 18, 10};
    int numOfElements = sizeof(arr)/sizeof(arr[0]);

    cout << "before sorting: " << '\n';
    disp(arr, numOfElements);

    cout << "after sorting: " << '\n';
    bubbleSort(arr, numOfElements); 
    disp(arr, numOfElements);




    
}

void bubbleSort(int arr[], int numOfElements){

    for (int i=0; i<numOfElements-1; i++){
        for (int j =0; j<numOfElements-1-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 

            }
        }
    }

}

void disp(int arr[], int numOfElements){
    for (int k=0; k<numOfElements; k++){
        cout << arr[k] << '\t'; 
    }
}

