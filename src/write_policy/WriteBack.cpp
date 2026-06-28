#include "WriteBack.h"

WriteBack::WriteBack(/* args */)
{
}

WriteBack::~WriteBack()
{
}

bool WriteBack::allocateOnWriteMiss()
{
    return true;
}

void WriteBack::processWrite(LinhaCache &line)
{
    line.dirty = 1;
}

bool WriteBack::shouldWriteMainMemory(LinhaCache &line)
{
    return line.dirty;
}