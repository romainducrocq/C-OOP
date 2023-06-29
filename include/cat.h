#ifndef _CAT_H
#define _CAT_H

#include "animal.h"

/* define cat child class */
typedef struct cat {
    animal* super;
    struct cat_vt* vt;

    int _weight; /* _ for private */
} cat;

/* define cat vtable */
typedef struct cat_vt {
    cat* (*ctor)(const char*, int);
    void (*dtor)(cat*);
    int (*getWeight)();
} cat_vt;

/* global instance of vtable */
extern const cat_vt Cat;

#endif