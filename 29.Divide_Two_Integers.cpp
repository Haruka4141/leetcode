#define INT_MIN -2147483648
#define INT_MAX 2147483647

#include <cstdlib>

//HINT: bit manipulate
//https://www.wikihow.com/Divide-Binary-Numbers
//https://en.wikipedia.org/wiki/Two%27s_complement  (signed int: 2's complement)
// 2's complement convert:
// 1. ~(NOT) all bit
// 2. LSB + 1
// 
//https://www.wikihow.com/Subtract-Binary-Numbers   (but in 2's complement, we only use addition)

//https://leetcode.com/problems/divide-two-integers/discuss/1085017/JS-Python-Java-C%2B%2B-or-(Updated)-Logarithmic-and-Bit-Manipulation-Solutions-w-Explanation
int divide_v3(int A, int B)     //A = dividend, B = divisor
{
    int ans = 0; 
    int sign = A > 0 == B > 0 ? 1 : -1;

    if (B == -2147483648) 
        return A == B;      //answer will only be 0 or 1

    if (A == -2147483648)
        if (B == 1) return -2147483648;
        else if (B == -1) return 2147483647;        //overflow
        else A += abs(B), ans++;                    //answer must > 1, execute once to avoid abs(A) overflow        <-***

    A = abs(A), B = abs(B);
    for (int i = 0; A >= B; i = 0) 
    {
        while (A >> i >= B)     
            i++;                //align dividend to divisor and count move step (instead shifting divisor(modify value) to dividend, preventing shifting overflow)
        A -= B << i - 1;        //B << (i - 1)   align divisor to dividend & substract
        ans += 1 << i - 1;      
    }
    return sign < 0 ? -ans : ans;
}

int main()
{
    int ans = divide_v3(INT_MAX, 1);

    return 0;
}

//https://stackoverflow.com/questions/5284898/implement-division-with-bit-wise-operator
int divide_v2(int dividend, int divisor)   //fail
{
    int negate = 0;
    int ret = 0;

    if (divisor == -2147483648)
        return dividend == divisor;      //answer will only be 0 or 1

    if (dividend == -2147483648)
        if (divisor == 1) return -2147483648;
        else if (divisor == -1) return 2147483647;        //overflow
        else dividend += abs(divisor), ret++;             //answer must > 1, execute once to avoid abs(A) overflow        <-***

    //while (dividend >= divisor)     //if dividend = INT_MAX, divisor will overflow to -2^31
    //    divisor <<= 1;
    //divisor >>= 1;

    int align = 0;
    while (dividend >> align >= divisor)
        ++align;
    divisor <<= align - 1;

    int t = dividend - divisor;
    while (t >= 0)
    {
        ret |= 1;
        dividend = t;

        dividend <<= 1;

        ret <<= 1;
        t = dividend - divisor;
    }

    if (negate == 1)
        return -ret;

    return ret;
}

int divide_v1(int dividend, int divisor)  //Time limit
{
    int ret = 0;

    //if (dividend < -INT_MAX)
    //    return INT_MAX;

    if (dividend > 0 && divisor > 0)
    {
        while (dividend >= divisor)
        {
            dividend -= divisor;
            ++ret;
        }
    }
    else if (dividend > 0 && divisor < 0)
    {
        while (dividend >= -divisor)
        {
            dividend += divisor;
            --ret;
        }
    }

    else if (dividend < 0 && divisor > 0)
    {
        while (dividend <= -divisor)
        {
            dividend += divisor;
            --ret;
        }
    }

    else if (dividend < 0 && divisor < 0)
    {
        while (dividend <= divisor)
        {
            dividend -= divisor;
            if (ret == INT_MAX)
                return INT_MAX;
            ++ret;
        }
    }

    return ret;
}