#include <type_traits>
#include <iostream>

class Actor {};
class Monster : Actor {};

template <typename T>
void Function(T Param) 
{
  using namespace std;
  if constexpr (is_pointer_v<T>) 
  {
    cout << "\nType is a pointer";
  }

  if constexpr (is_class_v<T>) 
  {
    cout << "\nType is a class";
  }

  if constexpr (is_same_v<Actor, T>) 
  {
    cout << ": Actor";
  } 
  else if constexpr (is_base_of_v<Actor, T>) 
  {
    cout << ": Actor (or derived from Actor)";
  }
}

int main(void) 
{
  int x{5};
  Function(&x);

  Actor MyActor;
  Function(MyActor);

  Monster MyMonster;
  Function(MyMonster);

  return 0;
}