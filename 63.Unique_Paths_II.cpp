#include <vector>

using namespace std;

//https://stackoverflow.com/questions/21880922/why-can-i-declare-an-array-with-a-predestined-size-on-gcc-but-not-on-visual-stud
//Variable length array(VLA) is a C99 addition. VS did not support C99

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    obstacleGrid[0][0] == 1 ? dp[0][0] = 0 : dp[0][0] = 1;

    for (int i = 1; i < col; ++i)
    {
        if (obstacleGrid[0][i] != 1)
            dp[0][i] = dp[0][i - 1];
    }

    for (int j = 1; j < row; ++j)
    {
        if (obstacleGrid[j][0] != 1)
            dp[j][0] = dp[j - 1][0];
    }

    for (int i = 1; i < row; ++i)
    {
        for (int j = 1; j < col; ++j)
        {
            if (obstacleGrid[i][j] != 1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[row - 1][col - 1];
}

int main()
{
    //vector<vector<int>> a = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    vector<vector<int>> a = { {1, 1}, {0, 0} };
    auto ans = uniquePathsWithObstacles(a);

    return 0;
}