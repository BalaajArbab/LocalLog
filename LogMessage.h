/*
Name: Balaaj Arbab
Student ID: 251055771
Date: 18th September 2022

A Log Message container class that encapsulates all the information for a stored log message. Such as timestamp and message content.
*/

#ifndef LOG_MESSAGE_H
#define LOG_MESSAGE_H

#include <iostream>
#include <string>

class LogMessage
{
public:
    LogMessage(const std::string& timestamp, const std::string& message);

    ~LogMessage();

    const std::string& GetMessage() const;

    const std::string& GetTimestamp() const;

private:
    std::string _timestamp;
    std::string _message;
};

std::ostream& operator<<(std::ostream& out, const LogMessage& lm);

#endif
