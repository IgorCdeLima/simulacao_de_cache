#ifndef CACHEMEMORYCONFIGURATION_H
#define CACHEMEMORYCONFIGURATION_H

    #include <vector>
    #include <string>
    #include "structs.h"
    #include <memory>
    #include "IReplacementPolicy.h"
    #include "PolicyLRU.h"
    #include "PolicyRandom.h"
    #include "WriteThrough.h"
    #include "WriteBack.h"
    #include "IWritePolicy.h"

    
    #define SIZEADDRESS 32 //address to bits

    class CacheMemoryConfiguration
    {
    private:
        


        //class
        CacheMemoryConfiguration()  = default;
        
        CacheMemoryConfiguration(const CacheMemoryConfiguration&) = delete;

        CacheMemoryConfiguration& operator=(const CacheMemoryConfiguration) = delete;

        /*Configuration variables for Addres Fields */
        int numberOfSets;
        int offsetBits;
        int setsBits;
        int tagBits;
        int totalSizetoCacheMemory;
        
        void setNumberOfSets(int numberOfLines, int associability );
        void setOffSetBits(int sizeLines );
        void setConjuctsBits();
        void setTagBits();
        void setTotalSizeToCacheMemory();
        std::string getTotalSizeToCacheMemoryToString();

        /*Configuration variables from arguments*/
        int entryPolicy;
        int sizeLine;
        int numberLines;
        int associability;
        int accessTimePerHit;
        std::string substituitionPolicyString;
        int timeToReadWrite;
        
        void setEntryPolicy(int entryPolicyVar);
        void setSizeLine(int sizeLineVar);
        void setNumberLines(int numberLinesVar);
        void setAssociability(int associabilityVar);
        void setAccessTimePerHit(int accesstimePerHitVar);
        void setSubstituitionPolicy(std::string substituitionPolicyVar);
        void setTimeToReadWrite(int timetoReadWriteVar);
        void defineAddressFields();


        std::unique_ptr<IReplacementPolicy> substituitionPolicy;
        std::unique_ptr<IWritePolicy> writePolicy;
        
        
        public:
        // cacheMemory(/* args */);
        
        static CacheMemoryConfiguration& getInstance()
        {
            static CacheMemoryConfiguration instance;
            return instance;
        }
        ~CacheMemoryConfiguration();
        
        // class funtions
        
        void printInformations();
        void defineArgumetnsParamns( DataCM configurationStruct);
        
        int getEntryPolicy();
        int getSizeLine();
        int getNumberLines();
        int getAssociability();
        int getAccessTimePerHit();
        std::string getSubstituitionPolicy();
        int getTimeToReadWrite();
        int getNumberOfSets();
        int getOffSetBits();
        int getSetBits();
        int getTagBits();
        int getTotalSizeToCacheMemory();
        int chooseLineToSubstitution(std::vector<LinhaCache>& line);
        void processWrite(LinhaCache& line);
        bool allocateOnWriteMiss();
        

        //preparar uma struct futuramente
        int cacheHit = 0;
        int cacheMiss = 0;

        int memoryRead = 0;
        int memoryWrite = 0;

        int readHit = 0;
        int writeHit = 0;

        int globalLRU = 0;

        simulationCache getStatistics();
    };
    

#endif //CACHEMEMORY_H