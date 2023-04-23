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
bool logoFade(sf::RenderWindow&);
bool createAccount(sf::RenderWindow&, std::string&);
bool createAccountButtonClick(const std::string&, const std::string&, const std::string&, std::string&);
bool onBoarding(sf::RenderWindow&, const std::string&);
bool writeUserInfo(const std::string&, const std::string&);




/*
bool login();
bool loginButtonClick(const std::string&, const std::string&);
*/
#endif