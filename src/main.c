// https://stackoverflow.com/questions/2181079/object-oriented-programming-in-c
// https://stackoverflow.com/questions/8194250/polymorphism-in-c
// https://stackoverflow.com/questions/351733/how-would-one-write-object-oriented-code-in-c

#include "cat.h"
#include "dog.h"

#include <stdio.h>

int main(){

    /* new */
    cat* c = Cat.ctor("cat", 69);
    dog* d = Dog.ctor("dog", 420);

    printf("%s %s %i\n", c->super->name, c->super->vt->sound(), c->vt->getWeight(c));
    printf("%s %s %i\n", d->super->name, d->super->vt->sound(), d->vt->getHeight(d));

    /* delete */
    Cat.dtor(c);
    Dog.dtor(d);
}