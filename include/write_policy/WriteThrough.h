#ifndef WRITETHROUGH_H
#define WRITETHROUGH_H
    #include "IWritePolicy.h"

    class WriteThrough : public IWritePolicy
    {
    private:
        /* data */
    public:
        WriteThrough(/* args */);
        ~WriteThrough();
        bool allocateOnWriteMiss()override;
        void processWrite(LinhaCache &line) override;
        bool shouldWriteMainMemory(LinhaCache &line) override;
        
    };
    

    

#endif