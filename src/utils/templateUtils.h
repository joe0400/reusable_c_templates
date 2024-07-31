
#ifndef TEMPLATE_UTILS_H
#define TEMPLATE_UTILS_H

#define _concat(a,b) a##_##b
#define concat(a,b) _concat(a,b)
#define constructor(type) concat(constructor,type)
#define destructor(type) concat(destructor,type)

#endif // TEMPLATE_UTILS_H
