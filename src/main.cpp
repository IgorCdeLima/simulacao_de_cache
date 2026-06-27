#include "commandLine.h"
#include "CacheMemory.h"
#include "ReaderArquive.h"

commandLine& lineOfCommandTratament = commandLine::getInstance();
CacheMemory& memoryCache = CacheMemory::getInstance();

int main(int argc, char *argv[]){
    lineOfCommandTratament.argumentsForClass(argc, argv);
    memoryCache.initializeCacheMemory(
        lineOfCommandTratament.getEntryPolicy(),
        lineOfCommandTratament.getSizeLine(),
        lineOfCommandTratament.getNumberLines(),
        lineOfCommandTratament.getAssociability(),
        lineOfCommandTratament.getAccessTimePerHit(),
        lineOfCommandTratament.getSubstituitionPolicy(),
        lineOfCommandTratament.getTimeToReadWrite()
    );

    ReaderArquive reader;
    

    reader.defineNameArquive("./teste.cache");
    reader.readArquive();

    for(int i = 0; i < reader.SizeMemoriaSecundaria; i++)
    {
        memoryCache.Controller(reader.getMemSecundaria(i));
    }

    memoryCache.getStatistics();

    return 0;
}