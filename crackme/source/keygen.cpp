#include <iostream>
#include <string>
#include "keygen.hpp"

namespace cm {

// isValid checks if the given login is valid.
bool isValid(const std::string& login) {
    for (auto ch : login) {
        if (ch < 'A') {
            return false;
        }
    }
    return login.size() > 0;
}

// generatePassword returns a corresponding password for the given login.
// Login should be valid.
std::string generatePassword(const std::string& login) {
    size_t sumOfChars = 0;
    for (auto ch : login) {
        sumOfChars += static_cast<size_t>(ch);
        if (ch >= 'Z') {
            sumOfChars -= 0x20;
        }
    }
    size_t password = sumOfChars ^ 0x1234 ^ 0x5678;
    return std::to_string(password);
}

// processLogin prints a corresponding password
// for the given login if it is valid and returns EXIT_SUCCESS.
// Otherwise, it prints an error message and returns EXIT_FAILURE.
int process(const std::string& login) {
    if (!isValid(login)) {
        std::cerr << "Invalid login: " << login << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Password: " << generatePassword(login) << std::endl;
    return EXIT_SUCCESS;
}

}  // namespace cm
