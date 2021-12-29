#include <string>

using namespace std;

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    else
    {
        string ret = countAndSay(n - 1);
        int count = 1;
        for (int i = ret.size() - 1; i > 0; --i)
        {
            if (ret[i] == ret[i - 1])
            {
                ret.erase(i, 1);
                ++count;
            }
            else
            {
                ret.insert(i, 1, count + '0');
                count = 1;
            }
        }
        ret.insert(0, 1, count + '0');
        return ret;
    }

}


int main()
{

    auto ans = countAndSay(6);
    return 0;
}