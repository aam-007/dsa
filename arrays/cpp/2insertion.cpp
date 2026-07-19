#include <iostream>
using namespace std;

/*
We intend to insert an element in an array. 
say the array is: {[0] 462, [1] 5356, [2] 345}
number of elements: 3
say you intend to insert it at position [1].
To do this you will need to shift the elements to the right. 
The issue is, if you move right, the next element is deleted.
To prevent this, we start at the postion after the last element, and work our way backwards.
We run the loop until we reach the position we want to insert the elememt. 
then, we insert the element, increase the number of elements, and done!
*/
void insert(int arr[], int &numOfElements, int pos, int item){
    for(int k = numOfElements; k > pos; k--){
        arr[k] = arr[k-1]; 
    }

    numOfElements++;
}


int main()
{
    int arr[10] = {462, 5356, 345};
    int numOfElements = 3;
    int pos = 1; 
    int item = 78; 
    
    for (int k=0; k<=numOfElements-1; k++ ){
        cout << arr[k] << '\t'; 
    }

    cout << '\n';

    insert(arr, numOfElements,pos, item);

    for (int k=0; k<=numOfElements-1; k++ ){
        cout << arr[k] << '\t'; 
    }
    cout << endl; 

    return 0;
}