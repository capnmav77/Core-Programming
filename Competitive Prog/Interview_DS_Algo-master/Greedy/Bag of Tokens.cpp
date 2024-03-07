/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LCx1WzlYgvw
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/bag-of-tokens/
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int currScore = 0;
        int maxScore  = 0;
        int l = 0, r = n-1;

        //:GREEDY
        //While losing power, I will choose the smallest token
        //While gainin power, I will choose the largest token
        
        while(l <= r) {
            if(P >= tokens[l]) {
                currScore++;
                maxScore = max(maxScore, currScore); //keep updating it
                P -= tokens[l]; //choose smallest token
                l++;
                
            } else if(currScore >= 1) {
                currScore--;
                P += tokens[r]; //choose largest token
                r--;
                
            } else {
                //no way further to increase score
                return maxScore;
            }
        }
        return maxScore;
    }
};
