#include<iostream>
#include<string>
#include<vector>

// Longest Common Subsequence using recursion 
// Time Complexity : O(2^n)
// Space Complexity : O(1)

class SolutionRec {
    private:

        int rec(int i , int j , std::string text1 , std::string text2){
                if(i>=text1.length() || j>=text2.length()){
                    return 0;
                }
                else{
                    if(text1[i]==text2[j]){
                        return 1 + rec(i+1,j+1,text1,text2);
                    }
                    else{
                        return std::max(rec(i+1 , j , text1,text2) , rec(i,j+1, text1 , text2));
                    }
                }
                
            }

    public :

        int longestCommonSubsequence(std::string text1, std::string text2) {
            int i=0 , j=0 ; 
            int res = rec(i,j,text1,text2);
            return res; 
        }

};


class SolutionDp{

    private:
        void dynp(int m , int n , std::string text1 , std::string text2 , std::vector<std::vector<int> > &dp , int i , int j){
            while(m<=i && n<=j){
                if(text1[m-1]==text2[n-1]){
                    dp[m][n] = 1 + dp[m-1][n-1];
                    m++;
                    n++;
                }
                else{
                    dp[m][n] = std::max(dp[m-1][n] , dp[m][n-1]);
                    if(dp[m-1][n]>dp[m][n-1]){
                        m++;
                    }
                    else{
                        n++;
                    }
                }
            }
        }

    public: 
        // int longestCommonSubsequence(std::string text1, std::string text2) {
        //     int n = text1.length() , m = text2.length();
        //     int dp[n+1][m+1];
        //     for(int i=0 ; i<=n ; i++){
        //         for(int j=0 ; j<=m ; j++){
        //             if(i==0 || j==0){
        //                 dp[i][j] = 0;
        //             }
        //             else{
        //                 if(text1[i-1]==text2[j-1]){
        //                     dp[i][j] = 1 + dp[i-1][j-1];
        //                 }
        //                 else{
        //                     dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
        //                 }
        //             }
        //         }
        //     }
        //     return dp[n][m];
        // }

        int longestCommonSubsequence(std::string text1, std::string text2) {
            int m = text1.length() , n = text2.length();
            std::vector<std::vector<int> > dp(m+1 , std::vector<int>(n+1,0));

            dynp(1,1,text1,text2,dp,m,n);
            return dp[m][n];
        }
};

int main(){
    SolutionDp s;
    std::string text1 = "abcde";
    std::string text2 = "ace";
    std::string text3 = "pmjghexybyrgzczy";
    std::string text4 = "hafcdqbgncrcbihkd";
    int res1 = s.longestCommonSubsequence(text1,text2) , res2 = s.longestCommonSubsequence(text3,text4);
    if(res1==3 && res2==4){
        std::cout<<"Test Passed "<<std::endl;
    }
    else{
        std::cout<<"Test Failed"<<std::endl;
        std::cout<<res1<<","<<res2<<std::endl;
    }
    return 0;
}