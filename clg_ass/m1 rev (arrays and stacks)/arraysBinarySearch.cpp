#include <iostream>
#include <cstddef>

constexpr std::size_t MAX{ 10 }; 

/*
* ALGORITHM: BINARY SEARCH
* STEP 1: SET LOW = 0 AND SET HIGH = numOfElements - 1;
* STEP 2: REPEAT STEPS 3 TO 6  WHILE LOW<=HIGH
* STEP 3: SET MID = (LOW+HIGH)/2 
* STEP 4: IF ARR[MID] == KEY GOTO STEP 7
* STEP 5: ELSE IF ARR[MID] > KEY SET HIGH = MID - 1 AND GOTO STEP 2
* STEP 6: ELSE SET LOW = MID + 1 AND GOTO STEP 2
* STEP 7: RETURN TRUE
* STEP 8: RETURN FALSE
* STEP 9: END 
*/

bool binarySearch(const std::size_t arr[], const std::size_t numOfElements, auto key) {
	int low{ 0 };
	int high = static_cast<int>(numOfElements - 1); 

	while (low <= high) {
		int mid = (low + high) / 2; 

		if (arr[mid] == key) {
			std::cout << "element found! \n";
			return true; 
		}
		else if (arr[mid] > key) {
			high = mid - 1; 
		}
		else {
			low = mid + 1; 
		}
	}
	std::cout << "not found" << '\n';
	return false; 
}

int main() {
	std::size_t arr[MAX] = { 2, 4, 6, 8, 10 }; // already sorted 
	std::size_t numOfElements{ 5 }; 
	auto key{ 4 }; 

	binarySearch(arr, numOfElements, key); 

	return 0; 
}