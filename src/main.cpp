#include "functions.h"
#include "sha256.h"


int main() {

    std::string email = "test@test.com";

    //if(createAccount(email)) return 1;
    if(onBoarding(email)) return 1;
    //login();

    return 0;
    


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

