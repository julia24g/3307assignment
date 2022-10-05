//
//  log_message.cpp
//  File Contents: includes Logger class functions that create a table, write to a table, and read a table
//
//  Created by Julia Groza on 2022-10-01.
//

#include "logger.h"
using namespace std;

// Function Name: Logger
// Description: constructor that creates a connection to the database and creates a table based off of input
// Parameter Descriptions: string of pointer to name
// Return Descriptions: none
Logger::Logger(std::string &name){
    // storing app name in Logger object
    this->appName = name;
    // preparing for use in open function
    // const char * aa = name.c_str();
    
    /** OPENING A TABLE*/
    
    // setting up open function & create table function
    char* zErrMsg;
    int handle = 0;

    std::string db_file_name = "dbFile";
    
    // open function
    handle = sqlite3_open(db_file_name.c_str(), &dbPointer); // returns db connection

    // check to see if the database opened or not
    if (handle != SQLITE_OK) { // if it's 1, this means there was a problem
        std::cerr << "Error open DB " << sqlite3_errmsg(dbPointer) << std::endl;
    }
    else { // if it's still 0, success!
        std::cout << "Opened Database Successfully!" << std::endl;
    }
    
    /** CREATING A TABLE*/
    
    // create a SQL statement for creating a table

    ostringstream os_sql;
    os_sql << "create table if not exists " << this->appName << " (timestamp varchar(255), message varchar(255));";
    std::string sql = os_sql.str();

    // executing SQL open db function
    handle = sqlite3_exec(dbPointer, sql.c_str(), NULL, NULL, &zErrMsg);
    // checking to see if it executed correctly
    if (handle != SQLITE_OK) { // did not get the OK
            std::cerr << "Error Create Table" << std::endl;
    }
    else std::cout << "Table Created Successfully" << std::endl; // got the OK
}

// Function Name: write()
// Description: writes to the table based off user input
// Parameter Descriptions: string of the message
// Return Descriptions: none
void Logger::write(std::string &message){
    // setting up parameters
    char* zErrMsg;
    int handle = 0;
    
    // getting timestamp
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::string goodtime = ctime(&start_time);

    // creating SQL statement for insert
    std::string aName = appName;
    std::string m = message;
    std::string sql = "INSERT INTO " + aName + " VALUES (\"" + goodtime + "\", \"" + m + "\");";
    
    handle = sqlite3_exec(dbPointer, sql.c_str(), NULL, 0, &zErrMsg);
    if (handle != SQLITE_OK) {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(zErrMsg);
        }
    else std::cout << "Records Created Successfully!" << std::endl;
}

// Function Name: read_all
// Description: reads all messages from the app and stores them in a vector in the form of Log_Messages
// Parameter Descriptions: none
// Return Descriptions: returs a vector of Log_Messages
std::vector<Log_Message> Logger::read_all(){ 
    // creating vector
    std::vector<Log_Message> allMessages;

    // create SQL statement
    ostringstream os_sql;
    os_sql << "SELECT * FROM " << this->appName << ";";
    std::string sql = os_sql.str();
    
    // create output pointer for prepare statement
    sqlite3_stmt* stmt;
    
    // step 1: use prepare to prepare the SQL statement

    int prepPointer = sqlite3_prepare(this->dbPointer, sql.c_str(), sql.size(), &stmt, NULL);
    // check if the procedure worked
    if (prepPointer != SQLITE_OK) { // not ok - there was an error
            std::cerr << "Error Select" << std::endl;
        }
    else std::cout << "Records Selected Successfully!" << std::endl; // received ok, so records created
    
    // step 2 and 3: step statement and column statement for reading data
    int stepPointer = sqlite3_step(stmt);

    // check return value on stepPointer - loop through if there are still rows left
    while (stepPointer != SQLITE_DONE) {
        std::string timeresult = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0))); 
        std::string mesgresult = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1))); 
        Log_Message newmessg(mesgresult.c_str(), timeresult.c_str());
        allMessages.push_back(newmessg);
        stepPointer = sqlite3_step(stmt);
    }
    
    // step 4: delete the prepared statement
    int returncode = sqlite3_finalize(stmt);
    return allMessages;
}

// Function Name: ~Logger
// Description: destructor
// Parameter Descriptions: none
// Return Descriptions: none
Logger::~Logger(){
    sqlite3_close(dbPointer); // closing the database connection
    
}
