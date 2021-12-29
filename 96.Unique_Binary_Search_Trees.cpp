#include <vector>

using namespace std;

//https://medium.com/@bill800227/leetcode-96-unique-binary-search-trees-abce6e62a7a0
int numTrees(int n)
{
    //Time complexity: O(n^2) space complexity: O(n)
    if (n == 0) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  //0
    dp[1] = 1;  //1 node 

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp.back();
}
/*
             (3)             (2)             (1)
DP[3] = DP[2] * DP[0] + DP[1] * DP[1] + DP[0] * DP[2]
             (4)             (3)             (2)             (1)
DP[4] = DP[3] * DP[0] + DP[2] * DP[1] + DP[1] * DP[2] + DP[0] * DP[3]

*/

int main()
{
    auto ans = numTrees(19);

    return 0;
}

//Pass, but Time Limit!
int numTrees_recursive(int start, int end)
{
    int ret = 0;
    if (start == end)
    {
        ret = 1;
    }
    else if (start < end)
    {
        for (int i = start; i <= end; ++i)
        {
            int left = numTrees_recursive(start, i - 1);
            int right = numTrees_recursive(i + 1, end);
            if (right == 0 || left == 0)
            {
                ret += right + left;
            }
            else
            {
                ret += right * left;
            }
        }
    }
    return ret;
}

int numTrees_v1(int n)
{
    return numTrees_recursive(1, n);
}
