#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     unordered_map<int,int> robots_health;
//     unordered_map<int,bool> robots_directions_right;

//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         if(positions.size() == 1){
//             return healths;
//         }
//         int max_pos = 0;
//         for(int i=0 ; i<positions.size() ; ++i){
//             robots_health[positions[i]] = healths[i];
//             robots_directions_right[positions[i]] = directions[i]=='R' ;
//             max_pos = max(max_pos ,positions[i]);
//         }
//         stack<int> robots_right;
//         vector<int> robots_left;
//         for(int i=0 ; i<max_pos+1 ; ++i){
//             if(robots_health[i] > 0){
//                 if(robots_directions_right[i]){
//                     robots_right.push(i);
//                 }
//                 else{
//                     robots_left.push_back(i);
//                 }
//             }
//         }

//         robots_directions_right.clear();
//         healths.clear();


//         while(!robots_right.empty() && !robots_left.empty()){
//             if(robots_right.top() > robots_left.back()){
//                 robots_right.pop();
//             }
//             else {
//                 int i=0;
//                 while(i<robots_left.size()){
//                     if(robots_right.top()<robots_left[i]){
//                         break;
//                     }
//                     i++;
//                 }
//                 if (robots_health[robots_right.top()] > 0 && robots_health[robots_left[i]] >0 ){
//                     int diff = robots_health[robots_right.top()] - robots_health[robots_left[i]];
//                     if(diff == 0){
//                         robots_health[robots_right.top()] = 0;
//                         robots_right.pop();
//                         robots_health[robots_left[i]] = 0 ;
//                         robots_left.erase(robots_left.begin() + i);
//                     }
//                     else if(diff > 0){
//                         robots_health[robots_right.top()] -=1 ;

//                         robots_health[robots_left[i]]  = 0 ;
//                         robots_left.erase(robots_left.begin() + i);
//                     }
//                     else{
//                         robots_health[robots_right.top()] = 0;
//                         robots_right.pop();
//                         robots_health[robots_left[i]] -= 1;
//                     }
//                 }
//             }
//         }
//         // vector<int> healthans;
//         for(int i=0 ; i<positions.size() ; i++){
//             if(robots_health[positions[i]]>0){
//                 healths.push_back(robots_health[positions[i]]);
//             }
//         }
//         return healths;
//     }
// };

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        if (n == 1) return healths;

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;
        for (int i : indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && healths[i] > 0) {
                    int j = st.top();
                    if (healths[j] < healths[i]) {
                        healths[j] = 0;
                        st.pop();
                        healths[i]--;
                    } else if (healths[j] > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                        break;
                    } else {
                        healths[j] = healths[i] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int health : healths) {
            if (health > 0) {
                result.push_back(health);
            }
        }
        return result;
    }
};

int main(){
Solution s;
vector<int>positions = {3,5,2,6};
vector<int>healths = {10,10,15,12};
string directions = "RLRL";
vector<int> ans = s.survivedRobotsHealths(positions, healths, directions);
for(auto it : ans){
  cout<<it<<endl;
}
return 0;
}
