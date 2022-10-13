/*
Name: Balaaj Arbab
Student ID: 251055771
Date: 18th September 2022

A Logger class that implements logging functionality using an SQLite database to store log messages.
Multiple tables are used to keep track of logging for different applications, where the name of the application is the name of a table.
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sqlite3.h>
#include <string.h>

#include "LogMessage.h"
#include "Utility.h"

class Logger
{
public:
    Logger(std::string appName);

    ~Logger();

    int Write(const std::string& messageText);

    std::shared_ptr<std::vector<LogMessage>> ReadAll();

private:
    const std::string _appName;
    sqlite3* _dbObject;

    int tableSetup();
};

#endif
