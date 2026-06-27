#ifndef POLICYRANDOM_H
#define POLICYRANDOM_H
    #include "IReplacementPolicy.h"

    class PolicyRandom : public IReplacementPolicy
    {
    private:
        /* data */
    public:
        PolicyRandom(/* args */);
        ~PolicyRandom();

        int getLineToReplace(
                const std::vector<LinhaCache>& set
            ) override;
    };

#endif