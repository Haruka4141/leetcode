#include <vector>

using namespace std;

//https://stackoverflow.com/questions/4773807/searching-in-a-sorted-and-rotated-array
int search_recursive(vector<int>& nums, int target, int left, int right)
{
    int mid = (left + right) / 2;

    if (left > right)
        return -1;

    if (nums[mid] == target)
        return mid;
    
    if (nums[left] <= nums[mid])     //left side is sorted (ascending)
    {
        if (nums[left] <= target && target < nums[mid])             //target is in right side
            return search_recursive(nums, target, left, mid - 1);
        else
            return search_recursive(nums, target, mid + 1, right);
    }
    else                            //right side is sorted  
    {
        if (nums[mid] < target && target <= nums[right])             //target is in right side
            return search_recursive(nums, target, mid + 1, right);
        else                                                        
            return search_recursive(nums, target, left, mid - 1);
    }

}

int search(vector<int>& nums, int target)
{
    if (nums.size() == 1)
        return target == nums[0] ? 1 : -1;
    if (nums.size() == 2)
        if (target == nums[0])  return 0;
        else if (target == nums[1]) return 1;
        else return -1;
    

    int left = 0;
    int right = nums.size() - 1;

    return search_recursive(nums, target, left, right);

}

int main()
{
    //vector<int> a = { 4,5,6,7,0,1,2 };
    vector<int> a = { 1, 2, 3 };
    int ans = search(a, 0);
    
    return 0;
}

int search_v1(vector<int>& nums, int target)       //fail, I think pivot = mid, but pivot is unkown actually
{
    if (nums.size() == 1 && target == nums[0])
        return 0;
    else if (nums.size() == 1)
        return -1;

    if (nums.size() == 2 && target == nums[0])
        return 0;
    else if (nums.size() == 2 && target == nums[1])
        return 1;
    else if (nums.size() == 2)
        return -1;

    int right = nums.size() - 1;        //caution: Possibly rotated!
    int left = 0;
    int mid = (left + right) / 2;

    if (nums[left] > nums[right])      //rotated
    {
        right = nums.size() / 2;
        left = right + 1;
        mid = 0;
        if (nums[right] == target)
            return right;

        if (target > nums[mid])
        {
            left = mid;
            mid = (left + right) / 2;
        }
        else if (target < nums[mid])
        {
            right = mid;
            mid = (left + nums.size()) / 2;
        }
        else
            return 0;
    }

    while (left < mid)
    {
        if (target >= nums[mid])
        {
            left = mid;
        }
        else if (target < nums[mid])
        {
            right = mid;
        }

        if (left > right)
            mid = (left + nums.size()) / 2;
        else
            mid = (left + right) / 2;
    }

    if (target == nums[left])
        return left;
    else if (target == nums[right])
        return right;
    else
        return -1;
}