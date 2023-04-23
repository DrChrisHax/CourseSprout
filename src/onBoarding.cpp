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

    const std::string UCOptions[9] {
        "UC Berkeley",
        "UC Davis",
        "UC Irvine",
        "UCLA",
        "UC Merced",
        "UC Riverside",
        "UC San Diego",
        "UC Santa Barbara",
        "UC Santa Cruz"
    };

    int phase = 1;

    //Phase 1 - Transfer / Current
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

    //Phase 2 - Current College
    sf::RectangleShape searchColleges(sf::Vector2f(300, 30));
    searchColleges.setFillColor(background);
    searchColleges.setOutlineThickness(2);
    searchColleges.setOutlineColor(text);
    searchColleges.setPosition(30, 100);

    sf::Text searchCollegesText;
    searchCollegesText.setFont(font);
    searchCollegesText.setFillColor(text);
    searchCollegesText.setString("Your Current College:");
    searchCollegesText.setCharacterSize(20);
    searchCollegesText.setPosition(30, 70);

    sf::Text searchCollegesInput("", font, 16);
    searchCollegesInput.setFillColor(text);
    searchCollegesInput.setPosition(35, 105);

    sf::Text searchCollegesPlaceholder("Search...", font, 16);
    searchCollegesPlaceholder.setFillColor(text);
    searchCollegesPlaceholder.setPosition(35, 105);


    std::string college = "";
    std::vector<std::string> results = {""};

    std::vector<std::string> collegeList;
    std::ifstream infile("Database/CommunityColleges.txt");
    std::string line;
    while(std::getline(infile, line)) {
        collegeList.push_back(line);
    }
    infile.close();

    //Phase 3 - Major
    sf::RectangleShape searchMajors(sf::Vector2f(300, 30));
    searchMajors.setFillColor(background);
    searchMajors.setOutlineThickness(2);
    searchMajors.setOutlineColor(text);
    searchMajors.setPosition(30, 100);

    sf::Text searchMajorsText;
    searchMajorsText.setFont(font);
    searchMajorsText.setFillColor(text);
    searchMajorsText.setString("Your Current Major:");
    searchMajorsText.setCharacterSize(20);
    searchMajorsText.setPosition(30, 70);

    sf::Text searchMajorsInput("", font, 16);
    searchMajorsInput.setFillColor(text);
    searchMajorsInput.setPosition(35, 105);

    sf::Text searchMajorsPlaceholder("Search...", font, 16);
    searchMajorsPlaceholder.setFillColor(text);
    searchMajorsPlaceholder.setPosition(35, 105);


    std::string major = "";

    std::vector<std::string> majorList;
    infile.open("Database/Majors.txt");
    while(std::getline(infile, line)) {
        majorList.push_back(line);
    }
    infile.close();

    //Phase 4 - Potential Transfer Schools
    const int checkboxSize = 20;
    const int checkboxSpacing = 30;
    sf::RectangleShape checkboxes[9];
    for(int i = 0; i < 9; i++) {
        checkboxes[i].setSize(sf::Vector2f(checkboxSize, checkboxSize));
        checkboxes[i].setPosition(sf::Vector2f(20, 20 + (checkboxSize + checkboxSpacing) * i));
        checkboxes[i].setOutlineThickness(2);
        checkboxes[i].setOutlineColor(text);
    }

    sf::Text optionText[9];
    for(int i = 0; i < 9; i++) {
        optionText[i].setFont(font);
        optionText[i].setString(UCOptions[i]);
        optionText[i].setCharacterSize(20);
        optionText[i].setFillColor(text);
        optionText[i].setPosition(sf::Vector2f(5 + checkboxSize + checkboxSpacing * 2, 20 + (checkboxSize + checkboxSpacing) * i));
    }


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
                            if(college.size() > 0) college.pop_back();
                            else results[0] = "";
                        }
                        else if(event.text.unicode == 10 || event.text.unicode == 13) { //Enter / Return
                            if(!(results[0] == "")){
                                writeUserInfo(results[0], email + ".txt");
                                phase = 3;
                            }
                        }
                        else {
                            college += std::tolower(static_cast<char>(event.text.unicode));
                        }
                        results.clear();
                        for(const auto& line : collegeList) {
                            if(line.find(college) != std::string::npos) {
                                results.push_back(line);
                                if(results.size() == 5) {
                                    break;
                                }
                            }
                        }
                        
                    }
                    break;
                case(3):
                    if(event.type == sf::Event::TextEntered) {
                        if(event.text.unicode == 8) { //BackSpace
                            if(major.size() > 0) major.pop_back();
                            else results[0] = "";
                        }
                        else if(event.text.unicode == 10 || event.text.unicode == 13) { //Enter / Return
                            if(!(results[0] == "")){
                                writeUserInfo(results[0], email + ".txt");
                                phase = 4;
                            }
                        }
                        else {
                            major += std::tolower(static_cast<char>(event.text.unicode));
                        }
                        results.clear();
                        for(const auto& line : majorList) {
                            if(line.find(major) != std::string::npos) {
                                results.push_back(line);
                                if(results.size() == 5) {
                                    break;
                                }
                            }
                        }
                        
                    }
                case(4):
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        for(int i = 0; i < 9; i++) {
                            if(checkboxes[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                                if(checkboxes[i].getFillColor() == background) {
                                    checkboxes[i].setFillColor(nextButton);
                                }
                                else {
                                    checkboxes[i].setFillColor(background);
                                }
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
                onBoardingPage.draw(searchCollegesText);
                searchCollegesInput.setString(college + '\n');
                for(size_t i = 0; i < results.size(); i++) {
                    searchCollegesInput.setString(searchCollegesInput.getString() + '\n' + results[i]);
                }
                if(college.empty()) {
                    onBoardingPage.draw(searchCollegesPlaceholder);
                }
                else {
                    onBoardingPage.draw(searchCollegesInput);
                }
                break;
            case(3):
                onBoardingPage.draw(searchMajors);
                onBoardingPage.draw(searchMajorsText);
                searchMajorsInput.setString(major + '\n');
                for(size_t i = 0; i < results.size(); i++) {
                    searchMajorsInput.setString(searchMajorsInput.getString() + '\n' + results[i]);
                }
                if(major.empty()) {
                    onBoardingPage.draw(searchMajorsPlaceholder);
                }
                else {
                    onBoardingPage.draw(searchMajorsInput);
                }
                break;
            case(4):
                for(int i = 0; i < 9; i++) {
                    onBoardingPage.draw(checkboxes[i]);
                    onBoardingPage.draw(optionText[i]);
                }
                break;
            

            
            default:
                break;
        }

        onBoardingPage.display();
    }
    return 0;
}