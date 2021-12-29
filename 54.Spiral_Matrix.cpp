#include <vector>

using namespace std;
/*
First while:                                            Second while: 
                                                                   col_start  col_end                     col_end, col_start (cause duplication, so need to add checking)
     0  1  2  3                                                            v  v                           v
   0                              0  1  2                                  1  2                           1
   1           < row_start  ->  1         < row_end    ->     row_end  >1               ->  row_end   > 1
   2                            2                           row_start  >                    row_start >
           ^                         ^
           col_end                      col_start


*/

//Hint: https://letstalkalgorithms.com/spiral-matrix-leetcode/
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> ret;

    int row_start = 0;
    int col_start = 0;
    int col_end = matrix[0].size() - 1;
    int row_end = matrix.size() - 1;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; ++i)
        {
            ret.push_back(matrix[row_start][i]);
        }
        ++row_start;

        for (int i = row_start; i <= row_end; ++i)
        {
            ret.push_back(matrix[i][col_end]);
        }
        --col_end;

        if (row_start <= row_end)               //reverse traverse, prevent duplication
            for (int i = col_end; i >= col_start; --i)
            {
                ret.push_back(matrix[row_end][i]);
            }
        --row_end;

        if (col_start <= col_end)               //reverse traverse, prevent duplication
            for (int i = row_end; i >= row_start; --i)
            {
                ret.push_back(matrix[i][col_start]);
            }
        ++col_start;

    }

    return ret;

}


int main()
{

    vector<vector<int>> matrix = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    //vector<vector<int>> matrix = { {6,9,7} };
    auto ans = spiralOrder(matrix);
    
    return 0;
}