#include "functions.h"
#include "sha256.h"


int main() {

    sf::RenderWindow window(sf::VideoMode(360, 800), "CourseSprout", sf::Style::Titlebar | sf::Style::Close);

    if(logoFade(window)) return 1;

    std::string email = "test@test.com";

    if(createAccount(window, email)) return 1;
    if(onBoarding(window, email)) return 1;
    
    //login();

    return 0;
    /*std::cout << "Hello Course Sprout!" << std::endl;

 */
}

bool writeUserInfo(const std::string& input, const std::string& fileName) {
    std::ofstream outfile("UserInfo/" + fileName, std::ios_base::app); 

    if(!outfile) {
        std::cout << "Error opening output file!" << std::endl;
        return 1;
    }

    outfile << input << std::endl;
    return 0;
}

