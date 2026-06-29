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


void CacheMemoryConfiguration::defineArgumetnsParamns(
DataCM info
)
{
    setEntryPolicy(info.entryPolicy);
    setSizeLine(info.sizeLine);
    setNumberLines(info.numberLines);
    setAssociability(info.associability);
    setAccessTimePerHit(info.accessTimePerHit);
    setSubstituitionPolicy(info.substituitionPolicy);
    setTimeToReadWrite(info.timeToReadWrite);
    defineAddressFields();
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

void CacheMemoryConfiguration::setTotalSizeToCacheMemory()
{
    if (!numberLines) return;
    if (!sizeLine) return;

    int powerToMemoryCache = log2(numberLines) + log2(sizeLine);
    int powerSize = (powerToMemoryCache / POWER) * 10;

    totalSizetoCacheMemory = pow(BASEPOWER,powerToMemoryCache) / (pow(BASEPOWER, powerSize));
}

void CacheMemoryConfiguration::processWrite(LinhaCache &line)
{
    writePolicy->processWrite(line);
}



// FUNÇÕES GET

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

int CacheMemoryConfiguration:: getAssociability()
{
    return associability;
}
int CacheMemoryConfiguration::getNumberOfSets()
{
    return numberOfSets;
}

int CacheMemoryConfiguration::chooseLineToSubstitution(std::vector<LinhaCache> &line)
{
    return substituitionPolicy->getLineToReplace(line);
}

bool CacheMemoryConfiguration::allocateOnWriteMiss()
{
    return writePolicy->allocateOnWriteMiss();
}



informationsProgram CacheMemoryConfiguration::initialInformations()
{
    informationsProgram info;

    info.politicaDeEscrita = entryPolicy;
    info.tamanhoDoBloco = sizeLine;
    info.quantidadeDeblocos = numberLines;
    info.associabilidade = associability;
    info.tempoDeAcessoMedio = accessTimePerHit;
    info.politicaDeSubstituicao = substituitionPolicyString.c_str();
    info.tempoDeEscritaLeitura = timeToReadWrite;

    info.quantidadeDeConjuntos = numberOfSets;
    info.bitsConjunto = setsBits;
    info.bitsTag = tagBits;
    info.bitsPalavra = offsetBits;
    info.tamanhoDaCacheString = (getTotalSizeToCacheMemoryToString()).c_str();

    return info;

}


simulationCache CacheMemoryConfiguration::getStatistics()
{
    simulationCache result;
    result.numberOfBlocks = numberOfSets;
    result.hitRate = ((double)cacheHit /(cacheHit + cacheMiss)) * 100.0;
    double missRate = (double)cacheMiss / (cacheHit + cacheMiss);
    result.averageAccessTime = accessTimePerHit + (missRate * timeToReadWrite);
    result.memoryRead = memoryRead;
    result.memoryWrite = memoryWrite;
    result.writeOperation = writeOperation;
    result.readOperation = readOperation;
    result.totalOperation = writeOperation + readOperation;
    result.escritasCache = writeHit;
    result.leiturasCache = readHit;

    result.sizeBlock = sizeLine;
    result.writePolicy = (entryPolicy == 1) ? "Write-back" : "Write-through"; 
    result.substituitionPolicy = substituitionPolicyString;
    result.associability = associability;

    result.cacheSize = totalSizetoCacheMemory;
    
    return result;
}   



uint32_t CacheMemoryConfiguration::getOffsetBitsInterpretation(uint32_t address)
{
    return tools.offsetBitsInterpretation(
        address,
        offsetBits
    );
}

uint32_t CacheMemoryConfiguration::getSetBitsInterpretation(uint32_t address)
{
    return tools.setBitsInterpretation(
        address,
        offsetBits,
        setsBits  
    );
}
uint32_t CacheMemoryConfiguration::getTagBitsInterpretation(uint32_t address)
{

    return tools.tagBitsInterpretation(
        address,
        offsetBits,
        setsBits
    );
}

// FUNÇÔES DE ESCRITA

void CacheMemoryConfiguration::printInformation()
{
    tools.printInformationsInitials(initialInformations());
    tools.printTable(getStatistics());
}

void CacheMemoryConfiguration::printLine(std::string word, std::string variable)
{
    tools.printLine(word, variable);
}

