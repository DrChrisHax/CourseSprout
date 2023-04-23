#include "window.h"
#include "sha256.h"


bool login() {
    sf::RenderWindow loginPage(sf::VideoMode(360, 800), "Login");

    sf::Font font;
    if(!font.loadFromFile("fonts/arial.ttf")) {
        loginPage.close();
        std::cerr << "Error loading font";
        return 1;
    }
    
    //email TEXT
    sf::Text emailText;
    emailText.setFont(font);
    emailText.setFillColor(sf::Color::Black);
    emailText.setString("Email:");
    emailText.setCharacterSize(20);
    emailText.setPosition(50, 50);

    //email BOX
    sf::RectangleShape emailBox(sf::Vector2f(200, 30));
    emailBox.setFillColor(sf::Color::White);
    emailBox.setOutlineColor(sf::Color::Black);
    emailBox.setOutlineThickness(1);
    emailBox.setPosition(50, 80);

    //email INPUT
    sf::Text emailInput;
    emailInput.setFont(font);
    emailInput.setCharacterSize(20);
    emailInput.setFillColor(sf::Color::Black);
    emailInput.setPosition(55, 85);

    std::string email = "";

    //PASSWORD TEXT
    sf::Text passwordText;
    passwordText.setFont(font);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setString("Password:");
    passwordText.setCharacterSize(20);
    passwordText.setPosition(50, 120);

    //PASSWORD BOX
    sf::RectangleShape passwordBox(sf::Vector2f(200, 30));
    passwordBox.setFillColor(sf::Color::White);
    passwordBox.setOutlineColor(sf::Color::Black);
    passwordBox.setOutlineThickness(1);
    passwordBox.setPosition(50, 150);

    sf::Text passwordInput;
    passwordInput.setFont(font);
    passwordInput.setCharacterSize(20);
    passwordInput.setFillColor(sf::Color::Black);
    passwordInput.setPosition(55, 155);

    std::string password = "";

    //LOGIN BUTTON
    sf::RectangleShape loginButton(sf::Vector2f(100, 30));
    loginButton.setFillColor(sf::Color::Blue);
    loginButton.setOutlineColor(sf::Color::Black);
    loginButton.setOutlineThickness(1);
    loginButton.setPosition(150, 200);

    sf::Text loginButtonText;
    loginButtonText.setFont(font);
    loginButtonText.setString("Login");
    loginButtonText.setCharacterSize(20);
    loginButtonText.setFillColor(sf::Color::White);
    loginButtonText.setPosition(165, 205);


    bool emailSelected = false;
    bool passwordSelected = false;


    while(loginPage.isOpen()) {

        sf::Event event;
        while(loginPage.pollEvent(event)) {

            //CLOSE PAGE
            if(event.type == sf::Event::Closed) {
                loginPage.close();
                return 1; //Login page closed prematurely

            }

            //MOUSE CLICKED
            if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                    if(loginButton.getGlobalBounds().contains(mousePos)){
                        int count = 0, size = email.size();
                        for(int i = 0; i < size; i++) {
                            if(email[i] == '@') count++;
                        }
                        if(!(count < 1 || count > 1) && size > 4){
                            //Do Login
                        }
                        else {
                            //Invalid Email
                        }
                    }
                    else if(emailBox.getGlobalBounds().contains(mousePos)) {
                        emailSelected = true;
                        passwordSelected = false;
                    }
                    else if(passwordBox.getGlobalBounds().contains(mousePos)) {
                        emailSelected = false;
                        passwordSelected = true;
                    }
                    else {
                        emailSelected = false;
                        passwordSelected = false;
                    }
                }
            }

            //HANDLE TEXT INPUT
            if(event.type == sf::Event::TextEntered) {
                if(emailSelected) {
                    if(event.text.unicode == 8 && !emailInput.getString().isEmpty()) {
                        emailInput.setString(emailInput.getString().substring(0, emailInput.getString().getSize() - 1));
                    }
                    else if(event.text.unicode != 8) {
                        emailInput.setString(emailInput.getString() + static_cast<char>(event.text.unicode));
                    }
                    email = emailInput.getString();
                }
                else if(passwordSelected) {
                    if(event.text.unicode == 8 && !passwordInput.getString().isEmpty()) {
                        passwordInput.setString(passwordInput.getString().substring(0, passwordInput.getString().getSize() - 1));
                    }
                    else if(event.text.unicode != 8) {
                        passwordInput.setString(passwordInput.getString() + static_cast<char>(event.text.unicode));
                    }
                    password = passwordInput.getString();
                }
            }
        }

        
        //UPDATE SCREEN
        loginPage.clear(sf::Color::White);
  
        loginPage.draw(emailText);
        loginPage.draw(emailBox);
        loginPage.draw(emailInput);
        loginPage.draw(passwordText);
        loginPage.draw(passwordBox);
        loginPage.draw(passwordInput);
        loginPage.draw(loginButton);
        loginPage.draw(loginButtonText);

        loginPage.display();
    }

    return 0;
}