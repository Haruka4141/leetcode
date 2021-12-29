#include <vector>
/*
Dynamic Programming: calculate base on last output (Kadane's Algorithm)

[v1, v2, v3, v4...]

at index 0, max_sum = dp[0] = v0 
at index 1, dp[1] = v1 or dp[0]+v2
at index 2, dp[2] = v2 or dp[1]+v2
...

https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
*/

using namespace std;

int maxSubArray_v2(vector<int>& nums)       //O(N) Dynamic Programming      (Leetcode hint: Divide & conquer)
{
    int max_sum = nums[0];
    int dp = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        dp = max(dp + nums[i], nums[i]);
        max_sum = max(dp, max_sum);
        //if (dp + nums[i] > nums[i])
        //    dp += nums[i];
        //else
        //    dp = nums[i];
        //if (dp > max_sum)
        //    max_sum = dp;
    }
    return max_sum;

}

int main()
{
    //vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> vec = {5,4,-1,7,8};
    //vector<int> vec = { -2,-1 };
    int ans = maxSubArray_v2(vec);

    return 0;
}

int maxSubArray(vector<int>& nums)      //{-2, -1} fail
{
    int max_sum = 0;
    max_sum += nums[0];

    int f_buffer = 0;

    int front = 0;
    int end = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        f_buffer += nums[i];
        if (f_buffer > 0)
        {
            while (front != i)
            {
                max_sum += nums[++front];
            }
            f_buffer = 0;
        }
        else
            f_buffer += nums[i];

        int e_buffer = 0;
        int j = end;
        while (j < front)
        {
            e_buffer += nums[j++];
            if (e_buffer < 0)
            {
                while (end != j)
                    max_sum -= nums[end++];
                e_buffer = 0;
                break;
            }
        }
    }
    return max_sum;
}
