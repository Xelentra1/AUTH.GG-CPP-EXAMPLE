#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include "xor.h"
//#include "lw_http.hpp"
#include <ostream>
#include <regex>
#include "print.h"
#include "hwid.h"
#include "md5wrapper.h"
#include "crypto.h"
#include "authgg.h"

extern c_crypto crypto;


int main()
{
	
	///////////////////////////////////////////////////////////////////////////////////////
	//                              Application Settings
	crypto.aid = "AID_HERE";
	crypto.secret = "SECRET_HERE";
	crypto.apikey = "API_KEY_HERE";
	crypto.version = "1.0";
	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////
	//                                Initialization
	auto md5 = new md5wrapper();
	authgg::GenerateSeed();
	authgg::Initialize();
	std::string choice;
	std::string username;
	std::string password;
	std::string email;
	std::string key;
	SetConsoleTitle(crypto.appname.c_str());
	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////
	//                                    Freemode
	if (crypto.freemode_status == "Enabled")
	{
		print::set_text("Freemode is enabled! \n\n", Green);
		//do freemode action here
	}
	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////
	//                                  Menu/Choices
	print::set_text("Welcome to Auth.GG Native C++ Example! \n\n", LightBlue);
	print::set_text("[1] Login \n", LightBlue);
	print::set_text("[2] Register \n\n", LightBlue);
	print::set_text("Please select an option from above : \n", LightBlue);
	std::getline(std::cin, choice);
	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////
	//                                Choice actions
	if (choice == "1")
	{
		system("CLS");
		print::set_text("Welcome to the Login page! \n\n", LightBlue);
		print::set_text("Username: \n", LightBlue);
		std::getline(std::cin, username);
		print::set_text("Password: \n", LightBlue);
		std::getline(std::cin, password);
		authgg::Login(username, password);
	}
	if (choice == "2")
	{
		system("CLS");
		print::set_text("Welcome to the Register page! \n\n", LightBlue);
		print::set_text("Username: \n", LightBlue);
		std::getline(std::cin, username);
		print::set_text("Password: \n", LightBlue);
		std::getline(std::cin, password);
		print::set_text("Email: \n", LightBlue);
		std::getline(std::cin, email);
		print::set_text("License: \n", LightBlue);
		std::getline(std::cin, key);
		authgg::Register(username, password, email, key);
	}
	std::getline(std::cin, choice);
}
///////////////////////////////////////////////////////////////////////////////////////