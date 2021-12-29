#include <vector>

using namespace std;

//Problem: You can assume that you can always reach the last index.
//https://dev.to/seanpgallivan/solution-jump-game-ii-cn3#idea
int jump(vector<int>& nums) 
{
    int curr_max_index = -1;
    int next_max_index = 0;     //farest reachable index
    int jump_count = 0;

    for (int i = 0; next_max_index < nums.size() - 1; ++i)
    {
        if (i > curr_max_index)                                        
        {
            ++jump_count;
            curr_max_index = next_max_index;               //there will be a jump in curr_max_index, ++count and set curr_max_index to farest reachable index 
        }

        next_max_index = max(next_max_index, nums[i] + i); //search in current_max_index, if larger, refresh reachable farest index                            
    }
    return jump_count;
}

/*
        0   1   2   3   4   5   6   7   8
        5   6   4   4   6   9   4   4   7
     c  n              
i=0     c------------------>n            count = 1
i=1     --->o---------------c------>n    count = 2, c represent current max jump length, n is refreshed to farest reachable index.
i=2                         c       n               i < max jump length, count remain same
i=3                         c       n
i=4     --------------->o---c------------>10   
i=5                                      found


        0   1   2   3   4   5   6   7   8
        5   6   1   1   1   1   1   4   7
     c  n
i=0     c------------------>n            count = 1
i=1     --->o---------------c------>n    count = 2, c represent current max jump length, n is refreshed to farest reachable index.
i=2                         c       n               i < max jump length, count remain same
i=3                         c       n
i=4                         c       n
i=5                         c       n
i=6     --->o---------------------->c------>11      count = 3, search next max jump length
i=7                                        found

*/

int main()
{

    //vector<int> nums = { 2,3,1,1,4 };
    vector<int> nums = { 5,6,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,6,9,4,4,7,/*4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5*/ };
    auto ans = jump(nums);

    return 0;
}

void helper(vector<int>& nums, int& minium_jump, int num_jump, int curr_index)  //time limit
{
    if (curr_index >= nums.size() - 1)
    {
        if (num_jump < minium_jump)
            minium_jump = num_jump;
        return;
    }

    if (num_jump >= minium_jump)
        return;


    for (int possible_len = nums[curr_index]; possible_len > 0; --possible_len)
    {
        helper(nums, minium_jump, num_jump + 1, curr_index + possible_len);
    }


}

int jump_v1(vector<int>& nums)
{
    int minium_jump = nums.size() - 1;
    helper(nums, minium_jump, 0, 0);

    return minium_jump;
}
