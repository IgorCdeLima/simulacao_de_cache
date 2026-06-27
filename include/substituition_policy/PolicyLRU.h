#ifndef POLICYLRU_H
#define POLICYLRU_H

    #include "IReplacementPolicy.h"

    class PolicyLRU : public IReplacementPolicy
    {
    private:
        /* data */
    public:
        PolicyLRU(/* args */);
        ~PolicyLRU();

        int getLineToReplace(const std::vector<LinhaCache>& set) override;
    };
    
#endif