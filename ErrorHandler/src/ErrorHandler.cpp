#include "ErrorHandler.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

ErrorHandler::ErrorHandler(const std::string& jsonFilePath) {
    // Carrega o arquivo JSON
    std::ifstream file(jsonFilePath);
    if (file.is_open()) {
        file >> errorData;  // Carrega os dados do arquivo JSON
    } else {
        std::cerr << "Erro ao carregar o arquivo JSON." << std::endl;
    }
}

std::string ErrorHandler::getErrorMessage(const std::string& errorCode) {
    if (errorData.contains(errorCode)) {
        return errorData[errorCode]["titulo"];
    }
    return "Erro desconhecido";
}

std::string ErrorHandler::getErrorDetails(const std::string& errorCode, const std::string& field) {
    if (errorData.contains(errorCode)) {
        if (errorData[errorCode].contains(field)) {
            return errorData[errorCode][field];
        }
    }
    return "Informação não disponível";
}
