    #include <iostream>
    #include <vector>

    using namespace std;

    int main()
    {
        vector<int> vec;

        for (int i = 1; i <= 30; i = i * 3)
            vec.push_back(i);

        cout << "Output with vec.begin() and vec.end(): ";
        for (auto i = vec.begin(); i != vec.end(); i++)
            cout << *i << " ";

        cout << "\nOutput with vec.rbegin() and vec.rend(): ";
        for (auto ir = vec.rbegin(); ir != vec.rend(); ir++)
            cout << *ir << " ";

        return 0;
    }
