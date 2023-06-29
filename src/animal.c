#include "animal.h"

#include <stdlib.h>

/* define animal functions */
static animal* animal_ctor(const char*,
                           const char* (*)());
static void animal_dtor(animal*);

/* assign animal vtable */
const animal_vt Animal = {
    .ctor = animal_ctor,
    .dtor = animal_dtor,
    .sound = NULL /* pure virtual function */
};

/* implement animal functions */
static animal* animal_ctor(const char* name,
                           const char* (*sound)()) {

    /* allocate this object */
    animal* this = malloc(sizeof(animal));

    /* allocate and copy vtable */
    this->vt = malloc(sizeof(animal_vt));
    *this->vt = Animal;

    /* assign pure virtual function */
    this->vt->sound = sound;

    /* initialize attributes */
    this->name = name;

    return this;
}

static void animal_dtor(animal* this) {

    /* free this */
    free(this->vt);
    free(this);
}