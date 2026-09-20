#include <iostream>
using namespace std;

bool find(int arr[], int n, int key){
    for(int k=0; k<n; k++){
        if (arr[k] == key){
            return true;
        }

    }

    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int key = 5;
    if (find(arr, n, key)){
        cout << "Exists!" << '\n';
    }

    else{
        cout << "Does not exist!" << '\n'; 
    }

    return 0;
}