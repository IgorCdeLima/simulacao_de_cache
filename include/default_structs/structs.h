#ifndef STRUCTS_H
#define STRUCTS_H

    #include <string>

    struct InfoAddress{
        uint32_t tag;
        uint32_t set;
        uint32_t offset;
    };

    struct LinhaCache{
        int tag; // rotulo
        int dirty;
        int lru;
    };

    struct MemoryAccess {
        char operation;
        InfoAddress address;
    };


#endif //STRUCTS_H