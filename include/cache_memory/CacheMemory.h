#ifndef CACHEMEMORY_H
#define CACHEMEMORY_H

    #include "Tools.h"
    #include "CacheMemoryConfiguration.h"


    class CacheMemory
    {
    private:
        Tools tools;
        CacheMemoryConfiguration& config = CacheMemoryConfiguration::getInstance();
        std::vector<LinhaCache> cacheMemory ;
    
    public:
        CacheMemory(/* args */);
        ~CacheMemory();

        void interprectAddress(std::string lineToInterpret);
    };
    
#endif //CACHEMEMORY_H