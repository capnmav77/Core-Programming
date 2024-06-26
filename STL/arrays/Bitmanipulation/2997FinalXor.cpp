#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(const vector<int>& nums, int k) {
        int finalXor = 0; 
        for(int n: nums){
            finalXor = finalXor^n;
        }

        int count = 0; 

        while(k || finalXor){
            if((k%2) != (finalXor%2)){
                count++;
            }
            k = k/2;
            finalXor = finalXor/2;
        }
        return count ; 
    }

    
};


int main()
{
    Solution s; 
    
    cout<<s.minOperations({2,1,3,4} , 1);

    return 0;
}