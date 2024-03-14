// 2483. Minimum Penalty for a Shop
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

// if the ith character is 'Y', it means that customers come at the ith hour
// whereas 'N' indicates that no customers come at the ith hour.
// If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

// For every hour when the shop is open and no customers come, the penalty increases by 1.
// For every hour when the shop is closed and customers come, the penalty increases by 1.
// Return the earliest hour at which the shop must be closed to incur a minimum penalty.

// Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

 

// Example 1:

// Input: customers = "YYNY"
// Output: 2
// Explanation: 
// - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
// - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
// - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
// - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
// - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
// Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
// Example 2:

// Input: customers = "NNNNN"
// Output: 0
// Explanation: It is best to close the shop at the 0th hour as no customers arrive.
// Example 3:

// Input: customers = "YYYY"
// Output: 4
// Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
 

// Constraints:

// 1 <= customers.length <= 105
// customers consists only of characters 'Y' and 'N'.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute force - TLE
// class Solution {
// private:   
//     int calcpenalty(int i , string s){
//         int pen = 0;
//         for(int j=0 ; j<s.length() ;++j){
//             if(s[j]=='N' && j<i){
//                 pen++;
//             }
//             if(s[j]=='Y' && j>=i){
//                 pen++;
//             }
//         }
//         //cout<<pen<<" ";
//         return pen;
//     }
// public:
//     int bestClosingTime(string customers) {
//         int n = customers.length();
//         if(n==1){
//             return (customers[0]=='Y')? 1 : 0;
//         }
//         int pos = 0 ,pen = INT_MAX; 
//         for(int i=0 ; i<=n ; i++){
//             int calc = calcpenalty(i , customers);
//             if(calc<pen){
//                 pos = i; 
//                 pen = calc;
//             }
//         }
//         return pos ;
//     }
// };

//pref sum
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int ans = INT_MAX , ind = -1 , a=0 , b=0 ;
        vector<pair<int,int>> v(n);
        for(int i=0 ; i<n ; i++){
            if(customers[i]=='Y'){
                a++ ; v[i] = {a,b};
            }
            else if (customers[i] == 'N'){
                b++ ; v[i] = {a,b};
            }
        }
        for(int i=0 ; i<n ; i++){
            int temp = v[i].second + v[n-1].first - v[i].first;
            if(customers[i] == 'Y') temp++;
            if(customers[i] == 'N') temp--;
            if(ans>temp){
                ind = i;
                ans = temp;
            }
        }
        return ans>v[n-1].second?n:ind;
    }
};

int main()
{
    Solution s;
    cout<<s.bestClosingTime("YYNY");
    return 0;
}