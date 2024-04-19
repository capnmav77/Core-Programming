    #include <iostream>
    #include <map>

    using namespace std;

    int main()
    {
        // empty multimap container
        multimap<int, int> m1; 

        multimap<int, int>::iterator itr;

        // insert elements
        m1.insert(pair<int, int>(25, 3));
        m1.insert(pair<int, int>(11, 4));
        m1.insert(pair<int, int>(51, 5));
        m1.insert(pair<int, int>(30, 6));
        m1.insert(pair<int, int>(51, 8));

        // printing multimap m1
        cout << "The multimap m1 is: " << endl;

        cout << "KEY  ->  VALUE" << endl;
        for (itr = m1.begin(); itr != m1.end(); itr++) 
        {
            cout << " " << itr->first << "  ->  " 
                 << itr->second << endl;
        }

        cout << endl;

        // removeing all elements up to key with value 30
        m1.erase(m1.begin(), m1.find(30));

        cout << "m1 after removal of elements < key = 30: " << endl;

        cout << "KEY  ->  VALUE" << endl;
        for (itr = m1.begin(); itr != m1.end(); itr++) 
        {
            cout << " " << itr->first << "  ->  " 
                 << itr->second << endl;
        }

        return 0;
    }

