#ifndef MODULEERROR_H
#define MODULEERROR_H

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "nlohmann/json.hpp"

class ErrorHandler {
public:
    ErrorHandler(const std::string& filename);
    std::vector<std::string> getErrorMessages(int errorCode);

private:
    std::unordered_map<int, std::vector<std::string>> errorMessages;
};

#endif