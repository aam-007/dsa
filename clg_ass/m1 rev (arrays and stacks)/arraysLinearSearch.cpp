#include <iostream>
#include <cstddef>

constexpr std::size_t MAX{ 10 }; 

void traversal(const std::size_t arr[], const std::size_t numOfElements) {
/*
* Algo for traversal
* STEP 1: START
STEP 2: SET K = 0
STEP 3: REPEAT STEPS 4 AND 5 WHILE K < numOfElements
STEP 4: DISPLAY arr[K]
STEP 5: INCREMENT K BY 1
STEP 6: END
*/
	std::cout << "[ "; 
	for (auto k{ 0 }; k < numOfElements; ++k) {
		std::cout << arr[k] << " ";
	}
	std::cout << " ]" << '\n';
}

bool linearSearch(const std::size_t arr[], const std::size_t numOfElements, const auto toSearch) {

	/*
	* ALGO FOR LINEAR SEARCH
	*STEP 1: START
STEP 2: SET K = 0
STEP 3: REPEAT STEPS 4 AND 5 WHILE K < numOfElements
STEP 4: IF arr[K] = toSearch, RETURN TRUE
STEP 5: INCREMENT K BY 1
STEP 6: RETURN FALSE
STEP 7: END
	*/
	for (auto k{ 0 }; k < numOfElements; ++k) {
		if (arr[k] == toSearch) {
			std::cout << "Element " << toSearch << " found @index " << k << '\n'; 
			return true; 
		}
	}

	std::cout << "element not found!" << '\n';
	return false; 
}

int main() {
	std::size_t arr[MAX] = { 2, 8, 1, 6, 45, 767 }; 
	std::size_t numOfElements{ 6 }; 
	auto toSearch{ 45 }; 

	traversal(arr, numOfElements); 
	linearSearch(arr, numOfElements, toSearch); 


	return 0; 
}