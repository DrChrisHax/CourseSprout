#include "window.h"
#include "sha256.h"


int main() {

    if(!createAccount()) return 1;
    if(!onBoarding()) return 1;
    //login();

    return 0;
    /*std::cout << "Hello Course Sprout!" << std::endl;

 */
}

