    #include <iostream>
    #include <unordered_set>

    using namespace std;

    int main()
    {
        // initialization of multiset
        unordered_multiset<int> ums1;

        unordered_multiset<int>::iterator it;

        // adding elements to the set
        ums1 = {12, 7, 12, 5, 0, 5};

        // inserting another element
        ums1.insert(5);

        // printing number of elements in the set
        cout << "The size of unordered multiset is: " 
             << ums1.size() << endl << endl;

        cout << "The unordered multiset is: " << endl;
        for (it = ums1.begin(); it != ums1.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl << endl;


        // counting the number of times the element 5 appears in set
        int val = 5;
        int count = ums1.count(val);

        cout << val << " appears " << count 
             << " times in unordered multiset." << endl << endl;


        // deleting all elements from the unordered multiset
        ums1.clear();

        if (ums1.empty())
        {
            cout << "Unordered multiset is empty.";
        }
        else
        {
            cout << "Unordered multiset is not empty.";
        }
    }
