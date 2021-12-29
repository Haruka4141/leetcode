#include <vector>

using namespace std;

void binary_search_recursive(vector<int>& nums, int target, int left, int right, bool& found)
{
    if (left > right)
        return;

    while (left < right && nums[left] == nums[left + 1])
        ++left;
    while (right > left && nums[right] == nums[right - 1])
        --right;

    int mid = (left + right) / 2;
    if (nums[mid] == target)
    {
        found = true;
        return;
    }

    if (nums[left] <= nums[mid])
    {
        if (nums[left] <= target && target < nums[mid])
            binary_search_recursive(nums, target, left, mid - 1, found);
        else
            binary_search_recursive(nums, target, mid + 1, right, found);
    }
    else
    {
        if (nums[mid] < target && target <= nums[right])
            binary_search_recursive(nums, target, mid + 1, right, found);
        else
            binary_search_recursive(nums, target, left, mid - 1, found);
    }
}

bool search(vector<int>& nums, int target) 
{   
    if (nums.size() == 1)
        return target == nums[0] ? true : false;
    if (nums.size() == 2)
        if (target == nums[0])  return true;
        else if (target == nums[1]) return true;
        else return false;


    int left = 0;
    int right = nums.size() - 1;
    bool ret = false;
    binary_search_recursive(nums, target, left, right, ret);

    return ret;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    //vector<int> nums = { 2, 5, 6, 0, 0, 1, 2 };
    auto ans = search(nums, 0);

    return 0;
}