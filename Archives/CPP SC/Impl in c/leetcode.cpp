#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int find_maxjump(int lim,vector<int>&nums,int currpos){
        int maxval=0;
        int pos = 0;
        for(int i = 1; i<=lim;i++){
            if((nums[currpos+i]+i)>maxval){
                maxval  = nums[i]+i;
                pos = i;
            }
        }
        return pos;
    }

    int jump(vector<int>& nums) {
        int i =0,count = 0,k=nums.size();
        while(i<k-1){
            if(nums[i]>=k-1){
                return count+1;
            }
            i += find_maxjump(nums[i],nums,i);
            count++;
        }
        return count;  
    }
};



int main()
{
    Solution Soln;
    vector<int> nums{1,2,0,1};
    int sol = Soln.jump(nums);
    cout<<sol;
    return 0;
}
