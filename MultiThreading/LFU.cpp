#include<iostream>
#include<mutex>
#include<bits/stdc++.h>


class LFUCache {
public:
    unordered_map<int, vector<int>> mp;
    set<vector<int>> s;
    int cap;
    int counter;
    mutex mu;
    
    LFUCache(int capacity) {
        cap = capacity;
        counter=0;
    }
    
    int get(int key) {
        unique_lock<mutex> lock(mu);
        if(cap==0)
            return -1;
        counter++;
        if(mp.find(key)==mp.end())
            return -1;

        int val = mp[key][0];
        int fre = mp[key][1];
        int coun = mp[key][2];

        auto it = s.find({fre, coun, key});

        s.erase(it);

        mp[key] = {val, fre+1, counter};
        s.insert({fre+1, counter, key});

        return val;        
    }
    
    void put(int key, int value) {
        unique_lock<mutex> lock(mu);
        if(cap==0)
            return;

        counter++;
        if(mp.find(key)!=mp.end())
        {
            int val = value;
            int fre = mp[key][1];
            int coun = mp[key][2];
            auto it = s.find({fre, coun, key});
            s.erase(it);

            mp[key] = {val, fre+1, counter};
            s.insert({fre+1, counter, key});
        }
        else
        {
            if(s.size()>=cap)
            {
                vector<int> it = *s.begin();
                int key1 = it[2];
                cout<<key1<<endl;
                mp.erase(key1);
                s.erase(s.begin());
            }

            mp[key] = {value, 1, counter};
            s.insert({1, counter, key});
        }
        
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
