/*
 * This source file was generated by the Gradle 'init' task
 */

#include <iostream>
#include <stdlib.h>
#include "app.h"

std::string VirtualDockingSoftware::Greeter::greeting() {
    return std::string("Hello, World!");
}

int main () {
    VirtualDockingSoftware::Greeter greeter;
    std::cout << greeter.greeting() << std::endl;
    return 0;
}

