    #include <iostream>
    #include <unordered_set>
    using namespace std;

    int main()
    {
        // declaring unordered set 
        unordered_set <char> set1 ;

        // declaring an iterator
        unordered_set<char> :: iterator itr;

        // inserting elements to the set
        set1.insert('c');
        set1.insert('o');
        set1.insert('d');
        set1.insert('i');
        set1.insert('n');
        set1.insert('g');

        // finding letter 's' in the set
        char key_to_find = 's' ;

        if (set1.find(key_to_find) == set1.end())
        {
            cout << "The key '" << key_to_find 
                 << "' is not present in set1" << endl << endl ;
        }
        else
        {
            cout << "The key '" << key_to_find 
                 << "' is present in set1" << endl << endl ;
        }

        // finding letter 'o' in the set
        key_to_find = 'o';
        if (set1.find(key_to_find) == set1.end())
        {
            cout << "The key '" << key_to_find 
                 << "' is not present in set1" << endl << endl ;
        }
        else
        {
            cout << "The key '" << key_to_find 
                 << "' is present in set1" << endl << endl ;
        }

        // printing all elements of the unordered set
        cout << "All elements of the unordered set: " << endl;

        for (itr = set1.begin(); itr != set1.end(); itr++)
        {
            cout << (*itr) << endl;
        }
        
        return 0;
    }
