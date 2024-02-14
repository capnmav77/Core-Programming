#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

// class Solution {
// private: 
//     vector<int> getcount(vector<string> bank){
//         vector<int> res;
//         int n=bank.size() , m = bank[0].size();
//         for(int i=0 ; i<n ; i++){
//             int num = 0;
//             for(int j=0 ; j<m ; j++){
//                 if(bank[i][j] == '1'){
//                     num++;
//                 }
//             }
//             if(num!=0){
//                 res.push_back(num);
//             }
//         }
//         return res;
//     }

// public:
//     int numberOfBeams(vector<string>& bank) {
//         cout<<bank.size()<<bank[0].size()<<endl;
//         if(bank.size()==1){
//             return 0;
//         }
//         vector<int> res = getcount(bank);
//         int siz = res.size();
//         if(siz==1){
//             return 0;
//         }
//         int ans = 0;
//         for(int i=0 ; i<siz-1 ; i++){
//             ans += res[i]*res[i+1];
//             cout<<ans;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {        
        if(bank.size() < 2)
            return 0;

        int solution = 0;
        short beaconsInPrevRow = 0;
        short beaconsInCurrentRow = 0;
        for(size_t i = 0; i < bank.size(); ++i)
        {
            beaconsInCurrentRow = 0;

            for(auto &it : bank[i])
            {
                if(it == '1')
                {
                    beaconsInCurrentRow++;
                }
            }
            solution += beaconsInCurrentRow * beaconsInPrevRow;
            beaconsInPrevRow = (beaconsInCurrentRow == 0) * beaconsInPrevRow + beaconsInCurrentRow;
        }

        return solution;
    };
};


int main()
{
    Solution s;
    vector<string> bank = {"1000","0001","1101","1101","1100","0000","0000","0000","0000","0000","0000","0000","0000","0000","0000"};
    cout<<s.numberOfBeams(bank);
    return 0;
}