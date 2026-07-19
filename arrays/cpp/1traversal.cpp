// travese an arr

#include <iostream>
using namespace std;

void trav(int arr[], int lb, int ub)
{
    for (int k = lb; k<=ub; k++){
        cout << arr[k] << '\t';
    }
}

int main()
{
    int arr [] = {1, 2, 8, 9};
    int lb = 0;
    int len = sizeof(arr)/sizeof(arr[0]);

    int ub = len - 1;

    trav(arr, lb, ub); 

    return 0; 

}