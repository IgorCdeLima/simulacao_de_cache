#include "CacheMemoryConfiguration.h"
#include <cmath>

#define BASEPOWER 2
#define POWER 10

// cacheMemory::cacheMemory(/* args */)
// {
// }

CacheMemoryConfiguration::~CacheMemoryConfiguration(){}

void CacheMemoryConfiguration::setNumberOfSets(int numberOfLines, int associability)
{
    numberOfSets = numberOfLines / associability ;
}

void CacheMemoryConfiguration::setOffSetBits(int sizeLine)
{
    offsetBits = log2(sizeLine);
}

void CacheMemoryConfiguration::setConjuctsBits()
{
    if(!numberOfSets){
        printf("Error: No have number of Sets");
        return;
    }

    //melhorar esse erro futuramente
    setsBits = log2(numberOfSets);
}

void CacheMemoryConfiguration::setTagBits(){
    
    if(!setsBits) {
        printf("Error: no have setBits");
        return;
    }
    if(!offsetBits){
        printf("Error: no have offSetBits");
        return;
    }

    tagBits = SIZEADDRESS - setsBits - offsetBits;
}


void CacheMemoryConfiguration::setEntryPolicy(int entryPolicyVar){
    entryPolicy = entryPolicyVar;
    if(entryPolicy == 1)
    {
        writePolicy = std::make_unique<WriteBack>();
    }
    else if(entryPolicy == 0)
    {
        writePolicy = std::make_unique<WriteThrough>();
    }
}
void CacheMemoryConfiguration::setSizeLine(int sizeLineVar){
    sizeLine = sizeLineVar;
}
void CacheMemoryConfiguration::setNumberLines(int numberLinesVar){
    numberLines = numberLinesVar;
}
void CacheMemoryConfiguration::setAssociability(int associabilityVar){
    associability = associabilityVar;
}
void CacheMemoryConfiguration::setAccessTimePerHit(int accessTimePerHitVar){
    accessTimePerHit = accessTimePerHitVar;
}
void CacheMemoryConfiguration::setSubstituitionPolicy(std::string substituitionPolicyVar){
    substituitionPolicyString = substituitionPolicyVar;
    if(substituitionPolicyString == "LRU")
    {
        substituitionPolicy = std::make_unique<PolicyLRU>();
    }
    else if (substituitionPolicyString == "RANDOM")
    {
        substituitionPolicy = std::make_unique<PolicyRandom>();
    }

}
void CacheMemoryConfiguration::setTimeToReadWrite(int timeToReadWriteVar){
    timeToReadWrite = timeToReadWriteVar;
}

void CacheMemoryConfiguration::setTotalSizeToCacheMemory()
{
    if (!numberLines) return;
    if (!sizeLine) return;

    int powerToMemoryCache = log2(numberLines) + log2(sizeLine);
    int powerSize = (powerToMemoryCache / POWER) * 10;

    totalSizetoCacheMemory = pow(BASEPOWER,powerToMemoryCache) / (pow(BASEPOWER, powerSize));
}

std::string CacheMemoryConfiguration::getTotalSizeToCacheMemoryToString(){
    if (!numberLines) return "Error:<numberLines> not exist";
    if (!sizeLine) return "Error: <sizeLine> not exist";

    int powerToMemoryCache = log2(numberLines) + log2(sizeLine);
    int powerSize = powerToMemoryCache / POWER;

    switch (powerSize)
    {
    case 0:
        return std::to_string(totalSizetoCacheMemory) + " B" ; 
    case 1:
        return  std::to_string(totalSizetoCacheMemory) + " KB";
    case 2:
        return  std::to_string(totalSizetoCacheMemory) + " MB";
    case 3:
        return  std::to_string(totalSizetoCacheMemory) + " GB";
    case 4:
        return  std::to_string(totalSizetoCacheMemory) + " TB";
    default:
        float valueDefaultToTotalSizeCacheMemory = pow(BASEPOWER,powerToMemoryCache) / (pow(BASEPOWER, 40 ));
        return std::to_string( valueDefaultToTotalSizeCacheMemory) + " TB";
    }
}

