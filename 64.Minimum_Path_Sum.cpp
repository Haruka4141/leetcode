#include <vector>

using namespace std;

//https://levelup.gitconnected.com/solve-leetcode-problems-and-get-offers-from-your-dream-companies-13949a80d2ab
int minPathSum(vector<vector<int>>& grid)  //reduce memory
{
    int row = grid.size();
    int col = grid[0].size();

    //vector<vector<int>> min_sum(row ,vector<int>(col, 0));

    //min_sum[0][0] = grid[0][0];

    for (int i = 1; i < col; ++i)
    {
        grid[0][i] += grid[0][i - 1];
    }

    for (int j = 1; j < row; ++j)
    {
        grid[j][0] += grid[j - 1][0];
    }

    for (int i = 1; i < row; ++i)
    {
        for (int j = 1; j < col; ++j)
        {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    
    return grid[row - 1][col - 1];
}


int main()
{
    //vector<vector<int>> grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
    vector<vector<int>> grid = { {1,2,3}, {4,5,6} };
    auto ans = minPathSum(grid);

    return 0;
}

int minPathSum_v1(vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> min_sum(row, vector<int>(col, 0));

    min_sum[0][0] = grid[0][0];

    for (int i = 1; i < col; ++i)
    {
        min_sum[0][i] = min_sum[0][i - 1] + grid[0][i];
    }

    for (int j = 1; j < row; ++j)
    {
        min_sum[j][0] = min_sum[j - 1][0] + grid[j][0];
    }

    for (int i = 1; i < row; ++i)
    {
        for (int j = 1; j < col; ++j)
        {
            min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i][j - 1]) + grid[i][j];
        }
    }

    return min_sum[row - 1][col - 1];
}