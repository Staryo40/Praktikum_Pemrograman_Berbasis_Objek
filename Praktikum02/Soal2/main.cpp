#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon *d1 = new Dragon("Draco");
    Creature& c1(*d1);
    d1->speak();

    d1->wound();
    d1->wound();

    d1->print();
    d1->speak();

    c1.wound();

    c1.print();
    d1->print();
    
    Creature c2(*d1);

    c2.speak();
    c2.wound();

    c2.print();
    d1->print();
    return 0;
}