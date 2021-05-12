#include <iostream>
#include <string>
#include "keygen.hpp"

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);

    std::string login;
    if (argc > 1) {
        login = argv[1];
        std::cout << "Login: " << login << std::endl;
    } else {
        std::cout << "Login: ";
        std::cin >> login;
    }

    return cm::process(login);
}
