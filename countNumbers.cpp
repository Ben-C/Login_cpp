#include <iostream>
#include <fstream>
#include <string>


int countNumbers() {
	int userNum;
	std::cout << "Please enter in a number: " << std::endl;
	std::cin >> userNum;

	int i = 0;
	while(i < userNum){
		std::cout << i << std::endl; i++;
	}

	return 0;	
}