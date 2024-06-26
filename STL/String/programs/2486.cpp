#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length() , m = t.length();
        int i=0 , j = 0 , maxcount = 0, currcount = 0;
        while(i<n && j<m){
            if(s[i] == t[j]){
                currcount++;
                i++; j++;
            }
            else{
                maxcount = max(maxcount , currcount);
                currcount = 0;
                j = 0;
                i++;
            }
        }
        maxcount = max(maxcount,currcount);
        return m-maxcount;
    }
};



int main()
{
    Solution s;
    cout<<s.appendCharacters("z","abcdse");
    return 0;
}