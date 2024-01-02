#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>



// range based for loop using & to iterate over hash_map
// class Solution {
// public:
//    vector<vector<int>> findMatrix(vector<int>& nums) {
//        std::unordered_map<int,int> hmap;
//        for(int i=0 ; i<nums.size() ; i++){
//            hmap[nums[i]]++;
//        }
//        std::vector<std::vector<int> > ans;

//        while(!hmap.empty()){
//            vector<int>temp;
//            vector<int> keys_to_delete;

//            for(auto &pair : hmap){
//                temp.push_back(pair.first);
//                pair.second--;
//                if(pair.second == 0){
//                   keys_to_delete.push_back(pair.first);
//                }
//            }

//            for(auto &key : keys_to_delete){
//                hmap.erase(key);
//            }

//            ans.push_back(temp);
//            temp.clear();
//            keys_to_delete.clear();
//        }

//        return ans;
//    }
// };

// iterator based for loop - for performing manipulations on the hash_map;

//using just simple read and writes 
// class Solution {
// public:
//    vector<vector<int>> findMatrix(vector<int>& nums) {
//        std::unordered_map<int,int> hmap;
//        int maxf = 0;
//        for(int i=0 ; i<nums.size() ; i++){
//            hmap[nums[i]]++;
//            maxf = max(maxf , hmap[nums[i]]);
//        }
//        std::cout<<maxf;
//        std::vector<std::vector<int> > ans(maxf);

//        for(auto & key : hmap){
//            int val = key.first;
//            int freq = key.second;
//            for(int i=0 ; i<freq ; i++){
//                ans[i].push_back(val);
//            }
//        }

//        return ans;
//    }
// };

//not using hashmaps
class Solution {
public:
   std::vector<std::vector<int> > findMatrix(std::vector<int>& nums) {
       std::vector<int> freq (nums.size() + 1);

       std::vector<std::vector<int> > result ; 

       for(int num:nums){
           if(freq[num] >= result.size()) {
               result.push_back({});
           }

           result[freq[num]].push_back(num);
           freq[num]++;
       }
       return result;
   }
};

// the above is just a normal way of doing the code 


int main()
{
    Solution s;
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    std::vector<std::vector<int> > ans = s.findMatrix(nums);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}



