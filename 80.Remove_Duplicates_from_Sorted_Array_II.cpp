#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    int same_element_count = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == nums[i - 1] && same_element_count < 2)
        {
            ++same_element_count;
        }
        else if (nums[i] == nums[i - 1] && same_element_count >= 2)
        {
            nums.erase(nums.begin() + i);
            --i;
        }
        else
            same_element_count = 1;
    }

    return nums.size();
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    auto ans = removeDuplicates(nums);

    return 0;
}