    #include <iostream>
    #include <map>

    using namespace std;

    int main()
    {
        // declaring an empty map container
        map<int, char> m1;

        map<int, char>::iterator itr;

        // insert elements
        m1.insert(pair<int, char>(1, 'c'));
        m1.insert(pair<int, char>(3, 'u'));
        m1.insert(pair<int, char>(4, 'n'));
        m1.insert(pair<int, char>(5, 't'));
        m1.insert(pair<int, char>(2, 'o'));


        // printing map gquiz1

        cout << "The map m1 is: " << endl;

        cout << "KEY  ->  VALUE" << endl;
        for (itr = m1.begin(); itr != m1.end(); ++itr)
        {
            cout << "  " << itr->first << "  ->  " 
                 << itr->second << endl;
        }

        cout << endl;

        // removeing the element with key = 4
        m1.erase(4);
        cout << "Map after executing m1.erase(4) is: " << endl;

        cout << "KEY  ->  VALUE" << endl;
        for (itr = m1.begin(); itr != m1.end(); ++itr)
        {
            cout << "  " << itr->first << "  ->  " 
                 << itr->second << endl;
        }

        return 0;
    }
