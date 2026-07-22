#include <iostream>
using namespace std; 

void insert(int arr[], int &numOfElements, int pos, int item){
    for(int k = numOfElements; k > pos; k--){
        arr[k] = arr[k-1];
    }

    arr[pos] = item; 

    numOfElements++; 
}

int main()
{
    int arr[10] = {1, 2, 3, 4};
    int pos = 2;
    int numOfElements = 4;
    int item = 69; 
    int ub= 3; 

    cout << "Old arr: " << '\n' ;
    for (int i=0; i<numOfElements; i++){
        cout << arr[i] << '\t';
        
    }
    cout << '\n';

    cout << "after insertion: ";
    insert(arr, numOfElements, pos, item);
    for (int i=0; i<numOfElements; i++){
        cout << arr[i] << '\t';
        
    }
    cout << '\n';

    return 0; 
    
}