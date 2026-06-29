#ifndef STRUCTS_H
#define STRUCTS_H

    #include <string>
    #include <cstdint>

    struct InfoAddress{
        uint32_t tag;
        uint32_t set;
        uint32_t offset;
    };

    struct LinhaCache{
        int tag = -1; // rotulo
        int dirty = 0;
        int lru = -1;
    };

    struct MemoryAccess {
        char operation;
        InfoAddress address;
    };
    
    struct LineInArquive
    {
        char operation;
        uint32_t address;
    };

    struct DataCM
    {
        int entryPolicy;
        int sizeLine;
        int numberLines;
        int associability;
        int accessTimePerHit;
        std::string substituitionPolicy;
        int timeToReadWrite;
    };

    struct HitLineInSet
    {
        bool hit = false;
        int lineInSet = 0;
    };

    struct simulationCache
    {
        int sizeBlock;
        std::string writePolicy;
        std::string substituitionPolicy;
        int associability;

        int numberOfBlocks;
        double hitRate;
        double averageAccessTime;
        int memoryRead;
        int memoryWrite;
        int writeOperation;
        int readOperation;
        int totalOperation;
        int leiturasCache;
        int escritasCache;
        int cacheSize;
    };


    struct informationsProgram
    {
        int politicaDeEscrita;
        int tamanhoDoBloco;
        int quantidadeDeblocos;
        int associabilidade;
        int tempoDeAcessoMedio;
        std::string politicaDeSubstituicao;
        int tempoDeEscritaLeitura;

        int quantidadeDeConjuntos;
        int bitsConjunto;
        int bitsTag;
        int bitsPalavra;
        std::string tamanhoDaCacheString;

    };

#endif //STRUCTS_H