#include <iostream>
using namespace std;

/*
We intend to delete an element from an array.
say the array is: {[0] 462, [1] 5356, [2] 345}
number of elements: 3.
Say you want to del 5356. Doing so will leave a "gap" bw the elements. 
So now, we want the elements to move left (in insertion it was right because we wanted to make space)

We start the loop where @ the index we want deleted. 
We continue the loop till there is no element to move (i.e, till the end of the array)
We then move fwd. 
We then give the value of the next element to the prev element
We must also dec the num of elements.


*/
void del(int arr[], int &numOfElements, int pos){
    for(int i = pos; i < numOfElements -1; i++){
        arr[i] = arr[i+1]; 
    }

    numOfElements--;
}


int main()
{
    int arr[10] = {462, 5356, 345};
    int numOfElements = 3;
    int pos = 1; 
    
    for (int k=0; k<=numOfElements-1; k++ ){
        cout << arr[k] << '\t'; 
    }

    cout << '\n';

    del(arr, numOfElements,pos);

    for (int k=0; k<=numOfElements-1; k++ ){
        cout << arr[k] << '\t'; 
    }
    cout << endl; 

    return 0;
}
