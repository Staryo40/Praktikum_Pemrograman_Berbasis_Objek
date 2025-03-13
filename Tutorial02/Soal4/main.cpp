#include "Pokemon.hpp"
#include "GrassPokemon.hpp"
#include "FirePokemon.hpp"
#include "WaterPokemon.hpp"

int main()
{
  FirePokemon f1("Charmander");
  WaterPokemon w1("Squirtle", 100, 20, 10);


  w1.heal(10);
  w1.attack(f1);
  f1.attack(w1);
  w1.attack(f1);

  GrassPokemon g1("Bulbasaur", 100, 50, 20);

  w1.attack(g1);
  g1.attack(w1);


  return 0;
}