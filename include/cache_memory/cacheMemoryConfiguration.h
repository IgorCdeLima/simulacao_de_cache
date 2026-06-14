#ifndef CACHEMEMORY_H
#define CACHEMEMORY_H

    #include <vector>
    #include <string>


    #define SIZEADDRESS 32 //address to bits

    struct LinhaCache{
        int rotulo;
        int dirty;
        int lru;
    };

    class cacheMemoryConfiguration
    {
    private:
        
        //class
        cacheMemoryConfiguration()  = default;
        cacheMemoryConfiguration(const cacheMemoryConfiguration&) = delete;
        cacheMemoryConfiguration& operator=(const cacheMemoryConfiguration) = delete;

        /*Configuration variables for Addres Fields */
        int numberOfSets;
        int offSetBits;
        int setsBits;
        int tagBits;
        int totalSizetoCacheMemory;
        
        void setNumberOfSets(int numberOfLines, int associability );
        void setOffSetBits(int sizeLines );
        void setSetsBits();
        void setTagBits();
        void setTotalSizeToCacheMemory();
        std::string getTotalSizeToCacheMemory();

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


    public:
        // cacheMemory(/* args */);

        static cacheMemoryConfiguration& getInstance()
        {
            static cacheMemoryConfiguration instance;
            return instance;
        }
        ~cacheMemoryConfiguration();

        // class funtions
        void defineAddressFields();
        void printInformations();
        void defineArgumetnsParamns( int entryPolicy, int sizeLine, int numberLines, int associability, int accessTimePerHit, std::string substituitionPolicy, int timeToReadWrite );
        
    };


#endif //CACHEMEMORY_H