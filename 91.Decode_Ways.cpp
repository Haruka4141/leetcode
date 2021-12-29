#include <string>
#include <vector>

using namespace std;

int numDecodings(string s)      //submission
{
    vector<int> dp(s.size() + 1, 0);    

    dp[0] = 1;  //for dp[2]
    dp[1] = s[0] == '0' ? 0 : 1;

    //start from s[1]
    for (int i = 2; i < dp.size(); i++)
    {
        int onedigit = int(s[i - 1] - '0');
        int twodigit = stoi(s.substr(i - 2, 2));        //<string>

        if (onedigit >= 1)
            dp[i] += dp[i - 1];
        if (twodigit >= 10 and twodigit <= 26)
            dp[i] += dp[i - 2];
    }
    return dp.back();
}

//pass, but hard to read
int numDecodings(string s)
{
    vector<int> ret(s.size(), 0);

    if (s[0] == '0')
        return 0;
    ret[0] = 1;

    if (s.size() <= 1)
        return ret[0];

    if (s[1] == '0' )
    {
        if (string(s, 0, 2) <= "26")
            ret[1] = 1;
        else
            return 0;
    }
    else
    {
        if (string(s, 0, 2) > "26")
            ret[1] = 1;
        else
            ret[1] = ret[0] + 1;
    }
    
    for (int i = 2; i < s.size(); ++i)
    {
        if (s[i] == '0')
        {
            if (s[i - 1] == '0')
                return 0;
            ret[i] = ret[i - 2];
        }
        else
        {
            if (string(s, i - 1, 2) > "26" || s[i - 1] == '0')
                ret[i] = ret[i - 1];
            else
                ret[i] = ret[i - 1] + ret[i - 2];
        }
    }
    return ret.back();
}

int main()
{
    auto ans = numDecodings("2611055971756562");

    return 0;
}

//seems work, but time limits exceed
void numdecode_recursive(string s, int& ret, int curr_length, vector<string>& decode_str)
{
    if (curr_length > s.size())
        return;

    if (!decode_str.empty())
        if (decode_str.back().size() == 2 && decode_str.back() > "26" || decode_str.back()[0] == '0')
            return;

    if (curr_length == s.size())
    {
        ++ret;
        return;
    }

    decode_str.push_back(string(1, s[curr_length]));
    numdecode_recursive(s, ret, curr_length + 1, decode_str);
    decode_str.pop_back();

    decode_str.push_back(string(s, curr_length, 2));
    numdecode_recursive(s, ret, curr_length + 2, decode_str);
    decode_str.pop_back();

    return;
}

int numDecodings_v1(string s)
{
    int ret = 0;
    int curr_length = 0;
    vector<string> decode_str;

    numdecode_recursive(s, ret, curr_length, decode_str);

    return ret;
}