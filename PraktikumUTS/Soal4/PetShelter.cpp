#include "PetShelter.hpp"

template<typename T>
PetShelter<T>::PetShelter(std::string shelterName)
/* Default constructor:
    * - Creates a shelter with the given name.
    * - Default capacity: 8 dogs, 12 cats.
    * - No pets in the shelter initially.
    */
{
    this->shelterName = shelterName;
    this->dogCapacity = 8;
    this->catCapacity = 12;
    this->petCount = 0;
    this->currentCats = 0;
    this->currentDogs = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
        pets[i] = nullptr;  
    }
}

template<typename T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity)
/* Constructor with specified capacities:
    * - Creates a shelter with custom capacities for dogs and cats.
    * - If total capacity exceeds MAX_SHELTER_CAPACITY, prints:
    *   "The total capacity you construct is <total>, meanwhile the shelter capacity is 20"
    */
{
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    this->petCount = 0;
    this->currentCats = 0;
    this->currentDogs = 0;

    int totalCap = this->dogCapacity + this->catCapacity;
    if (totalCap > MAX_SHELTER_CAPACITY){
        std::cout << "The total capacity you construct is " << totalCap << ", meanwhile the shelter capacity is 20" << std::endl;
    }

    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
        pets[i] = nullptr;  
    }
}

template<typename T>
PetShelter<T>::~PetShelter()
/* Destructor:
    * - Cleans up all dynamically allocated pets.
    * - Sets pet pointers to nullptr after deletion.
    */
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i){
        delete pets[i];
        pets[i] = nullptr;
    }
}

template<typename T>
std::string PetShelter<T>::getShelterName() const
/* Returns the name of the shelter.
    * Output: Shelter name as a string.
    */
{
    return shelterName;
}

template<typename T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo)
/* Adds a pet to the shelter.
* Input:
* - petName: Name of the pet.
* - age: Age of the pet in years.
* - isDog: If true, adds a dog; if false, adds a cat.
* - extraInfo: For dogs, this is the breed; for cats, this is the color.
*
* Process:
* - If shelter is full, prints "Error: Shelter is at full capacity!".
* - If dog capacity is full, prints "Error: No space for more dogs!".
* - If cat capacity is full, prints "Error: No space for more cats!".
*
* - If addition is successful, system will create a **unique pet ID** based on pet type:
*   - If dog, ID will be "D" followed by the dog's sequential number. Ex: "D1", "D2", etc.
*   - If cat, ID will be "C" followed by the cat's sequential number. Ex: "C1", "C2", etc.
*
* - If addition is successful, prints:
*   "Success: <petName> has been added as a <Dog/Cat>! Pet ID: <petID>"
*/
{
    // Checking capacities
    if (petCount >= MAX_SHELTER_CAPACITY){
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }

    // Addition
    std::string petID;
    if (isDog){
        if (currentDogs >= dogCapacity){
            std::cout << "Error: No space for more dogs!" << std::endl;
            return;
        }

        petID = "D" + std::to_string(currentDogs + 1);

        for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
            if (pets[i] == nullptr) {
                pets[i] = new Dog(petName, age, extraInfo);
                pets[i]->setId(petID);
                currentDogs++;
                petCount++;
                std::cout << "Success: " << petName << " has been added as a Dog! Pet ID: " << petID << std::endl;
                return;
            }
        }
    } else {
        if (currentCats >= catCapacity){
            std::cout << "Error: No space for more cats!" << std::endl;
            return;
        }

        petID = "C" + std::to_string(currentCats + 1);

        for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
            if (pets[i] == nullptr) {
                pets[i] = new Cat(petName, age, extraInfo);
                pets[i]->setId(petID);
                currentCats++;
                petCount++;
                std::cout << "Success: " << petName << " has been added as a Cat! Pet ID: " << petID << std::endl;
                return;
            }
        }
    }
}

template<typename T>
T* PetShelter<T>::findPet(const std::string &petID) const
/* Checks if a pet with the given ID exists in the shelter.
    * Input:
    * - petID: ID of the pet to check.
    *
    * Output:
    * - If found, prints pet details using the displayInfo() method.
    * - If not found, prints "Pet ID is invalid!".
    * Note: Uses dynamic_cast to safely convert from Pet* to T* when returning.
    */
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] && pets[i]->getId() == petID){
            pets[i]->displayInfo();
            return dynamic_cast<T*>(pets[i]);
        }
    }

    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}

template<typename T>
void PetShelter<T>::listAllPets() const
/* Displays a list of all pets in the shelter.
    * Output:
    * - If no pets in the shelter, prints "No pets in the shelter yet!".
    * - If pets exist, prints in the format:
    *   "<number>. <pet.displayInfo()>"
    *
    * - Numbering in output starts from 1.
    */
{
    if (petCount == 0){
        std::cout << "No pets in the shelter yet!" << std::endl;
    } else {
        int index = 0;
        for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i){
            if (pets[i] != nullptr){
                std::cout << ++index << ". ";
                pets[i]->displayInfo();
            }
        }
    }
}

template<typename T>
int PetShelter<T>::calculateCost() const
/* Calculates total cost of maintaining all pets in the shelter.
    * - Dogs cost 75 per day.
    * - Cats cost 60 per day.
    * 
    * Output: Total daily maintenance cost as an integer.
    * Note: Uses dynamic_cast to determine the type of pet (Dog or Cat) 
    * to apply the correct maintenance cost.
    * Example:
    *   if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    */
{
    int cost =  0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] && dynamic_cast<Dog*>(pets[i])) { cost += 75; }
        else if (pets[i] && dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    }
    return cost;
}

template<typename T>
void PetShelter<T>::removePet(const std::string &petID)
/* Removes a pet with the given ID from the shelter.
    * Input:
    * - petID: ID of the pet to remove.
    *
    * Output:
    * - If found and removed, prints "<petName> has been removed from the shelter."
    * - If not found, prints "Pet ID is invalid!"
    * Note: Uses dynamic_cast to determine pet type when updating counters:
    *   if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
    */
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
        if (pets[i] && pets[i]->getId() == petID) {
            if (dynamic_cast<Dog*>(pets[i])) currentDogs--;
            else if (dynamic_cast<Cat*>(pets[i])) currentCats--;

            std::cout << pets[i]->getName() << " has been removed from the shelter." << std::endl;
            delete pets[i];
            pets[i] = nullptr;
            petCount--;

            return;
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
}

template class PetShelter<Pet>;