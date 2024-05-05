// To compile this, you need to define the C++ standard
// g++ --std=c++20 *.cpp

#include <concepts>

#include <concepts>

class Player {};
class Monster {};
class Goblin : public Monster {};

template <typename T>
  requires std::is_base_of_v<Player, T> ||
           std::is_base_of_v<Monster, T>
void Function(T Character) {}

int main(void) 
{
  Function(Goblin{});
  return 0;
}