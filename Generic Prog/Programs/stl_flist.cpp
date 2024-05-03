    #include <iostream>
    #include <forward_list>

    using namespace std;

    int main()
    {
        // creating a forward list
        forward_list<int> fr_lst = {1, 2, 3, 4, 5};

        // inserting new values using push_front()
        fr_lst.push_front(6);
        fr_lst.push_front(7);

        // printing the forward list
        cout << "The forward list is: ";
        for (int& i : fr_lst)
        {
            cout << i << " ";
        }

        cout << endl;

        //output: 7 6 1 2 3 4 5

        // deleting first value using pop_front()
        fr_lst.pop_front();

        // printing the updated forward list
        cout << "Forward list after using pop_front: ";
        for (int& i : fr_lst)
        {
            cout << i << " ";
        }

        return 0;
    }
