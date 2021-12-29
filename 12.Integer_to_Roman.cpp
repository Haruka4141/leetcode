#include <string>

using namespace std;

string intToRoman(int num)
{
    string roman_set = "IVXXLCCDM";
    string ret;
    int digit;

    for (int i = 0; i < 3 && num > 0; ++i)
    {
        digit = num % 10;
        num /= 10;

        string r1(roman_set.substr(i * 3, 1));
        string r2(roman_set.substr(i * 3 + 1, 1));
        string r3(roman_set.substr(i * 3 + 2, 1));

        if (digit == 9)
            ret.insert(0, r1 + r3);
        else if (digit == 4)
            ret.insert(0, r1 + r2);
        else if (digit >= 5)
        {
            ret.insert(0, r2);
            digit -= 5;
            for (int j = digit; j > 0; --j)     
                    ret.insert(1, r1);          //must insert after previous char
        }
        else
        { 
            for (int j = digit; j > 0; --j)
                    ret.insert(0, r1);          //insert at head
        }
    }
    for (num; num > 0; --num)
        ret.insert(0, "M");
    return ret;
}

int main()
{
    string ans;
    ans = intToRoman(60);
    for (int i = 0; i < 4000; ++i)
         ans = intToRoman(i);


    return 0;
}