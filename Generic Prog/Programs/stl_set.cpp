    #include <iostream>
    // #include <iterator>
    #include <set>

    using namespace std;

    int main()
    {
        // declaring empty set container
        set<int> s1;

        // declaring an iterator
        set<int>::iterator it;

        // insert elements in random order
        s1.insert(40);
        s1.insert(30);
        s1.insert(20);
        s1.insert(50);

        // trying to add 50 once again in the set
        s1.insert(50);

        // printing set s1
        cout << "The set s1 is -> ";
        for (it = s1.begin(); it != s1.end(); it++) 
        {
            cout << *it << " ";
        }
        cout << endl << endl;
        // output : 20 30 40 50


        // remove element with value 50 in s1
        s1.erase(50);

        cout << "Set s1 after uisng s1.erase(50) -> ";
        for (it = s1.begin(); it != s1.end(); it++) 
        {
            cout << *it << " ";
        }

        //output : 20 30 40

        return 0;
    }
