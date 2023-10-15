#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    // Set up characters for the password
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Get the desired password length from the user
    int passwordLength;
    std::cout << "Enter the desired password length: ";
    std::cin >> passwordLength;

    // Generate and display the random password
    std::string password;
    for (int i = 0; i < passwordLength; ++i) {
        int randomIndex = std::rand() % characters.length();
        password += characters[randomIndex];
    }

    std::cout << "Random Password: " << password << std::endl;

    return 0;
}
