#include <string>
#include <vector>
#include <stack>

using namespace std;

string simplifyPath_stack(string path)      //submission. using stack is faster
{
    int n = path.size();
    stack<string> st;
    
    int i = 0;
    while (i < n)
    {
        string temp;
        while (path[i] == '/' && i < n) 
        {
            i++;
        }
        while (path[i] != '/' && i < n) 
        {
            temp += path[i];
            i++;
        }
        if (temp == ".." && !st.empty()) 
        {
            st.pop();
        }
        else if (temp == "." || temp == "") 
        {
            continue;
        }
        else if (temp != "..") 
        {
            st.push(temp);
        }
    }

    string res = "";
    while (!st.empty()) 
    {
        res = '/' + st.top() + res;         //<- add at front
        st.pop();
    }
    return res.empty() ? "/" : res;
}

//For this problem, any other format of periods such as '...' are treated as file/directory names.
string simplifyPath(string path)        //pass, using vector
{    
    vector<string> dir;
    
    int dir_index = -1;
    for (int i = 0; i < path.size(); ++i)
    {
        if (path[i] == '/')
        {
            dir.push_back("/");
            ++dir_index;           
        }
        else
            dir[dir_index].push_back(path[i]);
    }

    for (int i = 0; i < dir.size(); ++i)
    {
        if (dir[i] == "/." || dir[i] == "/")
        {
            dir.erase(dir.begin() + i);
            --i;
        }
        else if (dir[i] == "/..")
        {
            if (i >= 1)
            {
                dir.erase(dir.begin() + i - 1, dir.begin() + i + 1);
                i -= 2;
            }
            else
            {
                dir.erase(dir.begin() + i);
                --i;
            }
        }
    }

    string ret;
    for (auto& str : dir)
    {
        ret.append(str);
    }

    if (dir.empty())
        ret.push_back('/');

    return ret;
}

int main()
{
    //auto ans = simplifyPath("/a/../../");
    auto ans = simplifyPath("/...");
    return 0;
}

string simplifyPath_v1(string path)     //"/..." fail
{
    vector<string> dir;

    int dir_index = 0;
    dir.push_back("/");

    for (int i = 1; i < path.size(); ++i)
    {
        if (path[i] == '/')
        {
            if (path[i - 1] != '/')
            {
                dir.push_back("/");
                ++dir_index;
            }
        }
        else if (path[i] == '.')
        {
            if (dir_index > -1)
                --dir_index;
            if (!dir.empty())
                dir.pop_back();
        }
        else
            dir[dir_index].push_back(path[i]);
    }

    string ret;
    for (auto& str : dir)
    {
        ret.append(str);
    }

    while (ret.size() > 1 && ret.back() == '/')
        ret.pop_back();

    if (dir.empty())
        ret.push_back('/');

    return ret;
}