//
//  log_message.cpp
//  
//
//  Created by Julia Groza on 2022-10-01.
//

#include "log_message.h"
using namespace std;

// default constructor
Log_Message::Log_Message(std::string messageText, std::string timeStamp){
    message = messageText;
    time = timeStamp;
}

std::string Log_Message::get_message(){
    return message;
}

std::string Log_Message::get_timestamp(){
    return time;
}

// deconstructor
Log_Message::~Log_Message(){
}
    

