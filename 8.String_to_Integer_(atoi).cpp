#include <string>

using namespace std;

int myAtoi_v2(string s)
{
    int index = 0;
    while (s[index] == ' ')
        ++index;
    
    int negate = 0;
    if (s[index] == '-')
    {
        negate = -1;
        ++index;
    }
    else if (s[index] == '+')
        ++index;

    double ret = 0;                                 //double: exponent bit = 11, 2^(2^10) ~= 10^308
                                                    //using double to store int will not cause error
    for (index; index < s.size() && s[index] >= 48 && s[index] <= 57; ++index)
        ret = 10 * ret + int(s[index]) - 48;        //leetcode submission   <-***

    if (negate == -1)
        ret *= -1;

    if (ret > INT_MAX)
        ret = INT_MAX;
    if (ret < INT_MIN)
        ret = INT_MIN;

    return ret;
}


int main()
{

    int ans = myAtoi_v2("-91283472332");

    return 0;
}

int myAtoi(string s)
{
    int index = 0;
    while (s[index] == ' ')
        ++index;

    int negate = 0;
    if (s[index] == '-')
    {
        negate = -1;
        ++index;
    }
    else if (s[index] == '+')
    {
        negate = 0;
        ++index;
    }

    string int_str;
    while (index < s.size() && 48 <= s[index] && s[index] <= 57)
    {
        int_str.append(1, s[index]);
        ++index;
    }

    int ret = 0;
    for (int index = int_str.size() - 1, j = 0; index >= 0; --index, ++j)
    {
        int32_t add = 0;
        if (negate == 0)
        {
            if (add + (int_str[index] - 48) * pow(10, j) < INT_MAX)           //C24651
                add += (int_str[index] - 48) * pow(10, j);
            else
                add = INT_MAX;
        }
        else
        {
            if (add - (int_str[index] - 48) * pow(10, j) > INT_MIN)
                add -= (int_str[index] - 48) * pow(10, j);
            else
                add = INT_MIN;
        }

        if (negate == 0)
        {
            if (int64_t(ret) + int64_t(add) > INT_MAX)  //overflow adding will cast to larger type, and leetcode compiler can accept long, so using int64_t to check
            {
                ret = INT_MAX;
                break;
            }
            ret += add;
        }
        else
        {
            if (int64_t(ret) + int64_t(add) < INT_MIN)  //add is already negative
            {
                ret = INT_MIN;
                break;
            }
            ret += add;
        }
    }
    return ret;
}
