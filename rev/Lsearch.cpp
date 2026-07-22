#include <iostream>
using namespace std;

bool Lsearch(int arr[], int numOfElements, int key){

    for(int k = 0; k<numOfElements ; k++){
        if (arr[k] == key){
            return true; 
        }
    }

    return false; 

}

int main()
{
    int arr[10] = {1, 2, 3, 4};
    int key = 2;
    int numOfElements = 4;
    
    if (Lsearch){
        cout << "Exists! ";
    }

    else{
        cout << "Does not :( "; 
    }

    return 0; 

}