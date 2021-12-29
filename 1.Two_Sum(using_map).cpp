#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


//https://leetcode.com/problems/two-sum/discuss/1236732/C%2B%2B-oror-O(n)-time-oror-Explained-line-by-line-with-example
vector<int> twoSum(vector<int>& nums, int target)
{    //(key value) v    v(map value), unordered_set only has key value, which is also element value
    unordered_map<int, int> mark;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (mark.find(target - nums[i]) != mark.end())      //find(): if the value is not present in the map, it returns an iterator to the end of map
            return {mark[target - nums[i]], i};             //type vector<int>

        mark[nums[i]] = i;  //store the nums index with the key which is num value
    }
    return{};   //return an object of the function's return type initialized with an empty list-initializer
}



int main()
{
    vector<int> nums = {3,2,4};

    auto ans = twoSum(nums, 6);
    // cout << "[ ";
    // for (vector<int>::iterator curr = ans.begin(); curr != ans.end(); ++curr)
    //     cout << *curr << " ";
    // cout << "]\n";

    return 0;

}