#include <vector>
#include <unordered_map>

using namespace std;

//https://stackoverflow.com/questions/68006440/find-first-and-last-position-of-element-in-sorted-array
vector<int> searchRange(vector<int>& nums, int target) 
{
    if (nums.size() == 1 && target == nums[0])
        return { 0, 0 };

    unordered_map<int, int> value_index;
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left < right)
    {
        mid = (left + right) / 2;

        value_index.insert({ nums[left], left });
        value_index.insert({ nums[mid], mid });
        value_index.insert({ nums[right], right });

        if (target > nums[mid])
            left = mid + 1;
        else if ((target < nums[mid]))
            right = mid - 1;
        else
            break;
    }

    auto iter = value_index.find(target);
    if (iter != value_index.end())
    {
        int start = iter->second;
        int end = iter->second;

        while (start > 0 && nums[start - 1] == nums[start])
            --start;
        while (end < nums.size() - 1 && nums[end + 1] == nums[end])
            ++end;

        return { start, end };
    }
    else
        return { -1, -1 };

}


int main()
{
    //vector<int> a = { 5,7,7,8,8,10 };
    vector<int> a = { 1, 4 };
    auto ans = searchRange(a, 4);
        

    return 0;
}
 