#include<bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> ans;
//         int prev = -1;
//         for(int i=0 ; i<n ; i++){
//             int temp = temperatures[i];
//             if(temp == prev){
//                 int val = ans.back()-1;
//                 if(val<0){
//                     val = 0;
//                 }
//                 ans.push_back(val);
//             }
//            else
//             {
//                 int count=1;
//                 int j=i+1;
//                 while(j<n && temp>=temperatures[j]){
//                     count++;
//                     j++;
//                 }
//                 if(j>=n){
//                     ans.push_back(0);
//                     prev = temp;
//                 }
//                 else{
//                     ans.push_back(count);
//                     prev = temp;
//                 } 
//             }

//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> warmDays;
        std::vector<int> result(temperatures.size());

        for (int index = 0; index < temperatures.size(); index++) {
            while (!warmDays.empty() && temperatures[warmDays.back()] < temperatures[index]) {
                result[warmDays.back()] = index - warmDays.back();
                warmDays.pop_back();
            }

            warmDays.push_back(index);
        }

        return result;
    }
};

int main()
{
    vector<int> temp = {34,80,80,34,34,80,80,80,80,34};
    Solution s;
    vector<int> ans;
    ans = s.dailyTemperatures(temp);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}