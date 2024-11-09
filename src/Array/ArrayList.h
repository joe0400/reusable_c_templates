#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "../utils/templateUtils.h"
#include "../common/CollectionFunctions.h"

#define ArrayList(Type) concat(ArrayList,Type)
#define GenerateArrayList(Type, DestructorFunction)\
typedef struct {\
    Type* arraydata;\
    unsigned long int size_;\
    unsigned long int capc_;\
} ArrayList(Type);\
\
ArrayList(Type) constructor(ArrayList(Type))(unsigned int capacity){\
    if(capacity == 0){\
        capacity = 16;\
    }\
    ArrayList(Type) data;\
    data.capc_ = capacity;\
    data.size_ = 0;\
    data.arraydata = malloc(sizeof(Type) * data.capc_);\
    return data;\
}\
ArrayList(Type) destructor(ArrayList(Type))(ArrayList(Type)* ptr){\
    if(ptr == NULL){\
        return;\
    }\
    free(ptr->arraydata);\
    ptr->arraydata = NULL;\
    ptr->capc_ = ptr->size_ = 0;\
    return *ptr;\
}\
unsigned long long int capacity(ArrayList(Type))(ArrayList(Type)* ptr){\
    return ptr == NULL ? 0 : ptr->capc_;\
}\
unsigned long long int size(ArrayList(Type))(ArrayList(Type)* ptr){\
    return ptr == NULL ? 0 : ptr->size_;\
}\
void push_back(ArrayList(Type))(ArrayList(Type)* ptr, Type value){\
    if(ptr == NULL) return;\
    if(ptr->capc_ <= ptr->size_) ptr->array = realloc(ptr->array, (ptr->capc_ *= 2) * sizeof(Type) );\
    ptr->array[ptr->size++] = value;\
}\
Optional(Type) pop_back(ArrayList(Type))(ArrayList(Type)* ptr, Type value){\
    if(ptr == NULL || ptr->arraydata == NULL || ptr->size_ == 0){\
        Optional(Type) data;\
        data.has_data = false;\
        return data;\
    }\
    Optional(Type) data;\
    data.has_data = true;\
    data.values.argument = ptr->arraydata[--ptr->size_];\
}\
Optional(Type) back(ArrayList(Type))(ArrayList(Type)* ptr, Type value){\
    Optional(Type) data;\
    data.has_data = !(ptr == NULL || ptr->arraydata == NULL || ptr->size_ == 0);\
    if(!data.has_data){\
        return data;\
    }\
    data.values.argument = ptr->arraydata[ptr->size_-1];\
    return data;\
}\
Optional(Type) front(ArrayList(Type))(ArrayList(Type)* ptr){\
    Optional(Type) data;\
    if(!(data.has_data = !(ptr == NULL || ptr->arraydata == NULL || ptr->size_ == 0))){\
        return data;\
    }\
    data.values.argument = ptr->arraydata[0];\
    return data;\
}\
void push_front(ArrayList(Type))(ArrayList(Type)* ptr, Type value){\
    if(ptr == NULL || ptr->arraydata == NULL) return;\
    if(ptr->size_ >= ptr->capc_) ptr->array = realloc(ptr->array, (ptr->capc_ *= 2) * sizeof(Type));\
    for(unsigned long long int i = ptr->size_; i > 0;i--){\
        ptr->arraydata[i] = ptr->arraydata[i - 1];\
    }\
    ptr->arraydata[0] = value;\
}\
typedef concat(Type,Ptr) Type*;\
concat(Type,Ptr) at(ArrayList(Type))(ArrayList(Type)* ptr, unsigned long long int i){\
    if(ptr == NULL) return NULL;\
    if(ptr->arraydata == NULL) return NULL;\
    if(ptr->size_ <= i) return NULL;\
    return ptr->arraydata[ptr->size_];\
}



#endif // ARRAYLIST_H