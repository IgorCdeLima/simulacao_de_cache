#include "WriteThrough.h"

WriteThrough::WriteThrough(/* args */)
{
}

WriteThrough::~WriteThrough()
{
}


bool WriteThrough::allocateOnWriteMiss()
{
    return false;
}

void WriteThrough::processWrite(LinhaCache &line)
{
    line.dirty = 0;

}

bool WriteThrough::shouldWriteMainMemory(LinhaCache &line)
{
    return false;
}