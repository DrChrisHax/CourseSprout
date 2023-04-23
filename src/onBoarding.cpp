#include "functions.h"

bool onBoarding(const std::string& email) {
    
    sf::RenderWindow onBoardingPage(sf::VideoMode(360, 800), "On Boarding", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if(!font.loadFromFile("fonts/mulish/Mulish-Regular.ttf")) {
        onBoardingPage.close();
        std::cout << "Error loading font";
        return 1;
    }
    sf::Color background(255, 252, 227);
    sf::Color button(229, 224, 207);
    sf::Color text(39, 33, 33);
    sf::Color nextButton(0, 145, 65);
    sf::Color nextText(255, 252, 227);

    int phase = 1;

    //Phase 1
    sf::RectangleShape transferStudent(sf::Vector2f(300, 200));
    transferStudent.setPosition(30, 150);
    transferStudent.setFillColor(button);
    sf::Text transferStudentText("A prospective\nUC transfer", font, 24);
    transferStudentText.setFillColor(text);
    transferStudentText.setPosition(transferStudent.getPosition().x + 82, transferStudent.getPosition().y + 70);

    sf::RectangleShape currentStudent(sf::Vector2f(300, 200));
    currentStudent.setPosition(30, 450);
    currentStudent.setFillColor(button);
    sf::Text currentStudentText("A current\nUC student", font, 24);
    currentStudentText.setFillColor(text);
    currentStudentText.setPosition(currentStudent.getPosition().x + 82, currentStudent.getPosition().y + 70);

    //Phase 2
    sf::RectangleShape searchColleges(sf::Vector2f(300, 30));
    searchColleges.setFillColor(background);
    searchColleges.setOutlineColor(text);
    searchColleges.setPosition(30, 100);

    sf::Text searchCollegesText;
    searchCollegesText.setFont(font);
    searchCollegesText.setFillColor(text);
    searchCollegesText.setString("Your Current College:");
    searchCollegesText.setCharacterSize(20);
    searchCollegesText.setPosition(30, 100);

    sf::Text searchCollegesInput("", font, 16);
    searchCollegesInput.setFillColor(text);
    searchCollegesInput.setPosition(35, 105);

    sf::Text searchCollegesPlaceholder("Search...", font, 16);
    searchCollegesPlaceholder.setFillColor(text);
    searchCollegesPlaceholder.setPosition(35, 105);

    std::string college = "";

    //Phase Check boxes for page 3

    //Phase Search bar and button for page 4

    while(onBoardingPage.isOpen()) {
        sf::Event event;
        while(onBoardingPage.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                onBoardingPage.close();
                return 1;
            }
            switch(phase){
                case(1): //Transfer vs Current Student
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                        if(transferStudent.getGlobalBounds().contains(mousePos)) {
                            writeUserInfo("Transfer Student", email + ".txt");
                            phase = 2;
                        }
                        else if(currentStudent.getGlobalBounds().contains(mousePos)) {
                            writeUserInfo("Current Student", email + ".txt");
                            phase = 2;
                        }
                    }
                    break;
                case(2): //Current College Selection
                    if(event.type == sf::Event::TextEntered) {
                        if(event.text.unicode == 8) { //BackSpace
                            if(!college.empty()) {
                                college.pop_back();
                            }
                            else {
                                college += static_cast<char>(event.text.unicode);
                            }
                        }
                    }
                    break;

                default:
                    break;

            }
                
        }

        onBoardingPage.clear(background);

        switch(phase){
            case(1):
                onBoardingPage.draw(transferStudent);
                onBoardingPage.draw(transferStudentText);
                onBoardingPage.draw(currentStudent);
                onBoardingPage.draw(currentStudentText);
                break;
            case(2):
                onBoardingPage.draw(searchColleges);
                searchCollegesInput.setString(college);
                if(college.empty()) {
                    onBoardingPage.draw(searchCollegesPlaceholder);
                }
                else {
                    onBoardingPage.draw(searchCollegesInput);
                }

            
            default:
                break;
        }

        onBoardingPage.display();
    }
    return 0;
}