#include <type_traits>
#include <iostream>

template <typename>
struct is_renderable : std::false_type {};

class Fish 
{
 public:
  void Render() 
  {
    std::cout << "Fish: ><((((`>";
  }
};

template <>
struct is_renderable<Fish> : std::true_type {};

class Sound {};

template <typename T>
void Function(T Param) 
{
  if (is_renderable<T>::value) 
  {
    Param.Render();
  } 
  else 
  {
    std::cout << "\nNot Renderable";
  }
}

int main() 
{
  Fish MyFish;
  Function(MyFish);

  Sound MySound;
  Function(MySound);
}