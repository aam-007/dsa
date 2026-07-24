/*
array ops: display, insert, delete, bubble sort, linear search, binary search
*/

#include <iostream>
using namespace std; 

// functions used: 
void disp(int arr[],  int numOfElements); // ---------------- done 
void insert(int arr[],  int &numOfElements, int pos1, int item);  // ---------------- done 
void del(int arr[],  int &numOfElements, int pos2);//   ------- done 
void bubbleSort(int arr[],  int numOfElements); // ----- done 
bool linearSearch(int arr[],  int numOfElements, int key1);//  ---- done 
bool binarySearch(int arr[],  int numOfElements, int key2);//  ---- done 
bool isSorted(int arr[], int numOfElements); // --- done   

int main(){
    int arr[12] = {6, 9, 2, 0, 8, 46, 87, 100, 900, 122};
    int numOfElements = sizeof(arr)/sizeof(arr[0]); 
    int pos1 = 2; //insertion
    int pos2 = 0; // deletion
    int key1 = 67; //linear search
    int key2 = 0; // binary search
    int item = 90; //insertion 

    //disp array
    cout << "array is: " << '\n';
    disp(arr, numOfElements); cout << '\n'; 

    cout << endl; 

    // insert element
    cout << "after inserting "<< item << " in array " << '\n';
    insert(arr, numOfElements, pos1, item);
    disp(arr, numOfElements); cout << '\n'; 

    cout << endl; 

    //delete element 
    cout << "after deleting item at position: "<< pos2 << " in array " << '\n';
    del(arr, numOfElements, pos2); 
    disp(arr, numOfElements); cout << '\n'; 

    cout << endl; 


    // check sorted, if not sort
    cout << "checking if arr is sorted! "<< '\n'; 
    if (isSorted(arr, numOfElements)){
        cout << "already sorted! skippig bubble sort" << '\n';
    }
    else{
        cout << "not sorted. applying bubble sort " << '\n'; 
        bubbleSort(arr, numOfElements);
        cout << "after sorting: " << '\n'; 
        disp(arr, numOfElements); cout << '\n'; 
    }

    cout << endl; 

    // linear search
    cout << "Searching for  " << key1 << "  in arr" << '\n'; 
    if (linearSearch(arr, numOfElements, key1)){
        cout << "exists! " << '\n'; 
    }
    else{
        cout << "does not exist in arr " << '\n';
    }

    cout << endl; 

    // binary search 
    cout << "Searching for  " << key2 << "  in arr" << '\n'; 
    if (binarySearch(arr, numOfElements, key2)){
        cout << "exists! " << '\n'; 
    }
    else{
        cout << "does not exist in arr " << '\n';
    }

    cout << endl; 

    return 0; 


}


void disp(int arr[],  int numOfElements){
    for (int k=0; k<numOfElements; k++){
        cout << arr[k] << '\t';
    }
}

void insert(int arr[],  int &numOfElements, int pos1, int item){
    for (int k = numOfElements; k>pos1; k--){
        arr[k] = arr[k-1]; 
    }
    arr[pos1] = item; 
    numOfElements ++; 
}


void del(int arr[],  int &numOfElements, int pos2){
    for (int k=pos2; k<numOfElements-1; k++){
        arr[k] = arr[k+1];
    }
    numOfElements--; 
}

void bubbleSort(int arr[],  int numOfElements){
    for (int k=0; k<numOfElements-1; k++){
        for (int j=0; j<numOfElements-1-k; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}


bool linearSearch(int arr[],  int numOfElements, int key1){
    for (int k=0; k<numOfElements; k++){
        if (arr[k] == key1){
            return true; 
        }
    }

    return false; 
}
bool binarySearch(int arr[],  int numOfElements, int key2){
    int low =0;
    int high = numOfElements-1;

    while (low<=high){
       int mid = (low+high)/2;

       if (key2 == arr[mid]){
            return true; 
       }
       else if (key2 < arr[mid]){
        high = mid-1; 
       }
       else{
        low = mid+1; 
       }
    }

    return false; 
}


bool isSorted(int arr[], int numOfElements){
    for (int k=0; k<numOfElements-1; k++){
        if (arr[k] > arr[k+1]){
            return false; 
        }
    }
    return true; 
}

