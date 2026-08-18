#include <iostream>
#include <cstddef>
#include <utility>

constexpr std::size_t MAX {10};

/*
Algorithm: traversal of a 1D array
STEP 1: START
STEP 2: SET K = 0
STEP 3: REPEAT STEPS 4 AND 5 WHILE K<NUMOFELEMENTS
STEP 4: DISPLAY ARR[K]
STEP 5: INCREMENT K BY 1 (i.e., ++k)
STEP 6: END 
*/
void traverse(const std::size_t arr[], const std::size_t &numOfElements ){
    for (auto k{0}; k<numOfElements; ++k){
        std::cout << arr[k] << " ";
    }
    std::cout << '\n';
}

/*
Algorithm: Insertion in a 1D Array
STEP 1: START
STEP 2: SET K = NUMOFELEMENTS
STEP 3: REPEAT STEPS  4 AND 5 WHILE K > posToInsertAt-1
    STEP 4: SET ARR[K] = ARR[K-1]
    STEP 5: DECREMNENT K BY ONE, i.e, --k
STEP 6: SET ARR[posToInsertAt] = itemToInsert
STEP 7: INCREMENT numOfElements by 1, i.e, ++numOfElements
STEP 8: END

*/
void insert(std::size_t arr[], std::size_t &numOfElements, const int itemToInsert, const std::size_t posToInsertAt){
    for (auto k {numOfElements}; k>posToInsertAt; --k){
        arr[k] = arr[k-1];
    }
    arr[posToInsertAt] = itemToInsert;
    ++numOfElements; 
    traverse(arr, numOfElements); 
}

/*
Algorithm name: Deletion of element
STEP 1: START
STEP 2: SET K = posToDeleteAt
STEP 3: REPEAT STEPS 4 AND 5  WHILE K<numOfElements
STEP 4: SET ARR[k] = ARR[K+1]
STEP 5: INCREMEMNT K BY 1, i.e, ++k
STEP 6: DECREMEMNT NUMOFELEMENTS BY 1, i.e, --numOfElements
STEP 7: END 
*/
void deleteion(std::size_t arr[], std::size_t &numOfElements, const std::size_t posToDeleteAt){
    for (auto k {posToDeleteAt}; k<numOfElements-1; ++k){
        arr[k] = arr[k+1];
    }
    --numOfElements; 
    traverse(arr, numOfElements); 
}

void bubbleSort(std::size_t arr[], std::size_t numOfElements){
    for (auto k{0}; k<numOfElements-1; ++k){
        for (auto j{0}; j<numOfElements-1-k; ++j){
            if (arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]); 
            }
        }
    }
    traverse(arr, numOfElements); 
}

int main(){
    std::size_t arr [MAX] = {2, 8, 3, 9,0, 4, 1};
    std::size_t numOfElements {7};
    auto itemToInsert {20};
    std::size_t posToInsertAt {3};
    std::size_t posToDeleteAt {4};

    traverse(arr, numOfElements); 
    insert(arr, numOfElements, itemToInsert, posToInsertAt); 
    deleteion(arr, numOfElements, posToDeleteAt); 
    bubbleSort(arr, numOfElements); 

    return 0;
}