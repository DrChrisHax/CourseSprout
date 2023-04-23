#include "functions.h"

bool onBoarding(const std::string& email) {
    
    sf::RenderWindow onBoardingPage(sf::VideoMode(360, 800), "On Boarding", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if(!font.loadFromFile("fonts/arial.ttf")) {
        onBoardingPage.close();
        std::cout << "Error loading font";
        return 1;
    }

    //2 Buttons Page 1
    //sf::RectangleShape


    //Search Bar & instructions Page 2

    //Check boxes for page 3

    //Search bar and button for page 4







    while(onBoardingPage.isOpen()) {

        sf::Event event;
        while(onBoardingPage.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                onBoardingPage.close();
                return 1; //onBoarding closed prematurely

            }
        }
    }


    return 0;
}