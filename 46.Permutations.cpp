#include <vector>
#include <algorithm>

using namespace std;

//Hint by https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/46_permutations__medium.html
//Non-DFS solution:???



//DFS solution:
void depth_first_search(vector<int>& nums, vector<int>& avalible_index, vector<vector<int>>& ret, vector<int>& element)
{
    if (element.size() == nums.size())
        ret.push_back(element);

    for (int i = 0; i < avalible_index.size(); ++i)
    {
        if (avalible_index[i] == 0)
            continue;
        avalible_index[i] = 0;
        element.push_back(nums[i]);
        depth_first_search(nums, avalible_index, ret, element);
        element.pop_back();
        avalible_index[i] = 1;
    }

}

vector<vector<int>> permute_dfs(vector<int>& nums) 
{
    vector<vector<int>> ret;
    vector<int> element;
    vector<int> avalible_index(nums.size(), 1);
    
    depth_first_search(nums, avalible_index, ret, element);

    return ret;
}

int main()
{
    vector<int> nums = {1};
    auto ans = permute_dfs(nums);

    return 0;
}