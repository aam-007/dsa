/*
* All array ops:
* 1. traversal
* 2. insertion
* 3. deletion
* 4. linear search
* 5. bubble sort
* 6. binary search
*/

#include <iostream>
#include <cstddef>

namespace lds {
	void traversal(const std::size_t arr[], const std::size_t lb, const std::size_t ub) {
		for (std::size_t k{ 0 }; k < ub; ++k) {
			std::cout << arr[k] << ' ';
		}
		std::cout << '\n'; 
	}

	void insertion(std::size_t arr[], std::size_t &ub, int item, std::size_t pos1) {
		for (int k = ub; k > pos1; --k) {
			arr[k] = arr[k - 1];
		}
		arr[pos1] = item; 
		++ub; 
	}

	void deletion(std::size_t arr[], std::size_t& ub, std::size_t pos2) {
		for (std::size_t k = pos2; k < ub-1; ++k) {
			arr[k] = arr[k + 1];
		}

		--ub; 
	}

	bool linearSearch(const std::size_t arr[], const std::size_t& ub, int key) {
		for (int k{ 0 }; k < ub; k++) {
			if (arr[k] == key) {
				return true;
			}
		}

		return false; 
	}

}

int main() {
	std::cout << "array ops" << '\n';
	std::size_t arr[] = { 2, 7, 9, 10, 6 };
	std::size_t lb{ 0 };
	std::size_t ub = sizeof(arr) / sizeof(arr[0]);
	int item{ 67 };
	std::size_t pos1{ 4 }; 
	std::size_t pos2{ 2 }; 
	int key{ 10 };
	
	
	lds::traversal(arr, lb, ub); 
	lds::insertion(arr, ub, item, pos1);
	lds::traversal(arr, lb, ub); 
	lds::deletion(arr, ub, pos2);
	lds::traversal(arr, lb, ub); 

	if (lds::linearSearch(arr, ub, key)) {
		std::cout << key << " is present!" << '\n';
	}

	else {
		std::cout << key <<" not present"; 
	}

	return 0; 
}