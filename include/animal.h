#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <stddef.h>

/* define animal parent class */
typedef struct animal {
    struct animal_vt* vt;

    const char* name;
} animal;

/* define animal vtable */
typedef struct animal_vt {
    animal* (*ctor)(const char*,
                    const char* (*)());
    void (*dtor)(animal*);
    const char* (*sound)();
} animal_vt;

/* global instance of vtable */
extern const animal_vt Animal;

#endif