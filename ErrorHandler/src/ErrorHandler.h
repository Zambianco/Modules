#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>  

#if defined(WIN32) && defined(BUILD_DLL)
#    define DLL_EXPORT __declspec(dllexport)
#else
#    define DLL_EXPORT
#endif

class DLL_EXPORT ErrorHandler {
public:
    ErrorHandler(const std::string& jsonFilePath);
    std::string getErrorMessage(const std::string& errorCode);
    std::string getErrorDetails(const std::string& errorCode, const std::string& field);
private:
    nlohmann::json errorData; 
};

#endif