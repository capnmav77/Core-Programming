#include <iostream>

template <typename T> void myFriendFunction(T);
template <typename U> class MyFriend;


class GrantingFriendshipAsClass {

  friend void myFriendFunction<>(int);             // (1)
  friend class MyFriend<int>;                      // (2)

private:
  std::string secret{"Secret from GrantingFriendshipAsClass."};

};

template <typename T>
class GrantingFriendshipAsClassTemplate {

  friend void myFriendFunction<>(int);
  friend class MyFriend<int>;
  friend class MyFriend<T>;                        // (3)

private:
  std::string secret{"Secret from GrantingFriendshipAsClassTemplate."};

};

template <typename T>
void myFriendFunction(T) {
  GrantingFriendshipAsClass myFriend;
  std::cout << myFriend.secret << '\n';             // (4)

  GrantingFriendshipAsClassTemplate<T> myFriend1;
  std::cout << myFriend1.secret << '\n';            // (5)
}

template <typename T>                               // (6)
class MyFriend {                      
public:
  MyFriend() {
    GrantingFriendshipAsClass myFriend;                 
    std::cout << myFriend.secret << '\n';

    GrantingFriendshipAsClassTemplate<int> myFriendInt;  
    std::cout << myFriendInt.secret << '\n';

    GrantingFriendshipAsClassTemplate<T> myFriendT;      
    std::cout << myFriendT.secret << '\n';
  }
};

int main() {

  std::cout << '\n';

  int a{2011};
  myFriendFunction(a);                                    

  MyFriend<int> myFriend;                                 

  std::cout << '\n';

}