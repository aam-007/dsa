// travese an array

#include <iostream>
using namespace std;

void trav(int arr[], int lb, int ub){
    for(int k = lb; k<=ub; k++){
        cout << arr[k] << '\t';
    }

    cout << endl; 
}

int main(){
    int arr[] = {1, 2, 3 , 4};
    int lb =0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ub = n -1 ;

    trav(arr, lb, ub); 

    return 0; 


}