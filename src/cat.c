#include "cat.h"

#include <stdlib.h>

/* define cat functions */
static cat* cat_ctor(const char*, int);
static void cat_dtor(cat*);
static const char* cat_sound(); /* override */
static int cat_getWeight();

/* assign cat vtable */
const cat_vt Cat = {
    .ctor = cat_ctor,
    .dtor = cat_dtor,
    .getWeight = cat_getWeight /* only in child class */
};

/* implement cat functions */
static cat* cat_ctor(const char* name, int weight) {

    /* allocate this object */
    cat* this = malloc(sizeof(cat));

    /* call super constructor */
    this->super = Animal.ctor(name, cat_sound);

    /* allocate and copy vtable */
    this->vt = malloc(sizeof(cat_vt));
    *this->vt = Cat;

    /* initialize attributes */
    this->_weight = weight;

    return this;
}

static void cat_dtor(cat* this) {

    /* deallocate super */
    Animal.dtor(this->super);

    /* free this */
    free(this->vt);
    free(this);
}

static const char* cat_sound() {
    return "pasta";
}

static int cat_getWeight(cat* this) {
    return this->_weight;
}