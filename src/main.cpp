#include "window.hpp"


int main() {

    std::string username = "", password = "";
    login(username, password);

    

    return 0;
    /*std::cout << "Hello Course Sprout!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Course Sprout");

    std::string username = "", password = "";
    bool loggedIn = 0;

    while(window.isOpen()) {



        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }


        if(!loggedIn){
            if(login(username, password)) { //1 for fail, 0 for success
                std::cout << "Login Failed" << std::endl;
                loggedIn = 1;
            }
            else {
                std::cout << "Login Success" << std::endl;
                loggedIn = 1;
            }
        }


        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;*/
}

