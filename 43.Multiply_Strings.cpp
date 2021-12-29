#include <string>

using namespace std;

string multiply(string num1, string num2)   //leetcode solution
{
    if (num1 == "0" || num2 == "0")
        return "0";

    reverse(num1.begin(), num1.end());      //reversing make index easy to read
    reverse(num2.begin(), num2.end());

    int len = num1.size() + num2.size();    //e.g. 99 * 99 = 9801
    string ret(len, '0');                   

    for (int i = 0; i < num1.size(); ++i)
    {
        int val1 = num1[i] - '0';
        for (int j = 0; j < num2.size(); ++j)
        {
            int val2 = num2[j] - '0';
            int add = ret[i + j] - '0' + val1 * val2;
            ret[i + j] = add % 10 + '0';
            ret[i + j + 1] += add / 10;         //<-***
        }
    }
    while (ret.back() == '0')               //remember to delete initial 0
        ret.pop_back();

    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{

    auto ans = multiply("999999999", "9999999999999");

    return 0;
}

string multiply_v1(string num1, string num2)   //overflow!
{
    int int_num1 = 0;
    int int_num2 = 0;

    while (true)
    {
        int_num1 *= 10;
        int_num2 *= 10;

        if (!num1.empty())
        {
            int_num1 += num1.front() - '0';
            num1.erase(num1.begin());
        }
        if (!num2.empty())
        {
            int_num2 += num2.front() - '0';
            num2.erase(num2.begin());
        }
        if (num1.empty() && num2.empty())
            break;
    }

    int int_ret = int_num1 * int_num2;
    if (int_ret == 0)
        return "0";

    string ret;
    while (int_ret > 0)
    {
        ret.insert(ret.begin(), (int_ret % 10) + '0');
        int_ret /= 10;
    }

    return ret;

}