#include <iostream>

int factorial(int num) {
	if (num == 1 || num == 0) {
		return 1;  //base case
	}

	return num * factorial(num-1); 
}

int main() {
	int num{ 6 }; 
	std::cout << factorial(num) << '\n';
	return 0; 
}