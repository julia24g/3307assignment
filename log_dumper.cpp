//
//  log_dumper.cpp
//  
//
//  Created by Julia Groza on 2022-10-04.
//

#include "logger.h"
using namespace std;

int main(int argc, char* argv[]){
    // updating string to find app name
    std::string appName(argv[1]);
    
    // make Logger object
    Logger logger2(appName);
    
    // read from object
    std::vector<Log_Message> entireLog = logger2.read_all();

    // read through vector and print
    std::cout << "All Messages from Log:" << std::endl;
    for(Log_Message oneMessage : entireLog) {
        std::string a = oneMessage.get_timestamp();
        a.erase(remove(a.begin(), a.end(), '\n'));
        std::string b = oneMessage.get_message();
        std::cout << a << ": " << b << std::endl;
    }
    return 0;
}
