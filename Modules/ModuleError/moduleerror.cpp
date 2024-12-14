#include "moduleerror.h"

ErrorHandler::ErrorHandler(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        nlohmann::json jsonData;
        file >> jsonData;

        for (const auto& [errorCode, errorData] : jsonData["Errors"].items()) {
            int code = std::stoi(errorCode, nullptr, 16); 
            for (const auto& message : errorData["message"]) {
                errorMessages[code].push_back(message);
            }
        }
        file.close();
    } else {
        throw std::runtime_error("Erro ao abrir o arquivo de erros.");
    }
}

std::vector<std::string> ErrorHandler::getErrorMessages(int errorCode) {
    auto it = errorMessages.find(errorCode);
    if (it != errorMessages.end()) {
        return it->second;
    } else {
        return {}; 
    }
}