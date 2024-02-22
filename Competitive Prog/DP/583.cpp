//583. Delete Operation for Two Strings

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>



class Solution {
private:
    int longestCommonSub(std::string word1 , std::string word2 , int m , int n){
        std::vector< std::vector<int> >dp(m+1 , std::vector<int> (n+1 , 0));

        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }



public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length() , n = word2.length();
        int lcs = longestCommonSub(word1 , word2 , m , n);
        //std::cout<<lcs;
        return m+n-2*lcs;
    }
};


int main()
{
    Solution s;
    std::cout<<s.minDistance("sea" , "eat");
    return 0;
}