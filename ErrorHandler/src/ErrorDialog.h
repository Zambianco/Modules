#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QString>
#include <QMessageBox>
#include "ErrorHandler.h"

#if defined(WIN32) && defined(BUILD_DLL)
#    define DLL_EXPORT __declspec(dllexport)
#else
#    define DLL_EXPORT
#endif

class DLL_EXPORT ErrorDialog {
public:
    void showError(const std::string& errorCode, ErrorHandler& handler);
};

#endif