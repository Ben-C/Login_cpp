#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "countNumbers.cpp"

int def(){
	std::cout << '\a';
	std::cout << "Choice not recognised programme will now terminate.";
	return 0;
}

int regUser(){
	bool cont;
	int userID = 0;
	while(cont = true){
		std::string userName, userPass;
		std::cout << "select a username: \n"; std::cin >> userName;
		std::cout << "select a password: \n"; std::cin >> userPass;
		std::ofstream uLog;
		uLog.open("username.csv", std::ios::app | std::ios::out);
		uLog << userID++ << "," << userName << "," << userPass << std::endl;
		uLog.close();
		std::cout << "Would you like to Enter another user? Y/N" << std::endl;
		std::string userChoice;
		std::cin >> userChoice;
	if(userChoice == "Y"){
		cont = true;
	} 
	else{
		break;
	}
}
}

void checkLogin(){
	std::string userName, userPass;
	std::cout << "Enter your username: \n"; std::cin >> userName;
	std::cout << "Enter your password: \n"; std::cin >> userPass;
	std::string uID, uN, uP;
	std::ifstream userLog("username.csv", std::ios::in);
	if (userLog.is_open()){
		while (userLog >> uN >> uP){
			getline(userLog, uN);
			getline(userLog, uP);
			if (uN == userName && uP == userPass){
				std::cout << "Login Succseful!" << std::endl;
				countNumbers();
				break;
			}
			else{
				std::cout << "Login failed, programe will terminate!" << std::endl;
				break;
			}
		}
	}
		else{
			userLog.close();
		}
}

int login(){
	int choice;
	std::cout << "1: Register\n2: Login\n"; std::cin >> choice;
	switch (choice){
		default:
			def();
		break;
		case 1:
			regUser();
		break;
		case 2:
			checkLogin();
		}	
	return 0;
}