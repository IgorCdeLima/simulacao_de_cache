#ifndef TOOLS_H
#define TOOLS_H

    #include <iostream>
    #include <bitset>
    #include "structs.h"
    #include <iomanip>

    #define REPET 100

    class Tools
    {
    private:
        /* data */
    public:
        Tools(/* args */);
        ~Tools();

        void printLine(std::string mensagem, std::string variable);
        void printHexString(std::string mensagem, uint32_t variable);
        uint32_t offsetBitsInterpretation(uint32_t address, int offsetBits);
        uint32_t setBitsInterpretation(uint32_t address,int offsetBits, int setBits);
        uint32_t tagBitsInterpretation(uint32_t address, int offsetBits, int setBits);
        void imprimir(MemoryAccess data, int tag, int set, int offset);
        std::string toBinary(uint32_t value, int numberBits);
        void cabecalho();
        void printTable(simulationCache data);
        void printInformationsInitials(informationsProgram info);
    };



#endif //TOOLS_H