#include <vector>

using namespace std;

vector<int> plusOne_v2(vector<int>& digits)
{
    int carry = 0;
    auto riter = digits.rbegin();

    for (*riter += 1; riter != digits.rend(); ++riter)
    {
        *riter += carry;
        if (*riter == 10)
        {
            carry = 1;
            *riter = 0;
        }
        else
            carry = 0;

        if (carry == 0)
            break;
    }

    if (carry == 1)
        digits.insert(digits.begin(), 1);

    return digits;
}

int main()
{
    vector<int> a = { 8,9,9,9 };
    auto ans = plusOne_v2(a);

    return 0;
}


vector<int> plusOne(vector<int>& digits)    //[9,8,7,6,5,4,3,2,1,0] fail (int overflow)
{
    int carry = 0;
    vector<int>::reverse_iterator iter = digits.rbegin();
    int val = 0;

    for (int i = 0; iter != digits.rend(); ++iter, ++i)
        val += *iter * (int)pow(10, i);

    val += 1;

    vector<int> ret_digits;
    vector<int>::iterator iter2;
    while (val >= 10)
    {
        iter2 = ret_digits.begin();
        ret_digits.insert(iter2, val % 10);
        val /= 10;
    }

    iter2 = ret_digits.begin();
    ret_digits.insert(iter2, val);

    return ret_digits;
}