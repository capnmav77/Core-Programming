    #include <iostream>
    #include <unordered_map>
    using namespace std;

    int main()
    {
        // Initialization of unordered multimap
        unordered_multimap<string, int> un_mmap(
            {{ "Apples", 4},
            { "Oranges", 6},
            { "Apples", 10},
            { "Mangoes", 7}
            });

        unordered_multimap<string, int>::iterator it;

        // printing the multimap
        cout << "The unordered multimap is -->" << endl;

        for (it = un_mmap.begin(); it != un_mmap.end(); it++)
        {
            cout << it->first << " : " << it->second << endl;
        }

        cout << endl;

        // find and return any pair, associated with key "Oranges"
        string key = "Oranges";

        it = un_mmap.find(key);

        if (it != un_mmap.end()) 
        {
            cout << "The key " << key << " is present in "
                 << "the unordered multimap." << endl;

            cout << "One of the value associated with " << key 
                 << " is " << it->second << endl << endl;
        }
        else
        {
            cout << "The key " << key << " is not present in "
                 << "the unordered multimap." << endl << endl;
        }

        // removing all elements with the key "Apples"
        un_mmap.erase("Apples");
        
        // printing the multimap
        cout << "After deletion of key Apples, multimap is ->" << endl;

        for (it = un_mmap.begin(); it != un_mmap.end(); it++)
        {
            cout << it->first << " : " << it->second << endl;
        }

        return 0;
    }

