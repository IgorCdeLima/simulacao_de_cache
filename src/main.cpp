#include "commandLine.h"
#include "CacheMemoryConfiguration.h"
#include "CacheMemory.h"

commandLine& lineOfCommandTratament = commandLine::getInstance();
CacheMemoryConfiguration& config = CacheMemoryConfiguration::getInstance();
CacheMemory memoryCache;

int main(int argc, char *argv[]){
    lineOfCommandTratament.argumentsForClass(argc, argv);
    config.defineArgumetnsParamns(
        lineOfCommandTratament.getEntryPolicy(),
        lineOfCommandTratament.getSizeLine(),
        lineOfCommandTratament.getNumberLines(),
        lineOfCommandTratament.getAssociability(),
        lineOfCommandTratament.getAccessTimePerHit(),
        lineOfCommandTratament.getSubstituitionPolicy(),
        lineOfCommandTratament.getTimeToReadWrite()
    );
    config.printInformations();
    memoryCache.interprectAddress("0020a858 R");
    return 0;
}