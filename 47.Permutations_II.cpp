#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<bool>& avaliable_index, vector<int>& element)
{
    if (element.size() == nums.size() /*&& find(ret.begin(), ret.end(), element) == ret.end()*/)    //pass but slow
    {
        ret.push_back(element);
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!avaliable_index[i])
            continue;

        while (i + 1 < nums.size() && avaliable_index[i + 1] && nums[i + 1] == nums[i])
            ++i;

        avaliable_index[i] = false;
        element.push_back(nums[i]);
        dfs(nums, ret, avaliable_index, element);
        avaliable_index[i] = true;
        element.pop_back();
    }

}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> ret;
    vector<bool> avaliable_index(nums.size(), true);        //use bool to reduce space
    vector<int> element;
    sort(nums.begin(), nums.end());
    dfs(nums, ret, avaliable_index, element);

    return ret;
}

int main()
{
    vector<int> nums = { 1,1,2 };
    auto ans = permuteUnique(nums);


    return 0;
}
