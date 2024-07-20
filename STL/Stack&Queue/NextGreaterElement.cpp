#include<iostream>
#include<bits/stdc++.h>

class Solution {
    public: 
    std::vector<int> nextGReaterElement(std::vector<int> &nums){
        std::vector<int> ans;
        int n = nums.size();
        std::cout<<n;
        
        std::stack <int> stk;

        for(int i=nums.size()-1 ; i>=0 ; --i){
            if(stk.empty()){
                ans.push_back(-1);
                stk.push(nums[i]);
            }
            else{
                while(!stk.empty() && stk.top() < nums[i]){
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(-1);
                    stk.push(nums[i]);
                }
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
    std::vector<int> arr = {6,0,8,1,3};
    for(int elem:arr){
        std::cout<<elem<<" ";
    }
    Solution s;
    std::cout<<"init the elem";
    std::vector<int> ansk = s.nextGReaterElement(arr);
    for(int elem:ansk){
        std::cout<<elem<<" ";
    }
    return 0;

}