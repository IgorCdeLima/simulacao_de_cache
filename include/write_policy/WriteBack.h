#ifndef WRITEBACK_H
#define WRITEBACK_H
    #include "IWritePolicy.h"
    #include "structs.h"

    class WriteBack : public IWritePolicy
    {
    private:
        /* data */
    public:
        WriteBack(/* args */);
        ~WriteBack();

        bool allocateOnWriteMiss() override;
        void processWrite(LinhaCache& line) override;
        bool shouldWriteMainMemory(LinhaCache& line)override;
    };
    

    


#endif