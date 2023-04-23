#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//1 for fail, 0 for success
bool createAccount(std::string&);
bool createAccountButtonClick(const std::string&, const std::string&, const std::string&, std::string&);
bool onBoarding(const std::string&);
bool phase4ButtonClick();
bool writeUserInfo(const std::string&, const std::string&);




/*
bool login();
bool loginButtonClick(const std::string&, const std::string&);
*/
#endif