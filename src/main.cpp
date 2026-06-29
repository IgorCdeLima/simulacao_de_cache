#include "commandLine.h"
#include "CacheMemory.h"
#include "ReaderArquive.h"

commandLine& lineCommand = commandLine::getInstance();
CacheMemory& memoryCache = CacheMemory::getInstance();

int main(int argc, char *argv[]){
    lineCommand.argumentsForClass(argc, argv);
    memoryCache.initializeCacheMemory(
        lineCommand.getEntryPolicy(),
        lineCommand.getSizeLine(),
        lineCommand.getNumberLines(),
        lineCommand.getAssociability(),
        lineCommand.getAccessTimePerHit(),
        lineCommand.getSubstituitionPolicy(),
        lineCommand.getTimeToReadWrite()
    );

    ReaderArquive reader;
    

    reader.defineNameArquive("./cache.cache");
    reader.readArquive();

    for(int line = 0; line < reader.SizeMemoriaSecundaria; line++)
    {
        memoryCache.Controller(reader.getMemSecundaria(line));
    }

    memoryCache.getStatistics();
    memoryCache.saveDataOnMP();

    return 0;
}