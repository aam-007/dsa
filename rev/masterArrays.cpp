/*
tasks: - disp, insert, del, linear search, bubble sort, binary search
*/
#include <iostream>
using namespace std;


void disp(int arr[], int numOfElements);
void insert(int arr[], int &numOfElements, int pos, int item);
void del(int arr[], int &numOfElements, int pos2);
void bubbleSort(int[], int numOfElements);
bool linearSearch(int arr[], int numOfElements, int key);
bool isSorted(int arr[], int numOfElements);
bool binSearch(int arr[], int numOfElements, int key2);

int main(){
    int arr[] = {7, 8, 5, 0, 3, 34, 35, 100, 99};
    int numOfElements = sizeof(arr)/sizeof(arr[0]);
    int key = 0; //for linear search
    int key2 = 67; // for binary search
    int pos = 3; // for insetion
    int pos2 = 4; // for deletion

    cout << "The array is: " << '\n';
    disp(arr, numOfElements);
    cout << '\n';

    if (isSorted(arr, numOfElements)){
        cout << "List is sorted already! " << '\n';
    }
    else {
        cout << "List not sorted. applying bubble sort" << '\n';
        bubbleSort(arr, numOfElements);
        cout << "List sorted! " << '\n'; cout << "Sorted list: " << '\n'; disp(arr, numOfElements);
    }

    if(linearSearch(arr, numOfElements, key)){
        cout << key << " exists! " << '\n';
    }

    else {
    cout << key << " does not exist!" << '\n' ;
    }
    
    if (binSearch(arr, numOfElements, key2)){
        cout << key2 << " Exists! " << '\n';
    }

    else{cout << key2 << " does not exist";}

    return 0; 
}

void disp(int arr[], int numOfElements){
    for(int k=0; k<numOfElements; k++){
        cout << arr[k] << '\t';
    }
}

void insert(int arr[], int &numOfElements, int pos, int item){
    for (int k=numOfElements; k>pos; k-- ){
        arr[k] = arr[k-1];
    }

    numOfElements++; 
}

void del(int arr[], int &numOfElements, int pos2){
    for (int k=pos2; k<numOfElements; k++){
        arr[k] = arr[k+1];
    }
    numOfElements--;
}

void bubbleSort(int arr[], int numOfElements){
    for(int k=0; k<numOfElements-1; k++){
        for(int j=0; j<numOfElements-1-k; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 

            }
        }
    }
}

bool isSorted(int arr[], int numOfElements){
    for (int i=0; i < numOfElements-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }

    return true; 
}

bool linearSearch(int arr[], int numOfElements, int key){
    for(int k=0; k<numOfElements; k++){
        if (arr[k]==key){
            return true;
        }
    }

    return false; 
}

bool binSearch(int arr[], int numOfElements, int key2){
    int low =0;
    int high=numOfElements-1;

    for(int k=0; k<numOfElements; k++){
        int mid = (high+low)/2;
        if(key2 == arr[mid]){
            return true;
        }
        else if (key2 < arr[mid] ){
            high = mid-1;
        }

        else {
            low = mid+1;
        }
    }

    return false;
}