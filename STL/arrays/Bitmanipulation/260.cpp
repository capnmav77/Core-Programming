#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        
        // Initialize x to the first element of the array
        int x = arr[0];
        
        // Iterate through the array starting from the second element
        for(int i = 1; i < n; i++){
            // Perform a bitwise XOR operation with x and the current element
            x = x ^ arr[i];
        }
        
        // Initialize cnt to zero
        int cnt = 0;
        
        // Iterate through the bits of x
        for(int i = 0; i < 32; i++){
            // Check if the bit at the current position is set
            bool ans = x & (1 << i);
            
            // If the bit is set, break the loop and store the bit position in cnt
            if(ans == 1){
                cnt = i;
                break;
            }
        }
        
        // Initialize a and b to zero
        int a = 0, b = 0;
        
        // Iterate through the array again
        for(int i = 0; i < n; i++){
            // Check if the bit at the position cnt is set
            bool ans = arr[i] & (1 << cnt);
            
            // If the bit is set, XOR the element with a
            if(ans){
                a = a ^ arr[i];
            }
            // If the bit is not set, XOR the element with b
            else{
                b = b ^ arr[i];
            }
        }
        
        // Return the two single numbers
        return {a, b};
    }
};



int main()
{

    Solution s;
    vector<int> nums = {1,2,2,1,3,4};
    vector<int> ans = s.singleNumber(nums); // Output: [3, 4]
    return 0;
}