#include <iostream>
using namespace std;

void trav(int arr[], int lb, int ub){
    for (int k=lb; k<=ub; k++){
        cout << arr[k] << '\t'; 
    }
}

int main()
{
    int arr[] = {1, 2, 3}; 
    int lb = 0;
    int ub = 2;
    trav(arr, lb, ub); 
}