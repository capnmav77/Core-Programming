#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
   int T;
   cin >> T;
   while (T--) {
       int N;
       cin >> N;
       string s;
       cin >> s;
       vector< vector<int> > dp(N + 1, vector<int>(10, 0));
       dp[0][0] = 1;
       int sum = 0;
       for (int i = 0; i < N; ++i) {
           if (s[i] != '?') {
               sum = (sum + s[i] - '0') % 9;
               for (int j = 0; j < 9; ++j) {
                  dp[i + 1][(j + sum) % 9] = (dp[i + 1][(j + sum) % 9] + dp[i][j]) % MOD;
               }
           } else {
               for (int j = 0; j < 9; ++j) {
                  for (int k = 0; k < 9; ++k) {
                      dp[i + 1][(j + k) % 9] = (dp[i + 1][(j + k) % 9] + dp[i][j]) % MOD;
                  }
               }
           }
       }
       if(N==1){
       cout << dp[N][0] << endl;
       }
       else{
       cout << dp[N][0] +1  << endl;
       }
   }
   return 0;
}
