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
    #include "Tools.h"

    
    #define SIZEADDRESS 32 //address to bits

    class CacheMemoryConfiguration
    {
    private:
        
        Tools tools;


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

        int cacheHit = 0;
        int cacheMiss = 0;
        
        int memoryRead = 0;
        int memoryWrite = 0;
        
        int readHit = 0;
        int writeHit = 0;
        
        int writeOperation = 0;
        int readOperation = 0;
        
        int globalLRU = 0;
        
        // cacheMemory(/* args */);
        
        static CacheMemoryConfiguration& getInstance()
        {
            static CacheMemoryConfiguration instance;
            return instance;
        }
        ~CacheMemoryConfiguration();
        
        // class funtions
        
        void defineArgumetnsParamns( DataCM configurationStruct);
        int getAssociability();
        int getNumberOfSets();
        int chooseLineToSubstitution(std::vector<LinhaCache>& line);
        void processWrite(LinhaCache& line);
        bool allocateOnWriteMiss();
        
        informationsProgram initialInformations();
        simulationCache getStatistics();

        uint32_t getOffsetBitsInterpretation(uint32_t address);
        uint32_t getSetBitsInterpretation(uint32_t address);
        uint32_t getTagBitsInterpretation(uint32_t address);

        void printInformation();
        void printLine(std::string word, std::string variable);

    };
    

#endif //CACHEMEMORY_H