void CacheMemoryConfiguration::defineAddressFields()
{
    if(!numberLines){
        printf("Error: No have Number of Lines");
        return;
    }
    if(!associability){
        printf("Error: No have associability");
        return;
    }
    if(!sizeLine){
        printf("Error: No have SizeLine");
        return;
    }

    setNumberOfSets(numberLines, associability);
    setOffSetBits(sizeLine);
    setConjuctsBits();
    setTagBits();
    setTotalSizeToCacheMemory();
}

void CacheMemoryConfiguration::defineArgumetnsParamns(
DataCM config
)
{
    setEntryPolicy(config.entryPolicy);
    setSizeLine(config.sizeLine);
    setNumberLines(config.numberLines);
    setAssociability(config.associability);
    setAccessTimePerHit(config.accessTimePerHit);
    setSubstituitionPolicy(config.substituitionPolicy);
    setTimeToReadWrite(config.timeToReadWrite);
    defineAddressFields();
}


void CacheMemoryConfiguration::printInformations()
{
    printf("\n<entry_policy>: %d", entryPolicy);
    printf("\n<size_line>: %d", sizeLine);
    printf("\n<number_of_lines>: %d", numberLines);
    printf("\n<associability>: %d", associability);
    printf("\n<access_time_per_hit>: %d", accessTimePerHit);
    printf("\n<substituition_policy>:%s", substituitionPolicyString.c_str());
    printf("\n<time_to_read_write>: %d", timeToReadWrite);
    printf("\n");
    for(int i = 0; i <51; i++){printf("-");}
    printf("\n[1] Number of Sets (quantidade de conjuntos): %d\n[2] Set offSet Bits (Bits da palavra): %d\n[3] Set bits (bits do conjunto): %d\n[4] Tag bits (Bits da Tag): %d\n[5] Total Size to Cache Memory: %s\n", numberOfSets, offsetBits, setsBits, tagBits, (getTotalSizeToCacheMemoryToString()).c_str());


}



int CacheMemoryConfiguration:: getEntryPolicy()
{
    return entryPolicy;
}
int CacheMemoryConfiguration::getSizeLine()
{
    return sizeLine;
}
int CacheMemoryConfiguration:: getNumberLines()
{
    return numberLines;
}
int CacheMemoryConfiguration:: getAssociability()
{
    return associability;
}
int CacheMemoryConfiguration:: getAccessTimePerHit()
{
    return accessTimePerHit;
}
std::string CacheMemoryConfiguration:: getSubstituitionPolicy()
{
    return substituitionPolicyString;
}
int CacheMemoryConfiguration::getTimeToReadWrite()
{
    return timeToReadWrite;
}
int CacheMemoryConfiguration:: getNumberOfSets()
{
    return numberOfSets;
}
int CacheMemoryConfiguration:: getOffSetBits()
{
    return offsetBits;
}
int CacheMemoryConfiguration:: getTagBits()
{
    return tagBits;
}
int CacheMemoryConfiguration:: getTotalSizeToCacheMemory()
{
    return totalSizetoCacheMemory;
}
int CacheMemoryConfiguration::getSetBits()
{
    return setsBits;
}

int CacheMemoryConfiguration::chooseLineToSubstitution(std::vector<LinhaCache> &line)
{
    return substituitionPolicy->getLineToReplace(line);
}
void CacheMemoryConfiguration::processWrite(LinhaCache &line)
{
    writePolicy->processWrite(line);
}
bool CacheMemoryConfiguration::allocateOnWriteMiss()
{
    return writePolicy->allocateOnWriteMiss();
}

simulationCache CacheMemoryConfiguration::getStatistics()
{
    simulationCache result;
    result.numberOfBlocks = getNumberOfSets();
    result.hitRate = ((double)cacheHit /(cacheHit + cacheMiss)) * 100.0;
    double missRate = (double)cacheMiss / (cacheHit + cacheMiss);
    result.averageAccessTime = accessTimePerHit + (missRate * timeToReadWrite);
    result.memoryRead = memoryRead;
    result.memoryWrite = memoryWrite;

    result.sizeBlock = sizeLine;
    result.writePolicy = (entryPolicy == 1) ? "Write-back" : "Write-through"; 
    result.substituitionPolicy = substituitionPolicyString;
    result.associability = associability;
    
    return result;
}   