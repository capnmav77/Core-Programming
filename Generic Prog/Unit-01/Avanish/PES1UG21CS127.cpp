#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//I have used 
// vector
// sort
// pair

template <typename T, typename E>
class UMap
{
    vector<pair<T, E>> mp;
    int length = 0;

public:
    typedef typename vector<pair<T, E>>::iterator iterator;
    typedef typename vector<pair<T, E>>::const_iterator const_iterator;
    iterator begin()
    {
        sort(mp.begin(), mp.end());
        return mp.begin();
    }
    iterator end()
    {
        mp.end();
    }
    const_iterator begin() const
    {
        return mp.begin();
    }

    const_iterator end() const
    {
        return mp.end();
    }

    iterator find(const T &key)
    {
        sort(mp.begin(), mp.end());
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->first == key)
                return it;
        }
        return mp.end();
    }

    void insert(const T key, const E value)
    {
        mp.push_back({key, value});
        length++;
    }

    E &operator[](const T &key)
    {
        auto it = this->find(key);
        if (it != mp.end())
        {
            return it->second;
        }
        else
        {
            insert(key, E{});
            return mp.back().second;
        }
    }

    bool empty()
    {
        return length == 0;
    }

    int size()
    {
        return length;
    }
};

int main()
{

    UMap<string, int> umap;
    cout<<"Is empty? "<<umap.empty()<<endl;
    umap["ten"] = 10;
    umap["ten*2"] = 20;
    umap["ten*3"] = 30;
    cout<<"Is empty? (after inserting) "<<umap.empty()<<endl;
    
    for (auto x = umap.begin(); x != umap.end(); ++x)
    {
        cout << x->first << " " << x->second << endl;
    }

    if (umap.find("tejhn") != umap.end())
        cout << "Found Elemenet" << endl;
    else
        cout << "Not found" << endl;

    for (auto x : umap)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

    cout<<umap.size()<<endl;

    return 0;
}