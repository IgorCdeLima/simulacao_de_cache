#include "TratamentString.h"

#define ADDRESS 0
#define OPERATION 1
#define CHARACTERTOOPREATION 0


TratamentString::TratamentString(/* args */)
{
}

TratamentString::~TratamentString()
{
}

LineInArquive TratamentString::split(const std::string& texto)
{
    std::stringstream ss(texto);
    std::string token;
    std::vector<std::string> resultado;

    while (ss >> token)
    {
        resultado.push_back(token);
    }

    LineInArquive AddressAndOperation;
    AddressAndOperation.address = addressToLine(resultado[ADDRESS]);
    AddressAndOperation.operation = resultado[OPERATION][CHARACTERTOOPREATION];

    return AddressAndOperation ;
}

uint32_t TratamentString::addressToLine(std::string data)
{
    return static_cast<uint32_t>(std::stoul(data, nullptr, 16));
}

std::string TratamentString::operationRorW(std::string charAccesType)
{
    return std::string(charAccesType);
}
