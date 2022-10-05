//
//  log_message.cpp
//  Description: includes Log_Message functions
//
//  Created by Julia Groza on 2022-10-01.
//

#include "log_message.h"
using namespace std;

// Function Name: Log_Message
// Description: Constructor
// Parameter Descriptions: takes in a message and a timestamp as strings
// Return Descriptions: none
Log_Message::Log_Message(std::string messageText, std::string timeStamp){
    message = messageText;
    time = timeStamp;
}

// Function Name: get_message
// Description: gets message from the Log_Message
// Parameter Descriptions: none
// Return Descriptions: returns string
std::string Log_Message::get_message(){
    return message;
}

// Function Name: get_timestamp
// Description: gets timestamp string from the Log_Message
// Parameter Descriptions: none
// Return Descriptions: returns string
std::string Log_Message::get_timestamp(){
    return time;
}

// Function Name: ~Log_Message
// Description: deconstructor
// Parameter Descriptions: none
// Return Descriptions: none
Log_Message::~Log_Message(){
}
    

