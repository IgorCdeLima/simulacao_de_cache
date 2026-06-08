#include <commandLine.h>
#include <stdio.h>
#include <string>


#define NUMBER_OF_ARGUMENTS  9
#define POSITION_NAME_APPLICATION 0
#define ENTRY_POLICE 1
#define SIZE_LINE 2
#define NUMBER_OF_LINES 3
#define ASSOCIABILITY 4
#define ACESS_TIME 5
#define SUBSTITUTION_POLICY 6
#define TIME_TO_READ_WRITE 7

// commandLine::commandLine(/* args */){}

void commandLine::argumentsForClass(int argc, char *argv[]){
    int positionToRealArguments;

    // if not have 8 arguments, return and inform the user how to use the correct command line
    if(argc != NUMBER_OF_ARGUMENTS ){
        printf("Usage: %s <entry_policy> <size_line> <number_of_lines> <associability> <access_time_per_hit> <substituition_policy> <time_to_read_write>\n", argv[POSITION_NAME_APPLICATION]);
        return;
    }

    // variables to receive arguments from command line
    int entryPolicy  = std::stoi(argv[ENTRY_POLICE]);
    int sizeLine = std::stoi(argv[SIZE_LINE]);
    int numberLines = std::stoi(argv[NUMBER_OF_LINES]);
    int associability = std::stoi(argv[ASSOCIABILITY]);
    int accessTimePerHit = std::stoi(argv[ACESS_TIME]);
    std::string substitutionPolicy = argv[SUBSTITUTION_POLICY];
    int timeToReadWrite = std::stoi(argv[TIME_TO_READ_WRITE]);
    

    // for(positionToRealArguments = 1; positionToRealArguments < argc; positionToRealArguments++ ){

    // }
}


commandLine::~commandLine()
{
}
