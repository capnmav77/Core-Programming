#include <iostream>
#include <type_traits>

// Compares types without removing const
template <typename TFirst, typename TSecond>
void FuncA(TFirst& A, TSecond& B) 
{
  using namespace std;
  if constexpr (is_same_v<TFirst, TSecond>) 
  {
    cout << "FuncA: Types are the same\n";
  } 
  else 
  {
    cout << "FuncA: Types are not the same\n";
  }
}

// Removes const, then compares types
template <typename TFirst, typename TSecond>
void FuncB(TFirst& A, TSecond& B) 
{
  using namespace std;
  if constexpr (is_same_v<
                    remove_const_t<TFirst>,
                    remove_const_t<TSecond>>) 
  {
    cout << "\nFuncB: Types are the same";
  } 
  else 
  {
    cout << "\nFuncB: Types are not the same";
  }
}

int main(void) 
{
  int x{1};
  const int y{2};

  FuncA(x, x);
  FuncA(x, y);

  FuncB(x, x);
  FuncB(x, y);
  return 0;
}