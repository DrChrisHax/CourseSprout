#include "window.hpp"

bool login(std::string& username, std::string& password) {
    sf::RenderWindow loginPage(sf::VideoMode(400, 600), "Login");

    sf::Font font;
    if(!font.loadFromFile("fonts/arial.ttf")) {
        loginPage.close();
        std::cout << "Text failed to load";
        return 1;
    }

    //USERNAME BOX
    sf::RectangleShape usernameBox(sf::Vector2f(200, 30));
    usernameBox.setPosition(100, 100);
    usernameBox.setFillColor(sf::Color::White);
    usernameBox.setOutlineThickness(1);
    usernameBox.setOutlineColor(sf::Color::Black);
    
    //USERNAME TEXT
    sf::Text usernameText;
    usernameText.setFont(font);
    usernameText.setFillColor(sf::Color::Black);
    usernameText.setString("Username:");
    usernameText.setCharacterSize(24);
    usernameText.setPosition(100, 100);

    //PASSWORD TEXT
    sf::Text passwordText;
    passwordText.setFont(font);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setString("Password:");
    passwordText.setCharacterSize(24);
    passwordText.setPosition(100, 200);

    //LOGIN BUTTON
    sf::RectangleShape loginButton(sf::Vector2f(100, 50));
    loginButton.setPosition(100, 300);
    sf::Text loginButtonText;
    loginButtonText.setFont(font);
    loginButtonText.setString("Login");
    loginButtonText.setCharacterSize(24);
    loginButtonText.setPosition(120, 310);





    while(loginPage.isOpen()) {

        sf::Event event;
        while(loginPage.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                loginPage.close();
                return 1; //Login page closed prematurely
            }

            if(event.type == sf::Event::MouseButtonPressed &&
               event.mouseButton.button == sf::Mouse::Left &&
               loginButton.getGlobalBounds().contains(
                    event.mouseButton.x,
                    event.mouseButton.y)) 
            {
                //Check credentials

                //Login success or fail
                //If fail, do not close window
                //If success, close window
                loginPage.close();
                return 0;
            }
        }
            loginPage.clear(sf::Color::White);

            loginPage.draw(usernameBox);
            loginPage.draw(usernameText);
            loginPage.draw(passwordText);
            loginPage.draw(loginButton);
            loginPage.draw(loginButtonText);

            loginPage.display();
    }
    return 0;
}