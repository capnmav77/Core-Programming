#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> NextGE(vector<int> &nums){
            vector<int> ans;
            stack<int> stk;
            
            // dummy traversal to fill the stack : 
            for(int i=nums.size() - 1 ; i>=0 ; --i){
                if(stk.empty()){
                    stk.push(nums[i]);
                }
                else{
                    while(!stk.empty() && stk.top()<=nums[i]){
                        stk.pop();
                    }
                    stk.push(nums[i]);
                }
            }

            // real traversal
            for(int i=nums.size()-1 ; i>=0 ; --i){
                if(stk.empty()){
                    ans.push_back(-1);
                    stk.push(nums[i]);
                }
                else{
                    while(!stk.empty() && stk.top() <= nums[i]){
                        stk.pop();
                    }
                    if(stk.empty()) i++;
                    else{
                        ans.push_back(stk.top());
                        stk.push(nums[i]);
                    }

                }
            }
            return ans;
        }
};


int main(){
    vector<int>nums = {2,10,12,1,11};
    Solution s;
    nums = s.NextGE(nums);
    reverse(nums.begin(),nums.end());
    for(int n : nums){
        cout<<n<<" ";
    }
    return 0;
}