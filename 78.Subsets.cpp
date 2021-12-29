#include <vector>

using namespace std;

/*
e.g. {1,2,3}
All subsets(i):     1 << j -> 0001 ~ 0100
    0000
    0001
    0010
    0011 
    0100
    0101
    0110
    0111
*/

vector<vector<int>> subsets(vector<int>& nums)  //submission, omg
{
    vector<vector<int>>all_subset;

    int n = nums.size();
    int st_ct = (1 << n);   //total number of subsets

    for (int i = 0; i < st_ct; i++) 
    {
        vector<int>temp;
        for (int j = 0; j < n; j++) 
        {
            if (i & (1 << j))
                temp.push_back(nums[j]);
        }
        all_subset.push_back(temp);
    }
    return all_subset;
}

//Pass
void subsets_recursive(vector<vector<int>>& ret, vector<int>& nums, vector<int>& temp, int curr_index, int k)
{
    if (temp.size() == k)
    {
        ret.push_back(temp);
        return;
    }
    else
    {
        for (int i = curr_index; i < nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            subsets_recursive(ret, nums, temp, i + 1, k);
            temp.pop_back();
        }
    }
}

vector<vector<int>> subsets_v1(vector<int>& nums) 
{
    vector<vector<int>> ret;
    vector<int> temp;
    for (int k = 0; k <= nums.size(); ++k)
        subsets_recursive(ret, nums, temp, 0, k);

    return ret;
}

int main()
{
    vector<int> nums = {1,2,3};
    auto ans = subsets(nums);

    return 0;
}