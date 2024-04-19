#include <string>

template <typename T>
class GrantingFriendshipAsClassTemplate{

  template <typename T> friend void myFriendFunction(T);
  template <typename T> friend class MyFriend;

  std::string secret{"Secret from GrantingFriendshipAsClassTemplate."};

};
