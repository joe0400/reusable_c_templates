#ifndef ARRAY_H
#define ARRAY_H

#include "../utils/templateUtils.h"
#include "../common/CollectionFunctions.h"

#define Array(Type, size)\
concat(array, concat(Type,size))

#define GenerateArrayConstruct(Type, Size)\
typedef Array(Type,Size) struct{\
    Type[Size] array_data;\
};\
Array(Type,Size) constructor(Array(Type,Size))(){\
	Array(Type,Size) data;\
	return data;\
}\
unsigned long long int size(Array(Type,Size))(Array(Type,Size)* ptr){\
	return Size;\
}\
unsigned long long int capacity(Array(Type,Size))(Array(Type,Size)* ptr){\
	return Size;\
}\
unsigned long long int length(Array(Type,Size))(Array(Type,Size)* ptr){\
	return Size;\
}\
Type* at(Array(Type,Size))(Array(Type,Size)* ptr, unsigned long long int i){\
	return i < Size ? ptr == NULL ? NULL : ptr->array_data + i : NULL;\
}\
Type* back(Array(Type,Size))(Array(Type,Size)* ptr){\
	return ptr == NULL ? NULL : ptr->array_data + Size - 1;\
}\
Type* front(Array(Type,Size))(Array(Type,Size)* ptr){\
	return ptr == NULL ? NULL : ptr->array_data;\
}\


// destructor is not defined for this
//
#endif // ARRAY_H
