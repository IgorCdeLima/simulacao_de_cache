#ifndef CACHEMEMORYCONFIGURATION_H
#define CACHEMEMORYCONFIGURATION_H

    #include <vector>
    #include <string>


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
        std::string substituitionPolicy;
        int timeToReadWrite;
        
        void setEntryPolicy(int entryPolicyVar);
        void setSizeLine(int sizeLineVar);
        void setNumberLines(int numberLinesVar);
        void setAssociability(int associabilityVar);
        void setAccessTimePerHit(int accesstimePerHitVar);
        void setSubstituitionPolicy(std::string substituitionPolicyVar);
        void setTimeToReadWrite(int timetoReadWriteVar);
        void defineAddressFields();


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
        void defineArgumetnsParamns( int entryPolicy, int sizeLine, int numberLines, int associability, int accessTimePerHit, std::string substituitionPolicy, int timeToReadWrite );

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

    };


#endif //CACHEMEMORY_H