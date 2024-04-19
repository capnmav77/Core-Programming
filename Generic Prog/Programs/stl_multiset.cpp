    #include <iostream>
    #include <set>

    using namespace std;

    int main()
    {
        // empty multiset container
        multiset<int> ms1;

        // insert elements in random order
        ms1.insert(40);
        ms1.insert(30);
        ms1.insert(20);
        ms1.insert(50);

        // 50 will be added twice to the set
        ms1.insert(50);

        // printing multiset ms1
        multiset<int>::iterator itr;
        cout << "The multiset ms1 is: " << endl;
        for (itr = ms1.begin(); itr != ms1.end(); itr++) 
        {
            cout << *itr << " ";
        }

        cout << endl << endl;

        // remove all elements up to the element with value 40 in ms1
        cout << "ms1 after removal of elements < 40: " << endl;
        ms1.erase(ms1.begin(), ms1.find(40));

        for (itr = ms1.begin(); itr != ms1.end(); itr++) 
        {
            cout << *itr << " ";
        }

        return 0;
    }
