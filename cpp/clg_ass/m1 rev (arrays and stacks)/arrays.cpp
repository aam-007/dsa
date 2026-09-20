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

	void bubbleSort(std::size_t arr[], std::size_t ub) {
		for (std::size_t k{ 0 }; k < ub - 1; ++k) {
			for (std::size_t j{ 0 }; j < ub - 1 - k; ++j) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]); 
				}
			}
		}
	}

	bool binarySearch(const std::size_t arr[], std::size_t ub, int key2) {
		int low = 0;
		int high = ub-1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] == key2) {
				return true; 
			}

			else if (arr[mid] > key2) {
				high = mid - 1; 
			}

			else {
				low = mid + 1; 
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
	int key2{ 9 }; 
	
	
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

	lds::bubbleSort(arr, ub);
	lds::traversal(arr, lb, ub); std::cout << '\n'; 

	if (lds::binarySearch(arr, ub, key2)) {
		std::cout << "found!" << '\n';
	}
	else {
		std::cout << "not found" << '\n';
	}
	

	return 0; 
}