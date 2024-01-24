// 1239. Maximum Length of a Concatenated String with Unique Characters
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.
// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
// Explanation: The only string in arr has all 26 characters.

#include<bits/stdc++.h>

using namespace std;

// //brute force

// class Solution {
// private:
//     int initmap(unordered_map<char,int>&hmap , string s ){
//         for(int k=0 ; k<s.size() ; ++k){
//             if(hmap[s[k]]){
//                 return -1;
//             }
//             hmap[s[k]]++;
//         }
//         return 1;
//     }

//     bool checkmap(unordered_map<char,int>&hmap , string s){
//         for(int l = 0 ; l<s.size() ; ++l){
//             if(hmap[s[l]]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool compareLength(const std::string& a, const std::string& b)
//     {
//         return a.size() < b.size();
//     }
    

// public:
    
//     int maxLength(vector<string>& arr) {
//         int n = arr.size();
//         if(n==1){
//             return arr[0].size();
//         }
//         int maxval = 0;
//         sort(arr.begin(), arr.end(), [this](const std::string& a, const std::string& b) {
//             return compareLength(a, b);
//         });
//         for(int i=0 ; i<n ; ++i){

//             int cursize = arr[i].size();

//             unordered_map<char,int> hmap;
//             if(initmap(hmap , arr[i]) == -1){
//                 continue;
//             }

//             for(int j=i+1 ; j<n ; ++j){
//                 if(checkmap(hmap,arr[j])){
//                     if(initmap(hmap,arr[j]) == -1){
//                         continue;
//                     }
//                     cursize += arr[j].size();
//                 }
//             }

//             maxval = max(maxval , cursize);
//             cout<<maxval<<" ";
//         }
//         return maxval;
//     }
// };


class Solution {
private:
    bool isUniquechars(const string &s){
        unordered_set<char>set;
        for(char c : s){
            if(set.count(c)){
                return false;
            }
            set.insert(c);
        }
        return true;
    }

    void dfs(const vector<string> & arr , const string &path , int index , int & result)
    {
        if(isUniquechars(path)){
            result = max(result , static_cast<int>(path.length()));
        }
        if(index == arr.size() || !isUniquechars(path)){
            return;
        }
        for(int i=index ; i<arr.size() ; i++){
            dfs(arr, path + arr[i] , i+1 , result);
        }
    }

public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }
};

int main()
{
    vector<string>arr = {"cha","r","act","ers"};
    Solution s;
    cout<<s.maxLength(arr);
    return 0;
}