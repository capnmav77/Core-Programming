// 1291. Sequential Digits
// Solved
// Medium
// Topics
// Companies
// Hint
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 

// Constraints:

// 10 <= low <= high <= 10^9


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// class Solution {
// private: 
//     int getlen(int n){
//         int count =0 ; 
//         while(n){
//             count++;
//             n /=10;
//         }
//         return count ;
//     }
//     int getnum(int n){
//         int i =1;
//         while(n-1){
//             --n ; 
//             i = i*10 +1;
//         }
//         return i;
//     }
//     int geti(int n){
//         int i=1; 
//         while(--n){
//             i = i*10 + (i%10+1);
//         }
//         return i;
//     }
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> ans;
//         int m = getlen(low) , n = getlen(high) ;
//         //cout<<m<<","<<n<<endl;

//         for(int j=m ; j<=n ; j++){
            
//             int i = geti(j);
//             if(i>high){
//                 return ans;
//             }
//             int one = getnum(j);
//             //cout<<one<<endl;
//             while(i<low){
//                 i += one;
//             }
//             if(getlen(i+one)!=j || i>high)
//             continue ;

//             while(i%10 != 0 && i<=high){
//                 ans.push_back(i);
//                 i += one;
//                 //cout<<i<<endl;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> a;

        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int nextDigit = i + 1;

            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) a.push_back(num);
                ++nextDigit;
            }
        }

        sort(a.begin(), a.end());
        return a;
    }
};





int main()
{
    Solution s;
    vector<int> ans = s.sequentialDigits(1000,13000);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}