#include<iostream>
#include<array>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches) {
//         unordered_map<int,int> left;
//         unordered_map<int,int> right;
//         for(int i=0 ; i<matches.size() ; i++){
//             left[matches[i][0]]++;
//             right[matches[i][1]]++;
//         }
//         vector<int>ans1;
//         vector<int>ans2 ; 
//         //not lost
//         //lost once
//         for(auto i = left.begin() ; i!=left.end() ; i++){
//             if(right[i->first]==0){
//                 ans1.push_back(i->first);
//             }
//         } 
//         for(auto i=right.begin() ; i!=right.end() ; i++){
//             if(right[i->first] == 1){
//                 ans2.push_back(i->first);
//             }
//         }
//         vector<vector<int>> ans;
//         sort(ans1.begin() , ans1.end());
//         sort(ans2.begin() , ans2.end());
//         ans.push_back(ans1);
//         ans.push_back(ans2);
//         return ans;
//     }
// };

class Solution {
public:
    Solution() {
        memset(loss, -1, sizeof loss);
    }
    vector<vector<int> > findWinners(vector<vector<int>>& matches) {
        vector<vector<int> > res(2, vector<int>());
        res[0].reserve(1024), res[1].reserve(1024);
        for (const auto & match : matches) {
            int winner = match[0], loser = match[1];
            if (loss[winner] == -1) loss[winner] = 0;
            if (loss[loser] == -1) loss[loser] = 1;
            else ++loss[loser];
        }
        for (int player = 1; player < N; ++player) {
            if (loss[player] == 0) res[0].emplace_back(player);
            else if (loss[player] == 1) res[1].emplace_back(player);
        }
        return res;
    }
private:
    static const int N = 1e5 + 1;
    int loss[N];
};


int main(){
    Solution s;
    vector<vector<int>> matches = {{1,2},{2,3},{4,5},{4,6},{4,7},{5,8},{5,9},{5,10}};
    vector<vector<int>> ans = s.findWinners(matches);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}