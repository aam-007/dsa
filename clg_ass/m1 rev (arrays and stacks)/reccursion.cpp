#include <iostream>

/*
Algorithm: Recursive Factorial

STEP 1: START

STEP 2: INPUT NUM

STEP 3: IF NUM = 0 OR NUM = 1, THEN RETURN 1

STEP 4: OTHERWISE, RETURN NUM × FACTORIAL(NUM - 1)

STEP 5: END
*/

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