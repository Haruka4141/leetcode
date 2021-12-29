#include <string>
#include <vector>

using namespace std;
/*
leetcode solution
2D tracing is left to right, top to bottom. we can keep 1 row only

0  T  <- s1 
1  F
2  F
3  F
4  F 
5  F
  (s2)
*/
bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size())
        return false;

    vector<bool> dp(s2.size() + 1, false);

    for (int i = 0; i <= s1.size(); ++i)
        for (int j = 0; j <= s2.size(); ++j)
        {
            if (i == 0 && j == 0)
                dp[j] = true;
            else if (i == 0)    //s1 = ""
                dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
            else if (j == 0)    //s2 = ""
                dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
            else
                dp[j] = (dp[j - 1] && (s2[j - 1] == s3[i + j - 1])) ||
                        (dp[j] && (s1[i - 1] == s3[i + j - 1]));
        }
    return dp.back();
}

/*
https://medium.com/@bill800227/leetcode-97-interleaving-string-18b1202fb0ea
2D DP, Time & Space: O(MN)

    0   1   2   3   4   5
0   T   T   T   F   F   F   (s1
1   F   F   T   F   ---->   
2   F  
3   F
4   F
5   F
   (s2)
*/
bool isInterleave_v1(string s1, string s2, string s3) 
{
    if (s1.size() + s2.size() != s3.size())
        return false;

    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    
    dp[0][0] = true;    //s1, s2, s3 = ""

    for (int i = 1; i < dp.size(); ++i)     //s1
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);

    for (int j = 1; j < dp[0].size(); ++j)  //s2
        dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);

    for (int i = 1; i < dp.size(); ++i)
        for (int j = 1; j < dp[0].size(); ++j)
        {                                                          //v ***
            dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
                       (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
        }
    return dp.back().back();
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    auto ans = isInterleave(s1, s2, s3);

    return 0;
}