#include <iostream>

template <typename T>                            // (1)
void myFriendFunction(T);

template <typename U>                            // (2)
class MyFriend;

class GrantingFriendshipAsClass {

  template <typename U> 
  friend void myFriendFunction(U);
  
  template <typename U> 
  friend class MyFriend;

  std::string secret{"Secret from GrantingFriendshipAsClass."};

};

template <typename T>
class GrantingFriendshipAsClassTemplate{

  template <typename U> 
  friend void myFriendFunction(U);
  template <typename U> 
  friend class MyFriend;

  std::string secret{"Secret from GrantingFriendshipAsClassTemplate."};

};

template <typename T>                                // (3)
void myFriendFunction(T){
  GrantingFriendshipAsClass myFriend;
  std::cout << myFriend.secret << '\n';

  GrantingFriendshipAsClassTemplate<double> myFriend1;
  std::cout << myFriend1.secret << '\n';
}

template <typename T>                              // (4)
class MyFriend{
public:
  MyFriend(){
    GrantingFriendshipAsClass myFriend;
    std::cout << myFriend.secret << '\n';

    GrantingFriendshipAsClassTemplate<T> myFriend1;
    std::cout << myFriend1.secret << '\n';
  }
};

int main(void)
{

  std::cout << '\n';

  int a{2011};
  myFriendFunction(a);

  MyFriend<double> myFriend;

  std::cout << '\n';
  return 0;

}