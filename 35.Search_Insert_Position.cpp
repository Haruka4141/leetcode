#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)     //O(log2 n) binary search, if N = 16, the program will end after 4 loops
{
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    
    while (left != mid)
    {
        if (target > nums[mid])
        {
            left = mid;
            mid = (left + right) / 2;
        }
        else
        {
            right = mid;
            mid = (left + right) / 2;
        }
    }
    if (target > nums[right])
        return right + 1;
    if(target > nums[left])
        return right;
    return left;
}


int main()
{
    vector<int> a = { 1,3,5,6 };
    int ans = searchInsert(a, 7);
   
    return 0;
}

int searchInsert_linear(vector<int>& nums, int target)     //O(n) linear search
{
    if (target <= nums[0])
        return 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i - 1] <= target && target <= nums[i])
            return i;
    }
    return nums.size();
}