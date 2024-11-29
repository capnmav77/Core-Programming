#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<char>> solution(vector<vector<char>> board)
{
    int rows = board.size();
    int cols = board[0].size();

    // Push boxes to the right
    for (int i = 0; i < rows; i++)
    {
        int rightmost = cols - 1;
        for (int j = cols - 1; j >= 0; j--)
        {
            if (board[i][j] == '*')
            {
                rightmost = j - 1;
            }
            else if (board[i][j] == '#')
            {
                char temp = board[i][rightmost];
                board[i][rightmost] = '#';
                board[i][j] = temp;
                rightmost--;
            }
        }
    }

    // Push boxes down
    for (int j = 0; j < cols; j++)
    {
        int rm = rows - 1;
        for (int i = rows - 1; i >= 0; i--)
        {
            if (board[i][j] == '*')
            {
                rm = i - 1;
            }
            else if (board[i][j] == '#')
            {
                char temp = board[rm][j];
                board[rm][j] = '#';
                board[i][j] = temp;
                rm--;
            }
        }
    }

    return board;
}

int main()
{
    // here's the board write it as  a vector : board = [[ '-', '#', '-', '-', '-'] , [ '-', '-' , '-', '-', '-'] , [ '#', '-', '#', '#', '-'], [ '#', '-', '-', '-', '#']]

    vector<vector<char>> board = {{'-', '#', '-', '-', '-'}, {'-', '-', '-', '-', '-'}, {'#', '-', '#', '#', '-'}, {'#', '-', '-', '-', '#'}};

    vector<vector<char>> result = solution(board);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}