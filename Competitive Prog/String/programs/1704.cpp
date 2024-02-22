// 1704. Determine if String Halves Are Alike
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

// Return true if a and b are alike. Otherwise, return false.

 

// Example 1:

// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
// Example 2:

// Input: s = "textbook"
// Output: false
// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
// Notice that the vowel o is counted twice.
 

// Constraints:

// 2 <= s.length <= 1000
// s.length is even.
// s consists of uppercase and lowercase letters.



#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;


class Solution {
private: 
    bool vowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        else{
            return false;
        }
    }

public:
    bool halvesAreAlike(string s) {
        //split the string into 2
        int len = s.length() , first = 0 , second = 0; 
        int half = len/2; 
        //check num of vowels 
        for(int i=0 ; i<len ; i++){
            if(vowel(s[i])){
                if(i<half){
                    first++;
                }
                else{
                    second++;
                }
            }
        }
        return first==second;
    }
};

int main()
{
    Solution s;
    string str = "book";
    cout<<s.halvesAreAlike(str);
    return 0;
}