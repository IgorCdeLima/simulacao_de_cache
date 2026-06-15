#include "CacheMemory.h"

#define ADDRESS 0
#define OPERATION 1
#define CHARACTERTOOPREATION 0

CacheMemory::CacheMemory(/* args */){}

CacheMemory::~CacheMemory(){}


//Trabalhar melhor essa função, essa parte inicial pode ser interessante manter ela em uma função de utilizadade, assim como a função de split()
void CacheMemory::interprectAddress(std::string lineToInterpret)
{
    MemoryAccess newData;

    int offsetBits = config.getOffSetBits();
    int setBits = config.getSetBits();
    int tagBits = config.getTagBits(); 
    

    auto addressAndOperation = tools.split(lineToInterpret);

    uint32_t address =  tools.addressToLine(addressAndOperation[ADDRESS]);

    newData.address.offset = tools.offsetBitsInterpretation(address, offsetBits );
    newData.address.set = tools.setBitsInterpretation(address, offsetBits, setBits);
    newData.address.tag = tools.tagBitsInterpretation(address, offsetBits, setBits);
    newData.operation = tools.operationRorW(addressAndOperation[OPERATION])[CHARACTERTOOPREATION];

    tools.imprimir(newData, tagBits, setBits, offsetBits);


}