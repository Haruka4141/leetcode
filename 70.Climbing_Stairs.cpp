#include <vector>

using namespace std;

//Hint1:
//To reach nth step, what could have been your previous steps ? (Think about the step sizes)
int climbStairs(int n)
{
    vector<int> fib = { 1,2 };      //DP

    for (int i = 2; i < n; ++i)
    {
        fib.push_back(fib[i - 2] + fib[i - 1]);
    }

    return fib[n - 1];
}

int main()
{
    auto ans = climbStairs(9);

    return 0;
}

int climbStairs_v2(int n)      //recursive faster than v1, but 45 also needs 1min+
{
    if (n <= 2)
        return n;

    return climbStairs_v2(n - 1) + climbStairs_v2(n - 2);
}

void climb_recusive(int& ret, int n, int curr)
{
    if (curr == n)
    {
        ++ret;
        return;
    }
    if (curr > n)
    {
        return;
    }

    climb_recusive(ret, n, curr + 1);
    climb_recusive(ret, n, curr + 2);

}

int climbStairs_v1(int n)
{
    int ret = 0;
    climb_recusive(ret, n, 0);
    return ret;
}