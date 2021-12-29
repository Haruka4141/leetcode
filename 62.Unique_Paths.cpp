#include <vector>

using namespace std;

//https://leetcode.com/problems/unique-paths/discuss/1171708/100-faster-time-and-98-faster-space-oror-Easy-Understanding
int uniquePaths(int m, int n)
{
    //int dp[m+1][n+1];   //laguague built-in array must define at compile time
                          //std::array is same

    vector<vector<int>> dp (m, vector<int>(n, 1));
    
    for (int row = 1; row < m; ++row)
    {
        for (int col = 1; col < n; ++col)
        {
            dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{

    auto ans = uniquePaths(23, 12);

    return 0;
}

//if you use combination, you need to deal with overflow (factorial)
int combinaton_recursive(int m, int n, int m_sub_n)     //int overflow!
{
    if (n < 1) n = 1;
    if (m_sub_n < 1) m_sub_n = 1;
    if (m == 1)
        return 1;

    return m * combinaton_recursive(m - 1, n - 1, m_sub_n - 1) / n / m_sub_n;
}

int uniquePaths_v2(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    --m;
    --n;
    return combinaton_recursive(m + n, m, n);
}

double factorial(int num)   //{36, 7} error 1
{
    double ret = num;
    while (num > 1)
        ret *= --num;
    return ret;
}

int uniquePaths_v1(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    else
        return factorial(m + n - 2) / factorial(m - 1) / factorial(n - 1);
}