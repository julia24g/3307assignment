//
//  log_message.h
//  
//
//  Created by Julia Groza on 2022-10-01.
//

#ifndef log_message_h
#define log_message_h

#include <string.h>
#include <vector>
#include <iostream>
#include <stdio.h>

class Log_Message {
    private:
    std::string message;
    std::string time;
    
    public:
    Log_Message(std::string messageText, std::string timeStamp);
    std::string get_message();
    std::string get_timestamp();
    ~Log_Message();
}; 

#endif /* log_message_h */
