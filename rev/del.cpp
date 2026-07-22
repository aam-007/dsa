#include <iostream>
using namespace std; 

void del(int arr[], int &numOfElements, int pos){
    for (int k=pos; k<numOfElements;  k++){

        arr[k] = arr[k+1]; 

    }

    numOfElements--; 
}


int main()
{
    int arr[10] = {1, 2, 3, 4};
    int pos = 2;
    int numOfElements = 4;
   

    cout << "Old arr: " << '\n' ;
    for (int i=0; i<numOfElements; i++){
        cout << arr[i] << '\t';
        
    }
    cout << '\n';

    cout << "after del: ";
    del(arr, numOfElements, pos);
    for (int i=0; i<numOfElements; i++){
        cout << arr[i] << '\t';
        
    }
    cout << '\n';

    return 0; 
    
}