#ifndef TOOLS_H
#define TOOOLS_H

    #include <vector>
    #include <string>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <bitset>
    #include "structs.h"


    


    class Tools
    {
    private:
        /* data */
    public:
        Tools(/* args */);
        ~Tools();
        std::vector<std::string> split(const std::string& texto);
        uint32_t addressToLine(std::string data);
        std::string operationRorW(std::string charAccesType);
        void printInformation(std::string mensagem, std::string variable);
        void printHexString(std::string mensagem, uint32_t variable);
        uint32_t offsetBitsInterpretation(uint32_t address, int offsetBits);
        uint32_t setBitsInterpretation(uint32_t address,int offsetBits, int setBits);
        uint32_t tagBitsInterpretation(uint32_t address, int offsetBits, int setBits);
        void imprimir(MemoryAccess data, int tag, int set, int offset);
        std::string toBinary(uint32_t value, int numberBits);
    };



#endif //TOOLS_H