#ifndef READERARQUIVE_H
#define READERARQUIVE_H

    #include <fstream>
    #include <iostream>
    
    #include "TratamentString.h"
    #include "structs.h"


    class ReaderArquive
    {
    private:
        TratamentString tools;
        std::fstream arquive;
        std::string nameArquive;
        std::vector<LineInArquive> MemSecundaria;
        
    public:
        int SizeMemoriaSecundaria;

        ReaderArquive();
        ~ReaderArquive();
        void defineNameArquive(std::string name);
        void readArquive();
        void openArquive();
        void closeArquive();
        LineInArquive getMemSecundaria(int posLine);
    };
    
    
#endif
