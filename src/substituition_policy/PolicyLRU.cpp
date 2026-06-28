#include "PolicyLRU.h"

PolicyLRU::PolicyLRU(/* args */)
{
}

PolicyLRU::~PolicyLRU()
{
}

int PolicyLRU::getLineToReplace(const std::vector<LinhaCache> &set)
{
    int menor = 0;   
    for(size_t line = 1; line < set.size(); line++)
    {
        if(set[line].lru < set[menor].lru )
        {
            menor = line;
        }
    }
    return menor;
}
