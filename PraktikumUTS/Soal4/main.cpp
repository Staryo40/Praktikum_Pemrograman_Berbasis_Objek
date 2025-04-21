#include <iostream>
#include <string>
#include "PetShelter.hpp"  // Assuming your class is defined here

int main() {
    PetShelter<Pet> shelter("Good Daycare");

    // Add some pets
    shelter.addPet("Buddy", 3, true, "Golden Retriever");  // D1
    shelter.addPet("Whiskers", 2, false, "White");         // C1
    shelter.addPet("Max", 4, true, "Labrador");            // D2
    shelter.addPet("Luna", 1, false, "Black");             // C2

    std::cout << "\n== Current Pets ==" << std::endl;
    shelter.listAllPets();  // Should show 4 pets: D1, C1, D2, C2

    // Remove a pet to create a gap
    shelter.removePet("D1");

    std::cout << "\n== After Removing D1 ==" << std::endl;
    shelter.listAllPets();  // Should show C1, D2, C2

    // Add another dog — should get D1 again (hole filled)
    shelter.addPet("Charlie", 5, true, "Beagle");  // Should get D1 again

    std::cout << "\n== After Adding Charlie ==" << std::endl;
    shelter.listAllPets();  // Should include Charlie with D1

    // Try to fill in more
    shelter.removePet("C1");  // Remove a cat
    shelter.addPet("Milo", 2, false, "Orange");    // Should get C1 again

    std::cout << "\n== After Removing C1 and Adding Milo ==" << std::endl;
    shelter.listAllPets();  // Milo should have C1

    return 0;
}
