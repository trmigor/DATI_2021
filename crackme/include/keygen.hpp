#ifndef CRACKME_INCLUDE_KEYGEN_HPP_
#define CRACKME_INCLUDE_KEYGEN_HPP_

#include <string>

namespace cm {

// isValid checks if the given login is valid.
bool isValid(const std::string& login);

// generatePassword returns a corresponding password for the given login.
// Login should be valid.
std::string generatePassword(const std::string& login);

// processLogin prints a corresponding password
// for the given login if it is valid and returns EXIT_SUCCESS.
// Otherwise, it prints an error message and returns EXIT_FAILURE.
int process(const std::string& login);

}  // namespace cm

#endif  // CRACKME_INCLUDE_KEYGEN_HPP_
