//
//  log_generator.cpp
//  File Contents: main function that executes the Log Generator app
//
//  Created by Julia Groza on 2022-10-01.
//

#include "logger.h"
using namespace std;

// Function Name: signal_handlers
// Description: waits for signal and exits the waiting loop
// Parameter Descriptions: signal_num is a user input for what signal the user is waiting for
// Return Descriptions: none
void signal_handler(int signal_num)
{
    cout << "The interrupt signal is (" << signal_num
         << "). \n";
  
    // It terminates the  program
    exit(signal_num);
}

// Function Name: main
// Description: this runs the Log Generator app that writes to the table
// Parameter Descriptions: takes in user input in argv
// Return Descriptions: returns 0 when it ends
int main(int argc, char* argv[]){
    
    // create vector
    vector<std::string> messages;
    
    // push messages onto vector
    for (int i = 1; i < argc; i++)
        messages.push_back(argv[i]);
    
    // make sure the vector is correct
    std::cout << "Messages entered: " << std::endl;
    for (std::string i : messages)
        std::cout << i << std::endl;
    
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
