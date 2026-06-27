#include "PolicyRandom.h"


PolicyRandom::PolicyRandom(/* args */)
{
}

PolicyRandom::~PolicyRandom()
{
}

int PolicyRandom::getLineToReplace(const std::vector<LinhaCache> &set)
{
    return rand() % set.size();
}
