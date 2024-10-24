//
// Created by christian on 19.10.24.
//

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string>
#include <map>

enum class ErrorCode {
    Successful,
    FileAccessError,
    FileReadError,
};

class ErrorHandler {
public:
    ErrorHandler();
    void handleError(ErrorCode errorCode);

private:
    std::map<ErrorCode, std::string> errorMessages;
};

#endif // ERRORHANDLER_H