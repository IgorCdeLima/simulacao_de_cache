#ifndef TRATAMENTSTRING_H
#define TRATAMENTSTRING_H

    #include "structs.h"
    #include <vector>
    #include <sstream>

    class TratamentString
    {
    private:
        /* data */
    public:
        TratamentString(/* args */);
        ~TratamentString();

        LineInArquive split(const std::string& texto);
        uint32_t addressToLine(std::string data);
        std::string operationRorW(std::string charAccesType);
    };
    


#endif