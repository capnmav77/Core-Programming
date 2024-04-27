#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    vector<vector<int>> memo;

    vector<int> get_positions(char key, string ring) {
        vector<int> res;
        for (int i = 0; i < ring.length(); ++i) {
            if (ring[i] == key) {
                res.push_back(i);
            }
        }
        return res;
    }

    int rec(int pos, int keypos, const string& ring, const string& key) {
        if (keypos == key.length()) {
            return 0;
        }
        if (memo[pos][keypos] != -1) {
            return memo[pos][keypos];
        }
        int n = ring.length();
        int min_res = INT_MAX;
        vector<int> positions = get_positions(key[keypos], ring);
        for (int next_pos : positions) {
            int diff = abs(next_pos - pos);
            diff = min(diff, n - diff);
            int remaining_steps = rec(next_pos, keypos + 1, ring, key);
            min_res = min(min_res, diff + remaining_steps);
        }

        return memo[pos][keypos] = min_res;
    }

public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        memo.assign(n, vector<int>(key.length(), -1));
        return key.length() + rec(0, 0, ring, key);
    }
};

int main()
{
    Solution s;
    
    if(s.findRotateSteps("ababcab", "acbaacba") == 17){
        cout<<"passes test cases"<<endl;
    }
    else cout<<"failed";

    return 0;
}