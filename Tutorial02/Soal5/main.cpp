#include "Pokemon.hpp"
#include "GrassPokemon.hpp"
#include "FirePokemon.hpp"
#include "WaterPokemon.hpp"
#include "memory"

int main()
{
  FirePokemon* f1 = new FirePokemon("Charmander",100, 20);
  FirePokemon f2(*f1);
  WaterPokemon* w1 = new WaterPokemon("Squirtle", 100, 20, 10);
  w1->heal(10);
  WaterPokemon m2("Magikarp", 100, 20, 0);
  m2 = *w1;
  w1->attack(*f1);
  w1->attack(*f1);

  return 0;
}