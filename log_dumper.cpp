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
    std::string appName(argv[0]);
    appName.erase(0, 2);
    
    // make Logger object
    Logger logger2(appName);
    
    // read from object
    std::vector<Log_Message> entireLog = logger2.read_all();

    // read through vector and print
    cout << "Output of log: ";
    for(Log_Message oneMessage : entireLog) {
        std::string a = oneMessage.get_timestamp();
        std::string b = oneMessage.get_message();
        cout << a << ": " << b << endl;
    }
    return 0;
}
