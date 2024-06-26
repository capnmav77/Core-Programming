// Example for template template parameter used with class

#include <iostream>

template <typename T, template <typename, typename> class Cont > 
// the keyword class is a must before C++17, otherwise typename can also be used
class MyContainer
{
public:
  explicit MyContainer(std::initializer_list<T> inList): data(inList)
  {  
  }
  int getSize() const
  {
    return data.size();
  }


  void printCont()
  {
      for(const auto& d: data)
      {
          std::cout << d << ' ';
      }
      std::cout << '\n';
  }


private:
  Cont<T, std::allocator<T>> data; // the hidden default allocator in STL should be explicitly defined with the container to work with templates.                                                              


};


int main()
{
  MyContainer<int, std::vector> myIntVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
  std::cout << "myIntVec.getSize(): " << myIntVec.getSize() << std::endl;
  return EXIT_SUCCESS;
}
