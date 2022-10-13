/*
A Log Message container class that encapsulates all the information/metadata for a stored log message. Such as timestamp and message content.
*/

#include "LogMessage.h"

using namespace std;

/*
LogMessage Constructor
Constructs the LogMessage object to store message content and metadata.

@param appName :string The name of the app that is using the Logger class to log messages. Used as the name for a table in the DB.
*/
LogMessage::LogMessage(const string& timestamp, const string& message)
            : _timestamp{ timestamp }, _message{ message }
            {}

/*
Logger Destructor
*/
LogMessage::~LogMessage()
            {} 

/*
LogMessage content getter

@return const string& : LogMessage content
*/
const string& LogMessage::GetMessage() const 
    {
        return _message;
    }

/*
LogMessage timestamp getter

@return const string& : LogMessage timestamp
*/
const string& LogMessage::GetTimestamp() const
    {
        return _timestamp;
    }

/*
LogMessage insertion operator overload to std::cout

@return ostream&
*/
ostream& operator<<(ostream& out, const LogMessage& lm)
{
    return out << lm.GetTimestamp() << ": " << lm.GetMessage();
}
