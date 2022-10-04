//
//  logger.h
//  
//
//  Created by Julia Groza on 2022-10-01.
//

#ifndef logger_h
#define logger_h

#include <ctime>
#include <sqlite3.h> 
#include <sstream>
#include "log_message.h"

class Logger {
    private:
    std::string appName;
    sqlite3* dbPointer;
    
    public:
    Logger(std::string &name);
    void write(std::string &message);
    std::vector<Log_Message> read_all();
    ~Logger();
}; 

#endif /* logger_h */
