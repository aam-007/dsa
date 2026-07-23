#include <iostream>
using namespace std;

void bSort(int arr[], int numOfElements); 
bool bSearch(int arr[], int numOfElements, int key);
void disp(int arr[], int numOfElements);

int main(){
    int arr[] = {67, 90, 64, 0, 45, 89, 65, 78};
    int numOfElements =sizeof(arr)/sizeof(arr[0]); 
    int key = 0; 

    cout << "array is: " << '\n';
    disp(arr, numOfElements); cout << '\n'; 

    cout << "sorted array is: " << '\n';
    bSort(arr, numOfElements);
    disp(arr, numOfElements); cout << '\n'; 

    if(bSearch(arr, numOfElements,key)){
        cout << "Exists! ";
    }

    else{
        cout << "does not exist!"; 
    }


    return 0; 

}

void disp(int arr[], int numOfElements){
    for (int k=0; k<numOfElements; k++){
        cout << arr[k] << '\t'; 
    }
}

void bSort(int arr[], int numOfElements){
    for (int i=0; i<numOfElements-1; i++){
        for(int j=0; j<numOfElements-1-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
} 


bool bSearch(int arr[], int numOfElements, int key){
    int low =0;
    int high = numOfElements-1;

    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid] == key){
            return true; 
        }

        else if(key < arr[mid]){
            high = mid-1; 
        }

        else{
            low = mid+1; 
        }
    }

    return false;
}