#ifndef CACHEMEMORY_H
#define CACHEMEMORY_H

    #include "Tools.h"
    #include "CacheMemoryConfiguration.h"



    class CacheMemory
    {
    private:

   


        Tools tools;

        CacheMemoryConfiguration& config = CacheMemoryConfiguration::getInstance();

        CacheMemory() = default;
        CacheMemory(const CacheMemory&) = delete;
        CacheMemory& operator=(const CacheMemory) = delete;

        std::vector<std::vector<LinhaCache>> cacheMemory ;
        
        MemoryAccess interprectAddress(LineInArquive lineToInterpret);

        HitLineInSet isHit(uint32_t set, uint32_t tag);
        void insertLine(int lineInSet, uint32_t set, LinhaCache newLine);
        LinhaCache createLinhaCache(int tag, char operation);
        void updateLRU(LinhaCache& line);



    public:
        // CacheMemory(/* args */);
            
        ~CacheMemory();
        static CacheMemory& getInstance()
        {
            static CacheMemory instance;
            return instance;
        }
        
        void Controller(LineInArquive lineToInterpret);
        void initializeCacheMemory(
            int entryPolicy,
            int sizeLine,
            int numberLines,
            int associability,
            int accessTimePerHit,
            std::string substituitionPolicy,
            int timeToReadWrite
        );
        void getStatistics();
    };
    
#endif //CACHEMEMORY_H