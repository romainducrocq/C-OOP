#ifndef _DOG_H
#define _DOG_H

#include "animal.h"

/* define dog child class */
typedef struct dog {
    animal* super;
    struct dog_vt* vt;

    int _height; /* _ for private */
} dog;

/* define dog vtable */
typedef struct dog_vt {
    dog* (*ctor)(const char*, int);
    void (*dtor)(dog*);
    int (*getHeight)();
} dog_vt;

/* global instance of vtable */
extern const dog_vt Dog;

#endif