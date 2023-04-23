#include "functions.h"

bool onBoarding() {
    
    sf::RenderWindow createAccountPage(sf::VideoMode(360, 800), "On Boarding", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if(!font.loadFromFile("fonts/arial.ttf")) {
        createAccountPage.close();
        std::cout << "Error loading font";
        return 1;
    }




    
    return 0;
}