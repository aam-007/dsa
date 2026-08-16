#include <iostream>

constexpr std::size_t MAX{ 10 }; 

void display(const std::size_t arr[], std::size_t &numberOfElements) {
	for (auto k{ 0 }; k < numberOfElements; ++k) {
		std::cout << arr[k] << ' ';
	}
	std::cout << '\n'; 
}

void insert(std::size_t arr[], std::size_t& numOfElements, std::size_t pos1, const auto item) {
	for (auto k{ numOfElements }; k > pos1; --k) {
		arr[k] = arr[k - 1];
	}

	arr[pos1] = item;
	++numOfElements; 
}

void deletion(std::size_t arr[], std::size_t& numOfElements, std::size_t pos2) {
	for (auto k{ pos2 }; k < numOfElements-1; ++k) {
		arr[k] = arr[k + 1]; 
	}
	--numOfElements; 
}

bool linearSearch(const std::size_t arr[], const std::size_t& numOfElements, auto key) {
	for (auto k{ 0 }; k < numOfElements; ++k) {
		if (arr[k] == key) {
			std::cout << "Element " << key << " found @ position " << k+1 << " and index " << k << '\n';
			return true; 
		}
	}

	return false; 
}

void bubbleSort(std::size_t arr[], const std::size_t& numOfElements) {
	for (auto k{ 0 }; k < numOfElements; ++k) {
		for (auto j{ 0 }; j < numOfElements - 1 - k; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]); 
			}
		}
	}
	std::cout << '\n'; 
}

bool binarySearch(const std::size_t arr[], const std::size_t& numOfElements, auto key2) {
	int low{ 0 };
	int high = static_cast<int>(numOfElements - 1) ; 

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] > key2) {
			high = mid - 1; 
		}
		else if (arr[mid] == key2) {
			std::cout << "element found!"; 
			return true; 
		}
		else {
			low = mid + 1; 
		}
	}

	std::cout << "not found!" << '\n'; 
	return false; 
}

int main() {
	std::cout << "test" << '\n';
	std::size_t arr[MAX] = { 2, 8, 19, 56 };
	std::size_t numOfElements{ 4 };

	// for insert():
	std::size_t pos1{ 2 }; // pos @ which insertion is to occur
	auto item{ 67 }; // item to insert 

	//for deletion():
	std::size_t pos2{ 0 }; // pos @ which deletion is to occur

	//for linearSearch()
	auto key{ 67 }; 

	//for binarySearch()
	auto key2{ 56 }; 

	display(arr, numOfElements); 

	insert(arr, numOfElements, pos1, item); std::cout << '\n'; 
	display(arr, numOfElements);

	deletion(arr, numOfElements, pos2); std::cout << '\n'; 
	display(arr, numOfElements);

	linearSearch(arr, numOfElements, key); std::cout << '\n'; 

	bubbleSort(arr, numOfElements);
	display(arr, numOfElements);

	binarySearch(arr, numOfElements, key2); 

	return 0; 
}