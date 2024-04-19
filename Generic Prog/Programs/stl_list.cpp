    // CPP program to show the implementation of List
    #include <iostream>
    #include <iterator>
    #include <list>

    using namespace std;

    int main()
    {
        // defining a list
        list<int> lst;

        // defining an iterator
        list<int>::iterator it;

        for (int i = 0; i < 7; i++) 
        {
            // adding element to the back
            lst.push_back(i * 3); 
        }

        // printing the list
        cout << "List (lst) is -> ";

        for (it = lst.begin(); it != lst.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        // printing the first and last elements of the list
        cout << "lst.front() -> " << lst.front() << endl;
        cout << "lst.back() -> " << lst.back() << endl;

        // reversing the list
        lst.reverse();

        cout << "lst.reverse() -> ";
        for (it = lst.begin(); it != lst.end(); ++it)
        {
            cout << *it << " ";
        }

        return 0;
    }

