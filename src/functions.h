#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

//1 for fail, 0 for success
bool createAccount();
bool createAccountButtonClick(const std::string&, const std::string&, const std::string&);
bool onBoarding();
bool writeUserInfo(const std::string&, const std::string&);




/*
bool login();
bool loginButtonClick(const std::string&, const std::string&);
*/
#endif