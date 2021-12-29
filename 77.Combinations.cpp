#include <vector>

using namespace std;

//Use depth-first search
void rec(int n, int k, int curr, vector<int>& temp, vector<vector<int>>& ans)   //submission
{
    if (temp.size() == k) 
    {
        ans.push_back(temp);
        return;
    }
    for (int i = curr; i <= n; ++i)
    {
        temp.push_back(i);
        rec(n, k, i + 1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) 
{
    vector<vector<int>> ans;
    vector<int> temp;
    rec(n, k, 1, temp, ans);
    return ans;
}

vector<vector<int>> combine_v1(int, int);

int main()
{
    auto ans = combine(100, 5);
    auto ans2 = combine_v1(100, 3);

    return 0;
}

//Pass
vector<vector<int>> combine_recursive(int curr_number, int n, int k)
{
    vector<vector<int>> ret;

    if (k == 2)
    {
        for (int i = curr_number; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ret.push_back({ i, j });
            }
        }
    }
    else
    {
        ret = combine_recursive(curr_number + 1, n, k - 1);
        for (auto& element : ret)
        {
            element.insert(element.begin(), curr_number);
        }
        if ((curr_number + 1) + k - 1 <= n)
        {
            auto sub_ret = combine_recursive(curr_number + 1, n, k);
            ret.insert(ret.end(), sub_ret.begin(), sub_ret.end());
        }
    }
    return ret;
}

vector<vector<int>> combine_v1(int n, int k)
{
    vector<vector<int>> ret;

    if (k == 1)
    {
        for (int i = 1; i <= n; ++i)
            ret.push_back({ i });
    }
    else
        return combine_recursive(1, n, k);
}



/*
//fail
vector<vector<int>> combine_recursive(int curr_number, int n, int k)
{
    vector<vector<int>> ret;

    if (k == 1)     //<- wrong here
    {
        while (curr_number <= n)
        {
            ret.push_back({ curr_number });
            ++curr_number;
        }
    }
    else
    {
        ret = combine_recursive(curr_number + 1, n, k - 1);
        for (auto& element : ret)
        {
            element.insert(element.begin(), curr_number);
        }
    }
    return ret;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;

    if (k == 1)
    {
        for (int i = 1; i <= n; ++i)
            ret.push_back({ i });
    }
    else
    {
        for (int i = 1; i <= n - k + 1; ++i)
        {
            auto sub_ret = combine_recursive(i, n, k);
            ret.insert(ret.end(), sub_ret.begin(), sub_ret.end());
        }
    }

    return ret;
}
*/