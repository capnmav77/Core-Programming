// 6. Zigzag Conversion
// Solved
// Medium
// Topics
// Companies
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000


#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;


//Brute Force Method
// class Solution {
// private: 
//     void display(vector< vector<int>> mat){
//         for(int i=0 ; i<mat.size() ; i++){
//             for(int j=0 ; j<mat[0].size() ; j++){
//                 cout<<mat[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }


// public:
//     string convert(string s, int numRows) {
//         if(numRows<2){
//             return s;
//         }
//         string res;
//         int n = s.length();
//         int cols ;
//         if(numRows==2){
//             cols =n/2+1;
//         }
//         if(numRows>2){
//             cols = (n/(2*numRows-2)+1)*(numRows-1);
//         }    
//         cout<<cols<<endl;
//         vector< vector<int>> mat(numRows , vector<int>(cols,-1));
//         int i=0 , j=0 , k=0 , diag=0;
//         while(j<cols){
//             mat[i][j] = k;
//             k++;
//             if(i==numRows-1){
//                 diag = 1;
//             }
//             if(i==0){
//                 diag = 0;
//             }
//             if(diag == 1){
//                 i--; 
//                 j++;
//             }
//             if(diag == 0){
//                 i++;
//             }
//         }
//         //display(mat); 
//         for(int i=0 ; i<numRows ; i++){
//             for(int j=0 ; j<cols ; j++){
//                 if(mat[i][j]>=0 && mat[i][j]<n){
//                     res.push_back(s[mat[i][j]]);
//                 }
//             }
//         }
//         return res ;
//     }
// };

//optimized 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.size();

        string result = "";

        for (int i = 0; i < numRows; i++) {
            int increment = 2 * (numRows - 1);

            for (int j = i; j < n; j += increment) {
                result += s[j];

                if (i > 0 and i < numRows - 1 and j + increment - 2 * i < n) {
                    result += s[j + increment - 2 * i];
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 3;
    cout<<s.convert(str , numRows)<<endl;
    return 0;
}