#include <vector>

using namespace std;

//This problem focus on space complexity, not time.

//Hint4:
//We can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero.
//(because we search from left-right, top-bottom, we can set the flags in searched element)
void setZeroes(vector<vector<int>>& matrix) 
{
    bool first_row_flag = false;
    bool first_col_flag = false;

    for (int col = 0; col < matrix[0].size(); ++col)
        if (matrix[0][col] == 0)
            first_row_flag = true;

    for (int row = 0; row < matrix.size(); ++row)
        if (matrix[row][0] == 0)
            first_col_flag = true;

    for (int row = 1; row < matrix.size(); ++row)
        for (int col = 1; col < matrix[0].size(); ++col)
            if (matrix[row][col] == 0)
            {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }

    for (int row = 1; row < matrix.size(); ++row)
        if (matrix[row][0] == 0)
            for (int col = 1; col < matrix[0].size(); ++col)
                matrix[row][col] = 0;

    for (int col = 1; col < matrix[0].size(); ++col)
        if (matrix[0][col] == 0)
            for (int row = 1; row < matrix.size(); ++row)
                matrix[row][col] = 0;

    if (first_col_flag)
        for (int row = 0; row < matrix.size(); ++row)
            matrix[row][0] = 0;

    if (first_row_flag)
        for (int col = 0; col < matrix[0].size(); ++col)
            matrix[0][col] = 0;
}

int main()
{
    vector<vector<int>> matrix = { {0, 1, 2, 0},{3, 4, 5, 2},{1, 3, 1, 5} };
    setZeroes(matrix);

    return 0;
}