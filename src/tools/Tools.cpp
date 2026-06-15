#include "Tools.h"


Tools::Tools(/* args */)
{
}

Tools::~Tools()
{
}

std::vector<std::string> Tools::split(const std::string& texto)
{
    std::stringstream ss(texto);
    std::string token;
    std::vector<std::string> resultado;

    while (ss >> token)
    {
        resultado.push_back(token);
    }
    return resultado;
}

uint32_t Tools::addressToLine(std::string data)
{
    return static_cast<uint32_t>(std::stoul(data, nullptr, 16));
}

std::string Tools::operationRorW(std::string charAccesType)
{
    return std::string(charAccesType);
}

void Tools::printInformation(std::string mensagem, std::string variable)
{
    std::cout 
        << mensagem
        << variable
        << "\n";
}

void Tools::printHexString(std::string mensagem, uint32_t variable)
{
    std::cout
    << mensagem
    <<"0x"
    << std::hex
    << std::setw(8)
    << std::setfill('0')
    << variable
    << "\n";

}

uint32_t Tools::offsetBitsInterpretation(uint32_t address, int offsetBits)
{
    uint32_t mask  = (1 << offsetBits) -1;
    return  address & mask;
}

uint32_t Tools::setBitsInterpretation(uint32_t address,int offsetBits, int setBits)
{
    uint32_t maskOffset = (address >>offsetBits);
    uint32_t maskSet = (1U << setBits)-1;
    return maskOffset & maskSet;
}

uint32_t Tools::tagBitsInterpretation(uint32_t address, int offsetBits, int setBits)
{
    uint32_t mask = address>>(offsetBits + setBits);
    return mask;
}


void Tools::imprimir(MemoryAccess data,  int tagBits, int setBits, int offsetBits)
{
    std::cout
        << "OPERATION"
        << "\t\t"
        << "TAG"
        << "\t\t"
        << "SET"
        << "\t\t"
        << "OFFSET"
        <<"\n";


    std::cout
    << data.operation
    << "\t\t\t"
    << toBinary(data.address.tag, tagBits)
    << "\t"
    << toBinary(data.address.set, setBits)
    << "\t"
    << toBinary(data.address.offset, offsetBits)
    << "\n";
}

std::string Tools::toBinary(uint32_t value, int numberBits)
{
    return std::bitset<32>(value)
        .to_string()
        .substr(32 - numberBits);
}