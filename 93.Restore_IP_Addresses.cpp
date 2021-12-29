#include <string>
#include <vector>

using namespace std;

//submission, 0ms runtime & least memory
void solve(string& s, string& v, vector<string>& ans, int i, int count) 
{
    if (count == 3) 
    {
        if (s.size() - i > 3)
            return;
        if (stoi(s.substr(i, s.size() - i)) <= 255)     //append remain digits in index 4
        {
            if (s[i] == '0' && s.size() - i > 1)        //2, 3 digit int with leading 0
                return;
            ans.push_back(v + s.substr(i, s.size() - i));
        }
        return;
    }
    else 
    {
        for (int j = 1; j + i < s.size(); j++) 
        {
            if (j > 3)      //3 digits
                break;
            if (stoi(s.substr(i, j)) > 255)
                break;
            if (s[i] == '0' && j > 1)                   //2, 3 digit int with leading 0
                continue;

            int k = v.size();   //v size before append

            v += s.substr(i, j);
            v += '.';
            count++;
            solve(s, v, ans, i + j, count);
            count--;
            v.erase(k, v.size() - k);   //erase append size
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    string v;
    solve(s, v, ans, 0, 0);
    return ans;
}

//pass, but this will execute useless recursive (e.g 255255255, 2.5.5.2)
void restoreIP_recursive(string& s, vector<string>& ret, vector<string>& ip, int s_index, int ip_index)
{
    if (s_index == s.size() && ip_index == 4)
    {
        string valid_ip;
        for (int i = 0; i < 3; ++i)
        {
            valid_ip += (ip[i] + ".");
        }
        valid_ip += ip[3];
        ret.push_back(valid_ip);
        return;
    }

    if (s_index >= s.size() || ip_index > 3)
        return;

    ip[ip_index] = s.substr(s_index, 1);
    restoreIP_recursive(s, ret, ip, s_index + 1, ip_index + 1);
    ip[ip_index].clear();

    if (s[s_index] == '0')
        return;
    ip[ip_index] = s.substr(s_index, 2);
    restoreIP_recursive(s, ret, ip, s_index + 2, ip_index + 1);
    ip[ip_index].clear();

    if (s.substr(s_index, 3) > "255")
        return;
    ip[ip_index] = s.substr(s_index, 3);
    restoreIP_recursive(s, ret, ip, s_index + 3, ip_index + 1);
    ip[ip_index].clear();

}

vector<string> restoreIpAddresses_v1(string s)
{
    vector<string> ret;
    vector<string> temp_ip(4, "");

    int index = 0;
    int length = 0;

    restoreIP_recursive(s, ret, temp_ip, 0, 0);

    return ret;
}

int main()
{

    auto ans = restoreIpAddresses("010010");

    return 0;
}

