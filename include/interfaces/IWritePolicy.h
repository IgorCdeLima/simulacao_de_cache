#ifndef IWRITEPOLICY_H
#define IWRITEPOLICY_H
    #include "structs.h"

    class IWritePolicy
    {
    private:
        /* data */
    public:
        virtual bool allocateOnWriteMiss() = 0;
        virtual void processWrite(LinhaCache& Line)=0;
        virtual bool shouldWriteMainMemory(LinhaCache& Line)=0;
        
        virtual ~IWritePolicy() = default ;
    };
    

#endif