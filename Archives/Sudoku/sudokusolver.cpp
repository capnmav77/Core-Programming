#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solver 
{
    private: 

    int checkRow(vector<vector<int>> brd , int number, int row , int col){
        for(int i = 0 ; i<9 ; i++){
            if(brd[row][i] == -1 || i==col) continue;
            if(brd[row][i] == number ){
                //cout<<row<<" "<<i<<endl;
                return 0;
            }
        }
        return 1;
    }

    int checkCol(vector<vector<int>> brd , int number , int row , int col){
        for(int i = 0 ; i<9 ; i++){
            if(brd[i][col] == -1 || i==row) continue;
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
                if(brd[i][j] == -1 || i==row && j==col) continue;
                if(brd[i][j] == number){
                    //cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        return 1;
    }


    bool Check(vector<vector<int>> &brd , int number , int i , int j){
        return checkRow(brd, number , i,j) && checkCol(brd, number , i,j) && checkbox(brd, number,i,j) ;
    }

    bool isBoardSolved(vector<vector<int>> &brd) {
        for (int i =  0; i <  9; i++) {
            for (int j =  0; j <  9; j++) {
                if (brd[i][j] == -1) {
                    return false;
                }
            }
        }
        return true;
    }

    public: 

    void solution(vector<vector<int>> &brd) {
        if (isBoardSolved(brd)) {
            cout << "Solved!" << endl;
            return;
        }

        for (int i =  0; i <  9; i++) {
            for (int j =  0; j <  9; j++) {
                if (brd[i][j] == -1) {
                    for (int num =  1; num <=  9; num++) {
                        if (Check(brd, num, i, j)) {
                            brd[i][j] = num;
                            solution(brd);
                            if (isBoardSolved(brd)) {
                                return;
                            }
                            brd[i][j] = -1; // Backtrack here
                        }
                    }
                    return; // Return if no number can be placed i.e invalid board state
                }
            }
        }
    }

};


class Board : public Solver { 

    private:

    vector<vector<int>> brd;

    //default display
    void display(){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                cout<<brd[i][j]<<"|";
            }
            cout<<endl;
        }
    }

    //overloaded
    void display(vector<vector<int>> brd){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                cout<<brd[i][j]<<"|";
            }
            cout<<endl;
        }
    }

    public:

    void init_board(){
        vector<vector<int>> bord(9,vector<int>(9,-1));
        brd = bord;
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                cout<<"pos"<<i<<j<<":";
                cin>>brd[i][j];
                display(brd);
            }
        }
    }

    void manual_board(){
        brd =  {
            {5, 3, -1, -1, 7, -1, -1, -1, -1},
            {6, -1, -1, 1, 9, 5, -1, -1, -1},
            {-1, 9, 8, -1, -1, -1, -1, 6, -1},
            {8, -1, -1, -1, 6, -1, -1, -1, 3},
            {4, -1, -1, 8, -1, 3, -1, -1, 1},
            {7, -1, -1, -1, 2, -1, -1, -1, 6},
            {-1, 6, -1, -1, -1, -1, 2, 8, -1},
            {-1, -1, -1, 4, 1, 9, -1, -1, 5},
            {-1, -1, -1, -1, 8, -1, -1, 7, 9}
        };

        display();
    }

    void blank(){
        brd =  {
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1}
        };

        display();
    }

    void solve(){
        solution(brd);
        cout<<endl;
        display(brd);
    }

};


int main(){

    Board board;

    //board.init_board();

    //board.manual_board();

    board.blank();

    board.solve();

    return 0;
}