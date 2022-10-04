//
//  log_generator.cpp
//  
//
//  Created by Julia Groza on 2022-10-01.
//

#include <unistd.h>
#include "logger.h"
using namespace std;

void signal_handler(int signal_num)
{
    cout << "The interrupt signal is (" << signal_num
         << "). \n";
  
    // It terminates the  program
    exit(signal_num);
}

int main(int argc, char* argv[]){
    
    // create vector
    vector<std::string> messages;
    
    // push messages onto vector
    for (int i = 1; i < argc; i++)
        messages.push_back(argv[i]);
    
    // make sure the vector is correct
    cout << "Output of begin and end: ";
    for (auto i = messages.begin(); i != messages.end(); ++i)
        cout << *i << " ";
    
    // updating string to find app name
    std::string appName(argv[0]);
    appName.erase(0, 2);
    
    /** CREATE LOGGER */
    Logger logger1(appName);

    signal(SIGABRT, signal_handler);
  
    while (true){
        // pick a message randomly
        int randInt = rand() % (argc - 1);
        std::string randMessage = messages.at(randInt);
        
        // write to Log
        logger1.write(randMessage);
        
        // sleeping 
        sleep(5);
    }
    return 0;

}
