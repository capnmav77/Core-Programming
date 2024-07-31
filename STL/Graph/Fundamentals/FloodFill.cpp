#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
        void floodfill(vector<vector<int>> & v, int c , int x , int y){
            // logic 
            queue<pair<int,int>> holes;
            // for(int i=0 ; i<v.size() ; ++i){
            //     for(int j=0 ; j<v[0].size() ; ++j){
            //         if( v[i][j] ==1 ){
            //             holes.push({i,j});
            //         }
            //     }
            // }

            // directions : 
            vector<int> dx = {{0,0,1,-1}};
            vector<int> dy = {{1,-1,0,0}};


            // bfs logic here:  
            holes.push({x,y});
            while(!holes.empty()){
                pair<int,int> node = holes.front();
                holes.pop();
                for(int i=0 ; i<4 ; i++){
                    int nx = node.first + dx[i];
                    int ny = node.second + dy[i];
                    if(nx <0 || ny<0 || nx>=v.size() || ny>=v[0].size() || v[nx][ny] != 1){
                        continue;
                    }
                    v[nx][ny]=c;
                    holes.push({nx,ny});
                }
            }
        }        
        
};

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int n = 2; 
    Solution s; 
    s.floodfill(image , n,1,1);
    for(int i=0 ; i<image.size() ; ++i){
        for(int j=0 ; j<image[0].size() ; ++j){
            cout<<image[i][j]<<" ";
        }
    }
    return 0;
}