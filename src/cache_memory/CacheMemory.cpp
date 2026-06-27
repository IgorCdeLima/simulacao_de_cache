#include "CacheMemory.h"

#define ADDRESS 0
#define OPERATION 1
#define CHARACTERTOOPREATION 0

// CacheMemory::CacheMemory(/* args */){}

CacheMemory::~CacheMemory(){}


//Trabalhar melhor essa função, essa parte inicial pode ser interessante manter ela em uma função de utilizadade, assim como a função de split()
MemoryAccess CacheMemory::interprectAddress(LineInArquive lineToInterpret)
{
    MemoryAccess newData;
    

    newData.address.offset = tools.offsetBitsInterpretation(
        lineToInterpret.address,
        config.getOffSetBits()
    );

    newData.address.set = tools.setBitsInterpretation(
        lineToInterpret.address,
        config.getOffSetBits(),
        config.getSetBits()
    );

    newData.address.tag = tools.tagBitsInterpretation(
        lineToInterpret.address,
        config.getOffSetBits(),
        config.getSetBits()
    );

    newData.operation = lineToInterpret.operation;


    // tools.imprimir(
    //     newData,
    //     config.getTagBits(),
    //     config.getSetBits(),
    //     config.getOffSetBits()
    // );

    return newData;
}


void CacheMemory::initializeCacheMemory(
    int entryPolicy,
    int sizeLine,
    int numberLines,
    int associability,
    int accessTimePerHit,
    std::string substituitionPolicy,
    int timeToReadWrite
)
{
    DataCM configurationStruct;
    configurationStruct.entryPolicy = entryPolicy;
    configurationStruct.sizeLine = sizeLine;
    configurationStruct.numberLines = numberLines;     
    configurationStruct.associability = associability;
    configurationStruct.accessTimePerHit = accessTimePerHit;
    configurationStruct.substituitionPolicy = substituitionPolicy;
    configurationStruct.timeToReadWrite = timeToReadWrite;
    config.defineArgumetnsParamns(configurationStruct);

    config.printInformations();

    cacheMemory = std::vector<std::vector<LinhaCache>>
    (
        config.getNumberOfSets(),
        std::vector<LinhaCache>
        (
            config.getAssociability()
        )
    );
}

HitLineInSet CacheMemory::isHit(uint32_t set, uint32_t tag)
{
    HitLineInSet result;
    int lineInSet = 0;
    int LineInSetSize = config.getAssociability();
    for(lineInSet = 0; lineInSet < LineInSetSize; lineInSet++)
    {
        if(cacheMemory[set][lineInSet].tag == tag)
        {
            result.hit = true;
            result.lineInSet = lineInSet;
            return result;
        }
    }
    return result;
}

void CacheMemory::insertLine(int lineInSet, uint32_t set, LinhaCache newLine)
{
    cacheMemory[set][lineInSet] = newLine;
}


void CacheMemory::Controller(LineInArquive lineToInterpret)
{
    MemoryAccess newAddress = interprectAddress(lineToInterpret);

    HitLineInSet hitResult = isHit(newAddress.address.set, newAddress.address.tag);

    LinhaCache newData = createLinhaCache(
        newAddress.address.tag,
        newAddress.operation
    );

    tools.printInformation("\n TAG:", std::to_string(newAddress.address.tag));

    if(hitResult.hit)
    {
        config.cacheHit++;

        if(newAddress.operation == 'W')
        {
            config.writeHit++;
            config.processWrite(cacheMemory[newAddress.address.set][hitResult.lineInSet]);
        }
        else{
            config.readHit++;
        }
        updateLRU(cacheMemory[newAddress.address.set][hitResult.lineInSet]);
    }
    else
    {
        config.cacheMiss++;
        
        if(newAddress.operation == 'R')
        {
            config.memoryRead++;
            int chooseLine = config.chooseLineToSubstitution(cacheMemory[newAddress.address.set]);
            insertLine( chooseLine, newAddress.address.set, newData);
        }
        else{
            tools.printInformation("\t ESCRITA", " ");
            if(config.allocateOnWriteMiss())
            {
                tools.printInformation("NA CACHE", "");
                config.memoryRead++;
                int chooseLine = config.chooseLineToSubstitution(cacheMemory[newAddress.address.set]);
                config.processWrite(newData);
                insertLine(chooseLine, newAddress.address.set, newData);
            }
            else
            {
                tools.printInformation("NA MP", "");
                config.memoryWrite++;
            }
        }
    }
}


LinhaCache CacheMemory::createLinhaCache(int tag, char operation)
{
    LinhaCache newLine;
    newLine.tag = tag;
    newLine.dirty = 0;
    newLine.lru = config.globalLRU++;
    return newLine; 
}

void CacheMemory::updateLRU(LinhaCache& line)
{
    line.lru = config.globalLRU++;
}

void CacheMemory::getStatistics()
{
    tools.printTable(config.getStatistics());
}