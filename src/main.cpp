#include "commandLine.h"
#include "cacheMemoryConfiguration.h"

commandLine& lineOfCommandTratament = commandLine::getInstance();
cacheMemoryConfiguration& memoryCache = cacheMemoryConfiguration::getInstance();

int main(int argc, char *argv[]){
    lineOfCommandTratament.argumentsForClass(argc, argv);
    memoryCache.defineArgumetnsParamns(
        lineOfCommandTratament.getEntryPolicy(),
        lineOfCommandTratament.getSizeLine(),
        lineOfCommandTratament.getNumberLines(),
        lineOfCommandTratament.getAssociability(),
        lineOfCommandTratament.getAccessTimePerHit(),
        lineOfCommandTratament.getSubstituitionPolicy(),
        lineOfCommandTratament.getTimeToReadWrite()
    );
    memoryCache.defineAddressFields();
    memoryCache.printInformations();
    return 0;
}