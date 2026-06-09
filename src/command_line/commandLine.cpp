#include <commandLine.h>


#define NAME_OF_APPLICATION "simula_cache"
#define NUMBER_OF_ARGUMENTS  8
#define POSITION_NAME_APPLICATION 0
#define ENTRY_POLICE 1
#define SIZE_LINE 2
#define NUMBER_OF_LINES 3
#define ASSOCIABILITY 4
#define ACESS_TIME 5
#define SUBSTITUTION_POLICY 6
#define TIME_TO_READ_WRITE 7

#define POSSIBILITY_OF_NUMBER_ONE 1
#define NO_POSSIBILITY_OF_NUMBER_ONE 0

// commandLine::commandLine(/* args */){}

void commandLine::argumentsForClass(int argc, char *argv[]){
    int positionToRealArguments;

    // if not have 8 arguments, return and inform the user how to use the correct command line
    if(argc != NUMBER_OF_ARGUMENTS ){

        // correct commando line arguments
        printf("\nThe command is reqired:\n %s <entry_policy> <size_line> <number_of_lines> <associability> <access_time_per_hit> <substituition_policy> <time_to_read_write>\n\n", NAME_OF_APPLICATION);

        // information for parameters -help to simula_cache
        printf("\n[1] <entry_policy>: int type is required.  0 - write-through e 1 - write-back;\n[2] <size_line>: int type is requiered. A value that is a power of two is required. the Value 1 is not accepted\n[3] <number_of_lines>: int type is required. A value that is a power of two is required. the Value 1 is not accepted\n[4] <associability>: Number of lines per set.  int type is required. A value that is a power of two is required\n[5] <access_time_per_hit>: Access time per hit time. int type is required. This value is in nanoseconds\n[6] <substituition_policy>: string type is required. LRU (Least Recently Used) or RANDOM will  be accepted\n[7]  <time_to_read_write>: int type is required. This value is in nanoseconds");

        return;
    }
    
    try
    {
        // variables to receive arguments from command line
        int entryPolicy  = std::stoi(argv[ENTRY_POLICE]);
        printf("\n<entry_policy>: %d", entryPolicy);
        if(entryPolicy != 0 && entryPolicy != 1) error_message(("\nThe value <entry_policy>: "+ std::to_string(entryPolicy)+" not is accepted")); 

        int sizeLine = std::stoi(argv[SIZE_LINE]);
        printf("\n<size_line>: %d", sizeLine);
        if(sizeLine < 1  || checkNoPowerOfTwo(sizeLine, NO_POSSIBILITY_OF_NUMBER_ONE) ) error_message(("\nThe value <size_line>: "+std::to_string(sizeLine)+" is not accepted"));


        int numberLines = std::stoi(argv[NUMBER_OF_LINES]);
        printf("\n<number_of_lines>: %d", numberLines);
        if(numberLines < 1 || checkNoPowerOfTwo(numberLines, NO_POSSIBILITY_OF_NUMBER_ONE)) error_message(("\nThe value <associability>:"+ std::to_string(numberLines)+" not is accepted"));

        int associability = std::stoi(argv[ASSOCIABILITY]);
        printf("\n<associability>: %d", associability);
        if (associability <1 || associability > numberLines  ||  checkNoPowerOfTwo(associability, POSSIBILITY_OF_NUMBER_ONE)) error_message(("\nThe value "+std::to_string(associability)+" not is accepted"));

        int accessTimePerHit = std::stoi(argv[ACESS_TIME]);
        printf("\n<access_time_per_hit>: %d", accessTimePerHit);
        if ( accessTimePerHit<0) error_message(("\nThe value <access_time_per_hit>: "+std::to_string(accessTimePerHit)+" not is accepted"));

        std::string substitutionPolicy = argv[SUBSTITUTION_POLICY];
        printf("\n<substituition_policy>:%s", substitutionPolicy.c_str());
        if (substitutionPolicy != "LRU" && substitutionPolicy != "RANDOM") error_message(("\nThe value <substituition_policy>: "+ substitutionPolicy+" not is LRU or RANDOM" ));

        int timeToReadWrite = std::stoi(argv[TIME_TO_READ_WRITE]);
        printf("\n<time_to_read_write>: %d", timeToReadWrite);
        if (timeToReadWrite < 0 || timeToReadWrite == NULL ) error_message(("\nThe value <time_to_read_write>: "+std::to_string(timeToReadWrite)+" not is accepted" ));


        // chamada da classe correspondente a memória cache; é preciso desenvolver ela ainda
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool commandLine::checkNoPowerOfTwo(int number, bool possibility_to_number_one){
    
    if (possibility_to_number_one){
        if(number == 1) return 0;
    }
    if(number % 2 == 0) return 0;
    printf("\n The Value not is Power of two");
    return 1;
}

void commandLine::error_message(std::string msg){

    throw std::runtime_error(msg);
} 

commandLine::~commandLine()
{
}
