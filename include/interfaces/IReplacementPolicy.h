#ifndef IREPLACEMENTPOLICY_H
#define IREPLACEMENTPOLICY_H
    #include <vector>
    #include "structs.h"


    class IReplacementPolicy
    {
        public:
            virtual int getLineToReplace(
                const std::vector<LinhaCache>& set
            ) = 0;

            virtual ~IReplacementPolicy() = default;
    };

#endif //IREPLACEMENTPOLICY_H