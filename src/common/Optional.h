
#ifndef OPTIONAL_H
#define OPTIONAL_H

#include "CollectionFunctions.h"
#define Optional(Type) concat(Optioan,Type)

#define GenerateOptional(Type)\
typedef struct {\
    union {\
        char c;\
        Type argument;\
    } values;\
    bool has_data;\
};

#endif // OPTIONAL_H