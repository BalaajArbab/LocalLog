/*
Name: Balaaj Arbab
Student ID: 251055771
Date: 18th September 2022

A Logger class that implements logging functionality using an SQLite database to store log messages.
Multiple tables are used to keep track of logging for different applications, where the name of the application is the name of a table.
*/

#include "Logger.h"

using namespace std;

const char* DB_PATH{ "./Database.sqlite3" }; // Relative path to db file.

/*
Logger Constructor
Constructs the Logger object to be used to log messages.

@param appName :string The name of the app that is using the Logger class to log messages. Used as the name for a table in the DB.
*/
Logger::Logger(string appName)
    : _appName{appName}
{
    if (SQLITE_OK == sqlite3_open(DB_PATH, &_dbObject))
    {
        cout << "Database successfully opened. Table: " + _appName + '\n';
    }
    else
        throw "Database could not be opened.";

    if (tableSetup() == -1) throw "Error occured.";
}

/*
Logger Destructor
Safely closes the database connection.
*/
Logger::~Logger()
{
    sqlite3_close(_dbObject);
    cout << "Database successfully closed.\n";
}

/*
Logger::Write
Writes a message to the log with an internally calculated timestamp that corresponds to the current time.

@param messageText : const string& The message to write.
*/
int Logger::Write(const std::string& messageText)
{
    string timestamp = GetCurrentTime();

    string insertionStatement = "INSERT INTO " + _appName + " VALUES " + "(\"" + timestamp + "\", \"" + messageText + "\");";

    char** err = nullptr;

    sqlite3_exec(_dbObject, insertionStatement.data(), nullptr, nullptr, err);

    if (err) // TEST THIS MORE
    {
        cout << "here\n"; // REMOVE THIS
        cerr << err;
        sqlite3_free(err);
        err = nullptr;

        return -1;
    }

    return 0;
}

/*
Logger::ReadAll
Returns a list of all stored log messages for the Table/Log referred to by the Logger object.

@return shared_ptr<vector<LogMessage>> : A shared_ptr to a vector that contains LogMessage objects that have been read from the database.
*/
shared_ptr<vector<LogMessage>> Logger::ReadAll()
{
    auto list = make_shared<vector<LogMessage>>();

    string sqlQuery = "SELECT * from " + _appName;
    sqlite3_stmt* stmtObject;

    if (SQLITE_OK != sqlite3_prepare_v2(_dbObject, sqlQuery.data(), sqlQuery.length() + 1, &stmtObject, nullptr))
    {
        throw "Unable to prepare SQL statement.";
    }

    int stepReturnCode = sqlite3_step(stmtObject);

    while (stepReturnCode != SQLITE_DONE)
    {
        if (stepReturnCode == SQLITE_ERROR || stepReturnCode == SQLITE_MISUSE)
        {
            throw "Error code: " + stepReturnCode;
        }

        string timestamp = (const char *) sqlite3_column_text(stmtObject, 0);
        string message = (const char *) sqlite3_column_text(stmtObject, 1);

        list->push_back(LogMessage{ timestamp, message });

        stepReturnCode = sqlite3_step(stmtObject);
    }

    sqlite3_finalize(stmtObject);

    return list;
}

/*
private Logger::tableSetup
Creates a table in the database if one does not exist for the given appName to the Logger constructor.

@return int : 0 if successful, not 0 if not
*/
int Logger::tableSetup()
{
    string tableStatement = "CREATE TABLE IF NOT EXISTS " +
                            _appName +
                            " (Timestamp varchar(255), Message varchar(255));";

    char** err = nullptr;

    sqlite3_exec(_dbObject, tableStatement.data(), nullptr, nullptr, err);

    if (err) // TEST THIS MORE
    {
        cout << "here\n"; // REMOVE THIS
        cerr << err;
        sqlite3_free(err);
        err = nullptr;

        return -1;
    }

    return 0;
}
