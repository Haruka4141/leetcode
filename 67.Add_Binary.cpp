#include <string>

using namespace std;

string addBinary(string a, string b)
{
    string ret;
    int sum = 0;

    while (!a.empty() || !b.empty() || sum == 1)
    {
        if (!a.empty())
        {
            if (a.back() == '1')
                sum += 1;
            a.pop_back();
        }
        if (!b.empty())
        {
            if (b.back() == '1')
                sum += 1;
            b.pop_back();
        }

        switch (sum)
        {
        case 0:
            ret.insert(0, "0");
            break;
        case 1:
            ret.insert(0, "1");
            sum = 0;
            break;
        case 2:
            ret.insert(0, "0");
            sum = 1;
            break;
        case 3:
            ret.insert(0, "1");
            sum = 1;
            break;
        }
    }
    return ret;
}


int main()
{

    string ans = addBinary("11", "1");
    //string ans = addBinary("1010", "1011");
    return 0;
}