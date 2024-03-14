// 3005. Count Elements With Maximum Frequency
// User Accepted:13786
// User Tried:14468
// Total Accepted:14357
// Total Submissions:20447
// Difficulty:Easy
// You are given an array nums consisting of positive integers.

// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

// The frequency of an element is the number of occurrences of that element in the array.

 

// Example 1:

// Input: nums = [1,2,2,3,1,4]
// Output: 4
// Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
// So the number of elements in the array with maximum frequency is 4.
// Example 2:

// Input: nums = [1,2,3,4,5]
// Output: 5
// Explanation: All elements of the array have a frequency of 1 which is the maximum.
// So the number of elements in the array with maximum frequency is 5.
 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> freq;
        int elem = nums[0] , count = 1;
        for(int i=1 ; i<nums.size() ; i++){
            if(elem == nums[i]){
                count++;
            }
            else{
                freq.push_back(count);
                count = 1;
                elem = nums[i];
            }
        }
        freq.push_back(count);
        int maxval = 0,cunt=1;
        for(int i=0 ; i<freq.size() ; i++){
            if(freq[i]>maxval){
                maxval = freq[i];
                cunt = 1;
            }
            else if(freq[i]==maxval){
                cunt++;
            }
        }
        return maxval*cunt;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,2,3,4,4,5,5,5};
    cout<<s.maxFrequencyElements(nums);
    return 0;
}