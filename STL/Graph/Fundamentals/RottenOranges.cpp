#include<iostream> 
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> & v){
        int minutes = 0 , count = 0 , tot=0;
        queue<pair<int,int>> rotten;
        for(int i=0 ; i<v.size(); ++i){
            for(int j=0 ; j<v[0].size() ; ++j){
                if(v[i][j] == 2){
                    rotten.push({i,j});
                }
                if(v[i][j] !=0){
                    tot++;
                }
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};

        while(!rotten.empty()){
            int k = rotten.size();
            count += k;
            while(k--){
                int p = rotten.front().first , q = rotten.front().second;
                rotten.pop();
                for(int i=0 ; i<4 ; i++){
                    int nx = p+dx[i];
                    int ny = q+dy[i];
                    if(nx<0 || ny<0 || nx>=v.size() || ny>=v[0].size() || v[nx][ny] !=1){
                        continue;
                    }
                    v[nx][ny]=2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty())minutes++;
        }
        return count==tot?minutes:-1;
    }
};

int main()
    {
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        Solution s;
        int rotting = s.orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    }