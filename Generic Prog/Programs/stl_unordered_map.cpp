    #include <iostream>
    #include <unordered_map>

    using namespace std;

    int main()
    {
        // Declaring unordered map to be of <string, int> type
        unordered_map<string, int> uno_map;

        // inserting elements
        uno_map["Apples"] = 4;
        uno_map["Oranges"] = 4;
        uno_map["Mangoes"] = 9;

        // trying to add the key "Mangoes" twice in the map
        uno_map["Mangoes"] = 5;

        // printing an unordered map
        cout << "The unordered map is -->" << endl;
        for (auto i : uno_map)
        {
            cout << i.first << " : " << i.second << endl;
        }

        cout << endl;

        // checking if Oranges are present in the map
        string key = "Oranges";
        if (uno_map.find(key) == uno_map.end())
        {
            cout << key << " not found in uno_map" << endl;
        }
        else
        {
            cout << "Found " << key << " in uno_map" << endl;
        }

        return 0;
    }
