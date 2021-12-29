#include <vector>
#include <algorithm>

using namespace std;

//memory comsumption is more than v2. 0s runtime
void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int pos)    //submisson
{
    if (pos == nums.size())     //take position as depth, not size
    {
        ans.push_back(cur);
        return;
    }

    if (cur.empty() || nums[pos] != cur.back())
    {
        dfs(ans, cur, nums, pos + 1);       //a
    }

    cur.push_back(nums[pos]);
    dfs(ans, cur, nums, pos + 1);           //b
    cur.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> cur;
    dfs(ans, cur, nums, 0);
    return ans;
}

/*
    1  2  2
1:  a  a  a  -> {}
2:        b  -> {2}
3:     b  b  -> {2, 2}
4:  b  a  a  -> {1}
5:        b  -> {1, 2}
6:     b  b  -> {1, 2, 2}

*/

int main()
{
    vector<int> nums = { 1,2,2 };
    auto ans = subsetsWithDup(nums);

    return 0;
}

//pass
void subsets_recursive(vector<int>& nums, vector<vector<int>>& ret, vector<int>& sub_set, int index, int n)
{
    if (sub_set.size() == n)
    {
        if (find(ret.begin(), ret.end(), sub_set) == ret.end())
            ret.push_back(sub_set);
        return;
    }
    for (int i = index; i < nums.size(); ++i)
    {
        sub_set.push_back(nums[i]);
        subsets_recursive(nums, ret, sub_set, i + 1, n);
        sub_set.pop_back();
    }
}

vector<vector<int>> subsetsWithDup_v2(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    vector<int> subset;
    for (int i = 0; i <= nums.size(); ++i)
    {
        subsets_recursive(nums, ret, subset, 0, i);
    }
    return ret;
}

vector<vector<int>> subsetsWithDup_v1(vector<int>& nums)    //fail. shift amount exceed 32
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    //unordered_set<vector<int>> unique_set;      //cannot generate hash

    int dup_size = 1 << nums.size();

    for (int i = 0; i < dup_size; ++i)
    {
        vector<int> element;
        for (int j = 0; j < dup_size; ++j)
        {
            if (i & (1 << j))
                element.push_back(nums[j]);
        }
        if (find(ret.begin(), ret.end(), element) == ret.end())
            ret.push_back(element);
    }

    return ret;
}