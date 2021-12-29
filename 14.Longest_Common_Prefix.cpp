#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    int index = 0;
    bool cond = true;
    string ret_str = "";

    while(cond)
    {
        vector<string>::iterator it = strs.begin();

        if (strs.size() == 0)
            return ret_str;

        if (strs.size() == 1)
        {   
            ret_str.append(*it);
            return ret_str;
        }

        ret_str.push_back((*it)[index]);

        for (++it; it != strs.end(); ++it)
        {
            if ((*it)[index] == '\0' || 
                (*it)[index] != ret_str[index])
            {
                ret_str.pop_back();
                cond = false;
                break;
            }
        }
        ++index;
    }
    return ret_str;
}

int main()
{
    vector<string> str_vec = {};
    string ret = longestCommonPrefix(str_vec);
    return 0;
}

