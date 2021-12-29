#include <vector>
#include <set>

using namespace std;

//https://leetcode.com/problems/valid-sudoku/discuss/1332984/C%2B%2B-Simple-and-Easy-10-Short-Line-Solution
bool isValidSudoku(vector<vector<char>>& board)
{       
    vector<set<int>> rows(9), cols(9), blocks(9);       //(C++11) vector(n): constructing with n element (val is optional)
                                                        //set are typically implemented as binary tree, the elements are always const
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') continue;

            int curr = board[i][j] - '0';
            if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i / 3) * 3 + j / 3].count(curr))  //std::count(val) : return number of element of val 
                return false;

            rows[i].insert(curr);
            cols[j].insert(curr);
            blocks[(i / 3) * 3 + j / 3].insert(curr);       
        }
    }
    return true;
}
/*
     0 1 2  (j)
   0 0 1 2
   1 3 4 5      block index = i * 3 + j
   2 6 7 8
  (i)

*/

int main()
{
    vector<vector<char>> board
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };


    return 0;
}