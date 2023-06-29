#include "dog.h"

#include <stdlib.h>

/* define dog functions */
static dog* dog_ctor(const char*, int);
static void dog_dtor(dog*);
static const char* dog_sound();
static int dog_getHeight();

/* assign dog vtable */
const dog_vt Dog = {
    .ctor = dog_ctor,
    .dtor = dog_dtor,
    .getHeight = dog_getHeight /* only in child class */
};

/* implement dog functions */
static dog* dog_ctor(const char* name, int height) {

    /* allocate this object */
    dog* this = malloc(sizeof(dog));

    /* call super constructor */
    this->super = Animal.ctor(name, dog_sound);

    /* allocate and copy vtable */
    this->vt = malloc(sizeof(dog_vt));
    *this->vt = Dog;

    /* initialize attributes */
    this->_height = height;

    return this;
}

static void dog_dtor(dog* this) {

    /* deallocate super */
    Animal.dtor(this->super);

    /* free this */
    free(this->vt);
    free(this);
}

static const char* dog_sound() {
    return "risotto";
}

static int dog_getHeight(dog* this) {
    return this->_height;
}