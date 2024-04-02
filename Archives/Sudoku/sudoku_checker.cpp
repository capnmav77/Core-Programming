#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solver 
{
    private: 
    int checkRow(vector<vector<int>> brd , int number, int row , int col){
        for(int i = 0 ; i<9 ; i++){
            if(i==col) continue;
            if(brd[row][i] == number ){
                //cout<<row<<" "<<i<<endl;
                return 0;
            }
        }
        return 1;
    }
    int checkCol(vector<vector<int>> brd , int number , int row , int col){
        for(int i = 0 ; i<9 ; i++){
            if(i==row) continue;
            if(brd[i][col] == number ){
                //cout<<i<<" "<<row<<endl;
                return 0;
            }
        }
        return 1;
    }
    int checkbox(vector<vector<int>> brd , int number, int row, int col){
        for(int i=(row/3)*3 ; i<(row/3 + 1 )*3 ; i++){
            for(int j=(col/3)*3 ; j<(col/3 +1)*3 ; j++){
                if(i==row && j==col) continue;
                if(brd[i][j] == number){
                    //cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        return 1;
    }

    public: 
    bool Check(vector<vector<int>> &brd ){
        //check row 
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(!(checkRow(brd, brd[i][j] , i,j) && checkCol(brd, brd[i][j] , i,j) && checkbox(brd, brd[i][j] , i,j))){
                    //cout<<"wrong";
                    return false;
                }  
            }
        }
        return true;
    }

};


int main(){
    vector<vector<int>> sudokuBoard = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    Solver s;
    cout<<s.Check(sudokuBoard);

    return 0;
}