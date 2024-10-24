//
// Created by christian on 19.10.24.
//

#include "ErrorHandler.h"
#include <iostream>

ErrorHandler::ErrorHandler() {
    errorMessages[ErrorCode::Successful] = "No error occurred.";
    errorMessages[ErrorCode::FileAccessError] = "Unable to access the file.";
    errorMessages[ErrorCode::FileReadError] = "File could not be fully read.";
    // ... add more error messages ...
}

void ErrorHandler::handleError(ErrorCode errorCode) {
    if (errorCode != ErrorCode::Successful) {
        std::cerr << "Error: " << errorMessages[errorCode] << std::endl;
        // You can add more actions here, like logging the error
    }
}