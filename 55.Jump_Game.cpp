#include <vector>

using namespace std;

bool canJump(vector<int>& nums)
{
    int next = 0;

    for (int i = 0; i < nums.size() && i <= next; ++i)
        next = max(next, i + nums[i]);
    if (next >= nums.size() - 1)
        return true;
    else
        return false;
}


int main()
{
    vector<int> nums = { 2,3,1,1,4,1 };
    //vector<int> nums = { 3,2,1,0,4 };
    auto ans = canJump(nums);


    return 0;
}